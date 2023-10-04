#include <PilhaDeque.hh>
using exercicio::PilhaDeque;

// ============ Exercício 3 ============
template<typename T>
class FilaDe2Pilhas{
public:
    PilhaDeque<T> acc;
    PilhaDeque<T> invertida;
    

    bool push(T inserir) {
        return acc.push(inserir);
    }

    T pop(){
        invertida = PilhaDeque<T> ();
        T ret;
        while(acc.size()) {
            invertida.push(acc.pop());
        }
        ret = invertida.pop();
        PilhaDeque<T> reserva = PilhaDeque<T>();
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