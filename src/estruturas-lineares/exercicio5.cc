#include <FilaDeque.hh>
#include <PilhaDeque.hh>
using exercicio::FilaDeque;
using exercicio::PilhaDeque;

// ============ Exercício 5 ============
// Exercício 5.a
template<typename T>
void inverterFilaComPilha(FilaDeque<T> *p) {
    PilhaDeque<T> f = PilhaDeque<T>();
    while(p->size()) {
        f.push(p->pop());
    }
    while(f.size()) {
        p->push(f.pop());
    }
}
// exercício 5.b
template<typename T>
void inverterFilaCom2Filas(FilaDeque<T> *p) {
    FilaDeque<T> p1;
    FilaDeque<T> p2;
    
    // invertida na fila original em uma auxiliar
    while(p->size()) {
        p1.push(p->pop());
    }
    // inverte a fila já invertida em um segundo auxiliar, obtendo a fila original
    while(p1.size()) {
        p2.push(p1.pop());
    }
    // inverte a fila na ordem na fila original, invertendo assim o sentido da fila
    while(p2.size()) {
        p->push(p2.pop());
    }
}