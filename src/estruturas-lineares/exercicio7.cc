#include <__utility/integer_sequence.h>
#include <_ctype.h>
#include <cmath>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <map>
using std::string;
using std::stack;

enum Operador {
    SOMA = '+',
    SUBTRACAO = '-',
    MULTIPLICACAO = '*',
    DIVISAO = '/',
    POTENCIA = '^',
    ABRE_PARENTESES = '(',
    FECHA_PARENTESES = ')',
    DESCONHECIDO = '0'
};

int precedencia(Operador op){
    switch (op)
    {
        case ABRE_PARENTESES:{
            return 0;
        } case FECHA_PARENTESES:{
            return 0;
        } case SOMA:{
            return 1;
        } case SUBTRACAO:{
            return 1;
        } case MULTIPLICACAO:{
            return 2;
        } case DIVISAO:{
            return 2;
        } case POTENCIA:{
            return 3;
        } default:{
            return -1;
        }
    }
}

bool eOperador(string s){
    return (
        s == "+" ||
        s == "-" ||
        s == "*" ||
        s == "/" ||
        s == "^"
    );
}

bool eParentese(string s){
    return (
        s == "(" ||
        s == ")"
    );
}

Operador emOperador(char s){
    switch(s) {
        case '+':{
            return Operador::SOMA;
        } case '-':{
            return Operador::SUBTRACAO;
        } case '*':{
            return MULTIPLICACAO;
        } case '/':{
            return DIVISAO;
        } case '^':{
            return POTENCIA;
        } case '(':{
            return ABRE_PARENTESES;
        } case ')':{
            return FECHA_PARENTESES;
        } default:{
            return DESCONHECIDO;
        }
    }
}

string acharProximaEntrada(string &entrada){
    int pos = entrada.find(' ');
    string saida = entrada.substr(0, pos);
    entrada = entrada.substr(pos+1, string::npos);
    return saida;
}

string tratarOperador(Operador opAtual, stack<Operador> &operadores){
    string saida;
    while(
        (operadores.size() > 0 && operadores.top() != Operador::ABRE_PARENTESES)
        && precedencia(operadores.top()) >= precedencia(opAtual)
    ){
        auto char_operador = operadores.top();
        saida += char_operador;
        saida += ' ';
    }
    operadores.push(opAtual);
    return saida;
}

string tratarParentese(Operador parenteseAtual, stack<Operador> &operadores){
    string saida;
    if (parenteseAtual == Operador::ABRE_PARENTESES){
        operadores.push(Operador::ABRE_PARENTESES);
    } else {
        while(operadores.top() != Operador::ABRE_PARENTESES){
            if (operadores.size() == 0){
                throw std::invalid_argument("Parenteses desbalanceados");
            }
            auto char_operador = operadores.top();
            saida += char_operador;
            saida += ' ';
            operadores.pop();
        }
        if(operadores.top() != Operador::ABRE_PARENTESES){
            throw std::invalid_argument("Parenteses desbalanceados");
        }
        operadores.pop();
    }
    return saida;
}

string printOperadores(stack<Operador> op){
    string ops;
    while (op.size()) {
        ops += op.top();
        op.pop();
        ops += ' ';
    }
    return ops;
}

string transformarEntradaEmNotacaoPolonesa(string entrada) {
    entrada += ' ';
    string saida;
    string stringAtual = acharProximaEntrada(entrada);
    std::stack<Operador> operadores;
    while(stringAtual.length() > 0){
        std::cout
            << "string atual: '" << stringAtual << "'\t"
            << "saida: '" << saida << "'\t"
            << "operadores: '" << printOperadores(operadores) << "'\n";
        if (eOperador(stringAtual)){
            saida += tratarOperador(emOperador(stringAtual[0]), operadores);
        }
        else if (eParentese(stringAtual)) {
            saida += tratarParentese(emOperador(stringAtual[0]), operadores);
        }
        else {
            saida += stringAtual;
            saida += ' ';
        }
        stringAtual = acharProximaEntrada(entrada);
    }
    while(operadores.size() > 0){
        auto char_operador = operadores.top();
        saida += char_operador;
        saida += ' ';
        operadores.pop();
    }
    return saida;
}

int main(void) {
    string entrada = "( 1 + 2 ) * ( 3 + 4 * 5 )";
    std::cout
        << "rodando exemplo " << entrada << ":\n"
        << transformarEntradaEmNotacaoPolonesa(entrada) << std::endl;
    return 0;
}