#include "FilaDeque.hh"
using exercicio::FilaDeque;

// ============ Exercício 2 ============
template<typename T>
class PilhaDe2Filas{
public:
    FilaDeque<T> acc;
    FilaDeque<T> invertida;
    

    bool push(T inserir) {
        return acc.push(inserir);
    }

    // o algoritmo pode ser otimizado com uma flag `last_pushed`
    // essa flag indicaria a necessidade de construir a pilha invertida
    // caso last_pushed seja verdadeiro, a pilha invertida seria construída do zero
    // caso contrário, a pilha invertida já estaria disponível, pois nenhum elemento foi adicionado
    T pop(){
        // zera a fila invertida
        invertida = FilaDeque<T> ();
        T ret = invertida.push();
        // insere elementos da fila
        while(acc.size()) {
            invertida.push(acc.pop());
        }

        // salva o elemento a ser retornado: o fim da fila/topo da pilha
        ret = invertida.top();
        // cria uma fila auxiliar, de modo a manter a invertida disponível para consulta de top
        FilaDeque<T> reserva = FilaDeque<T>();
        while(invertida.size()) {
            reserva.push(invertida.pop());
        }

        acc = reserva;
        return ret;
    }
    
    int size() {
        return acc.size();
    }

    T top() {
        invertida.top();
    }
};
