#pragma once
#include "DequeEncadeado.hh"

namespace exercicio {
template <typename T>
class FilaDeque {
 public:
  DequeEncadeado<T> d;

  bool push(T inserir) { return d.insereInicio(inserir); }

  T pop() { return d.removeFim(); }

  T top() { return d.frente(); }

  FilaDeque() { this->d = DequeEncadeado<T>(); }
};
}  // namespace exercicio
