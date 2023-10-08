#include <PilhaDeque.hh>
using exercicio::PilhaDeque;

// ============ Exercício 6 ============
template <typename T>
class PilhaMin {
 public:
  PilhaDeque<T> p;
  PilhaDeque<T> mins;

  int topo() { return p.top(); }

  void empilha(int v) {
    p.push(v);

    // ao empilhar, checa se o valor é menor ou igual ao do topo da pilha de
    // mínimos em caso afirmativo, empilha o valor na pilha de mínimos checar é
    // O(1), empilhar é O(1) -> a operação é O(1)
    if (mins.size() == 0 || v <= mins.top()) {
      mins.push(v);
    }
  };
  int desempilha() {
    T removed = p.pop();

    // ao desempilhar, checa se o valor é igual ao do topo da pilha de mínimos
    // em caso afirmativo, desempilha o valor na pilha de mínimos
    // checar é O(1), desempilhar é O(1) -> a operação é O(1)
    if (removed == mins.top()) {
      mins.pop();
    }
    return removed;
  }

  int obterMinimo() {
    // consultar o valor no topo de uma pilha: O(1)
    return mins.top();
  }
};