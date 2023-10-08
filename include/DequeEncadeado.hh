// Exercício de Estruturas de dados
// codigo de presença 0071A

#pragma once
#include <iostream>
namespace exercicio {
template <typename T>
struct Elemento {
 public:
  T value;
  Elemento<T>* next;

  explicit Elemento<T>(T value, Elemento<T>* next = 0)
      : value(value), next(next) {}
};

// ============ Exercícios 1 =================
// 1.a
template <typename T>
struct DequeEncadeado {
  Elemento<T>* head;
  Elemento<T>* last;
  int _size;

  T inicio() { return head->value; }

  T fim() { return last->value; }

  int size() { return _size; }

  bool insereInicio(T value) {
    // aumenta o tamanho da lista ao inserir um elemento
    _size++;
    // O elemento inserido deve apontar para o próximo elemento da lista
    Elemento<T>* inserir = new Elemento<T>(value, head);
    // O elemento inicial deve ser tanto o primeiro como o último da lista
    if (!head) {
      head = inserir;
      last = inserir;
      return true;
    }
    // salva o elemento inicial atual como o primeiro da lista
    head = inserir;
    return true;
  }

  bool insereFim(T value) {
    _size++;
    Elemento<T>* inserir = new Elemento<T>(value);
    if (!head) {
      head = inserir;
      last = inserir;
      return true;
    }
    // O elemento inserido deve ser apontado pelo último da lista
    last->next = inserir;
    // e então salvo como o último da lista
    last = inserir;
    return true;
  }

  T removeInicio() {
    _size--;
    // salva o valor do primeiro elemnto da lista como o elemento a ser
    // retornado
    T ret = head->value;
    T* toRemove = head;
    // o elemento seguinte se torna o inicial primeiro da lista
    head = head->next;
    // no caso de uma lista vazia, anula o último elemnto
    if (_size == 0) {
      last = 0;
    }
    // deleta o ponteiro pra evitar vazamentos de memória
    delete toRemove;
    return ret;
  }

  T removeFim() {
    // análogo à classe anterior
    _size--;
    T ret = last->value;
    T* toRemove = last;
    last = last->next;
    if (_size == 0) {
      head = 0;
    }
    delete toRemove;
    return ret;
  }

  DequeEncadeado() : _size(0) {
    this->head = nullptr;
    this->last = nullptr;
  }

  DequeEncadeado(DequeEncadeado& d) : _size(0) {
    Elemento<T>* atual = d.head;
    while (atual) {
      insereFim(atual->value);
      atual = atual->next;
    }
  }

  ~DequeEncadeado() {
    // deleta todos os elementos da lista na destrução do objeto
    // evitando assim vazamentos de memória
    while (head) {
      removeInicio();
    }
  }
};
}  // namespace exercicio