// Exercício de Estruturas de dados
// codigo de presença 0071A

#include <DequeEncadeado.hh>
#include <FilaDeque.hh>
#include <PilhaDeque.hh>
#include <iostream>

template <typename T>
struct Elemento {
 public:
  T value;
  Elemento<T>* next;

  explicit Elemento<T>(T value, Elemento<T>* next = 0)
      : value(value), next(next) {}
};

// ============ Exercício 1 =================

// 1.a
void letraA() {
  static_assert(requires(exercicio::DequeEncadeado<char> a, char t) {
    // requer operação de consulta ao elemento 'inicio'
    { a.inicio() };
    // requer operação de consulta ao elemento 'fim'
    { a.fim() };
    // requer operação 'insereInicio' sobre tipo 't'
    { a.insereInicio(t) };
    // requer operação 'insereFim' sobre tipo 't'
    { a.insereFim(t) };
    // requer operação 'removeInicio' e retorna tipo 't'
    { a.removeInicio() };
    // requer operação 'removeFim' e retorna tipo 't'
    { a.removeFim() };
  });
}

// 1.b
void letraB() {
  static_assert(requires(exercicio::PilhaDeque<char> a, char t) {
    // requer a operação de empilhamento 'push'
    { a.push(t) };
    // requer método de desempilhar 'pop'
    { a.pop() };
    // requer operação de consulta ao elemento do topo 'top'
    { a.top() };
  });
}

// 1.c
void letraC() {
  static_assert(requires(exercicio::FilaDeque<char> a, char t) {
    // requer a operação de enfileiramento 'push'
    { a.push(t) };
    // requer método de desenfireilar 'pop'
    { a.pop() };
    // requer operação de consulta ao elemento do topo 'top'
    { a.top() };
  });
}
