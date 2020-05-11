#ifndef PLAYER1_H
#define PLAYER1_H

#include "../header/tabuleiro.h"
#include "../header/jogo.h"

template < typename tipo_int >
class player1{
public:
   void player1_joga(tabuleiro &T1, tipo_int i);
   void player1_joga_SEM_COR_REPETIDA(tabuleiro &T1, tipo_int i);
   ~player1();
};

#endif
