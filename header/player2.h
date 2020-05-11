#ifndef PLAYER2_H
#define PLAYER2_H

#include "../header/tabuleiro.h"

template < typename tipo_int >
class player2{
public:
  tipo_int player2_joga(tabuleiro &T1, tipo_int  i);
  ~player2();
};

#endif
