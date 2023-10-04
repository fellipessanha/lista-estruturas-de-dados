#include <FilaDeque.hh>
#include <PilhaDeque.hh>
using exercicio::FilaDeque;
using exercicio::PilhaDeque;

// ============ Exercício 4 ============
// 4.a
template<typename T>
void inverterPilhaComFila(PilhaDeque<T> *p) {
    FilaDeque<T> f = FilaDeque<T>();
    while(p->size()) {
        f.push(p->pop());
    }
    while(f.size()) {
        p->push(f.pop());
    }
}
// 4.b
template<typename T>
void inverterCom2Pilhas(PilhaDeque<T> *p) {
    PilhaDeque<T> p1;
    PilhaDeque<T> p2;
    
    // invertida na pilha original em uma auxiliar
    while(p->size()) {
        p1.push(p->pop());
    }
    // inverte a pilha já invertida em um segundo auxiliar, obtendo a pilha original
    while(p1.size()) {
        p2.push(p1.pop());
    }
    // inverte a pilha na ordem na pilha original, invertendo assim o sentido da pilha
    while(p2.size()) {
        p->push(p2.pop());
    }
}

// 4.c
template<typename T>
void inverterElementos(PilhaDeque<T> *p, int p1, int p2){
    int first = p1 <= p2 ? p1 : p2;
    int last = p1 <= p2 ? p2 : p1;
    PilhaDeque<T> aux;
    
    // guarda o p1esimo elemento numa varíavel T: O(1)
    for(int i = 0; i < first; i++) {
        aux.push(p->pop());
    }
    T salvo1 = p->pop();

    // guarda o p2esimo elemento numa varíavel T: O(1)
    for(int i = first; i < last; i++) {
        aux.push(p->pop());
    }
    T salvo2 = p->pop();

    // insere o p1esimo elemento na posição p2
    p->push(salvo1);

    // insere os elementos entre p1 e p2
    while(aux.size() >= first) {
        p->push(aux.pop());
    }

    // insere o p2esimo elemento na posição p1
    p->push(salvo2);

    // insere os elementos restantes na pilha original
    while(aux.size()) {
        p->push(aux.pop());
    }
}
template<typename T>
void inverterCom1Pilha(PilhaDeque<T> *p) {
    // tomando n é como tamanho da pilha, inverte os elementos i e n-i-1
    // faz o operação n/2 vezes, de 0 a n/2, invertendo assim a pilha
    for(int i = 0; i < p->size()/2; i++) {
        inverterElementos(p, i, p->size() - 1 - i);
    }
}
