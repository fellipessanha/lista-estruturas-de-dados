#pragma once
#include "DequeEncadeado.hh"

namespace exercicio {

template <typename T>
class PilhaDeque {
 public:
  DequeEncadeado<T> d;

  bool push(T inserir) { return d.insereFim(inserir); }

  int size() { return d.size(); }

  T pop() { return d.removeFim(); }

  T top() { return d.costas(); }

  PilhaDeque() { this->d = DequeEncadeado<T>(); }
};
}  // namespace exercicio
