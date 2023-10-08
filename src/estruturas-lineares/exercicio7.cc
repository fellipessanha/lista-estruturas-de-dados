#include <__utility/integer_sequence.h>
#include <_ctype.h>

#include <cmath>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>
using std::stack;
using std::string;

// algoritmo de shunting-yard, feito baseado no pseudocódigo da wikipedia

constexpr bool DEBUG = false;

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

int precedencia(Operador op) {
  switch (op) {
    case ABRE_PARENTESES: {
      return 0;
    }
    case FECHA_PARENTESES: {
      return 0;
    }
    case SOMA: {
      return 1;
    }
    case SUBTRACAO: {
      return 1;
    }
    case MULTIPLICACAO: {
      return 2;
    }
    case DIVISAO: {
      return 2;
    }
    case POTENCIA: {
      return 3;
    }
    default: {
      return -1;
    }
  }
}

bool eOperador(string s) {
  return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
}

bool eParentese(string s) { return (s == "(" || s == ")"); }

Operador emOperador(char s) {
  switch (s) {
    case '+': {
      return Operador::SOMA;
    }
    case '-': {
      return Operador::SUBTRACAO;
    }
    case '*': {
      return MULTIPLICACAO;
    }
    case '/': {
      return DIVISAO;
    }
    case '^': {
      return POTENCIA;
    }
    case '(': {
      return ABRE_PARENTESES;
    }
    case ')': {
      return FECHA_PARENTESES;
    }
    default: {
      return DESCONHECIDO;
    }
  }
}

string acharProximaEntrada(string& entrada) {
  // fiz a leitura de entradas baseada no espaço por preguiça
  // dá pra fazer um parser melhor facilmente por conta da modularização do
  // código o caminho seria parsear por caractere e parar qdo for uma operação
  int pos = entrada.find(' ');
  string saida = entrada.substr(0, pos);
  entrada = entrada.substr(pos + 1, string::npos);
  return saida;
}

string tratarOperador(Operador opAtual, stack<Operador>& operadores) {
  string saida;
  // desempilha todas as operações _do parentese atual_ com maior prioridade
  while ((operadores.size() > 0 &&
          operadores.top() != Operador::ABRE_PARENTESES) &&
         precedencia(operadores.top()) >= precedencia(opAtual)) {
    auto char_operador = operadores.top();
    saida += char_operador;
    saida += ' ';
  }
  // adiciona a operação atual na pilha de operações
  operadores.push(opAtual);
  return saida;
}

string tratarParentese(Operador parenteseAtual, stack<Operador>& operadores) {
  if (parenteseAtual == Operador::ABRE_PARENTESES) {
    operadores.push(Operador::ABRE_PARENTESES);
    return "";
  }
  string saida;

  // desempilha as operações _do parentese atual_
  // note que as operações menos prioritárias já foram desempilhadas
  while (operadores.top() != Operador::ABRE_PARENTESES) {
    if (operadores.size() == 0) {
      throw std::invalid_argument("Parenteses desbalanceados");
    }
    auto char_operador = operadores.top();
    saida += char_operador;
    saida += ' ';
    operadores.pop();
  }
  // exception handling
  if (operadores.top() != Operador::ABRE_PARENTESES) {
    throw std::invalid_argument("Parenteses desbalanceados");
  }
  operadores.pop();
  return saida;
}

string printOperadores(stack<Operador> op) {
  // debug básico
  string ops;
  while (op.size()) {
    ops += op.top();
    op.pop();
    ops += ' ';
  }
  return ops;
}

void debugPrint(bool debug, string stringAtual, string saida,
                stack<Operador> operadores) {
  if (!debug) return;
  std::cout << "string atual: '" << stringAtual << "'\t"
            << "saida: '" << saida << "'\t"
            << "operadores: '" << printOperadores(operadores) << "'\n";
}

string transformarEntradaEmNotacaoPolonesa(string entrada) {
  entrada += ' ';
  string saida;
  string stringAtual = acharProximaEntrada(entrada);
  std::stack<Operador> operadores;
  while (stringAtual.length() > 0) {
    debugPrint(DEBUG, stringAtual, saida, operadores);
    if (eOperador(stringAtual)) {
      saida += tratarOperador(emOperador(stringAtual[0]), operadores);
    } else if (eParentese(stringAtual)) {
      saida += tratarParentese(emOperador(stringAtual[0]), operadores);
    } else {
      saida += stringAtual;
      saida += ' ';
    }
    stringAtual = acharProximaEntrada(entrada);
  }
  while (operadores.size() > 0) {
    auto char_operador = operadores.top();
    saida += char_operador;
    saida += ' ';
    operadores.pop();
  }
  return saida;
}

int main(void) {
  string entrada = "( 1 + 2 ) * ( 3 + 4 * 5 )";
  std::cout << "rodando exemplo!\n"
               "em notação usual:\t"
            << entrada << ":\n"
            << "em notação polonesa:\t"
            << transformarEntradaEmNotacaoPolonesa(entrada) << std::endl;
  return 0;
}