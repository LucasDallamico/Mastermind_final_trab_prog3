#ifndef FUNCOES_H
#define FUNCOES_H
/* ------------------------------------------------------------------------ */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
/* --------------------------- -INTERFACE --------------------------------- */
void iniciar_jogo(void);
void niveis_menu(void);
/* ---------------------- FUNCOES PARA GERAR SEQUENCIA -------------------- */
int * sequencia_aleatoria_com_repeticao(int intervalo);
int * sequencia_aleatoria_sem_repeticao (int intervalo);
/* ------------------------------------------------------------------------ */

#endif
