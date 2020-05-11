#ifndef TABULEIRO_H
#define TABULEIRO_H
/* ------------------------------------------------------------------------ */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
/* ------------------------------------------------------------------------ */
#include "../header/bola.h"
#include "../header/jogo.h"
#include "../header/funcoes.h"
/* ------------------------------------------------------------------------ */
class tabuleiro : public jogo{
private:
  //int t_senha; // numero de colunas
  //int t_palpites; // numero de linhas
  string *colors; // string das cores disponive no tabuleiro para a partida
  string *senha_pc; // armazena a senha do PC tamanho [t_senha]
public:
  Bola v[10][10]; // matriz das senhas
  Bola resposta[10][10]; // matriz preto,branco,cinza PBC
   // construtor né
  tabuleiro(jogo &game);
   // imprime tabuleiro das senhas
  void imprime(void);
   //imprime o tabuleiro da pbc
  void imprime_resposta(void);
  // verifica se a cor passada do usuario é valida para o tipo de jogo ( sem repetição )
  int verifica_cor(string color);
  // verifica se o jogador 2 nao digitou entrada errada
  int verifica_cor_jogador2(string color);
  // seta matriz da senhas
  void set_posicao1(int p, string color, int linha);
   // seta matriz da pbc
  void set_posicao2(int p, string color, int linha);
  //imprime a linha da matriz de senhas
  void imprime_palpite(int l);
  // imprime a matriz pbc, retorna a quantidade de preto ( cor correta e sequencia correta)
  int imprime_palpite2(int l);
  // mostra as cores disponiveis para o player
  void mostrar_cores(void);
  // menu para o jogador obter informações pertinentes a tabuleiro
  void help(void);
  /* PC -> Organiza a saida da matriz PBC para ficar na ordem (preto,branco,cinza)
  exibe na tela a linha da vez na tela
  */
  void gera_resposta(int linha);
  // PC -> cria a senha do pc ( sem repetição )
  void cria_senha_sem_repetidos(int intervalo);
  // PC -> cria a senha do pc ( sem repetição )
  void cria_senha_com_repetidos(int intervalo);
  // PC -> verifica se o usuario acertou a senha
  int venceu(int linha); // simplificar
  // Mostra para o usuario e seta a pbc
  int resposta_do_PC(int i);
  ~tabuleiro();
  /* --- Implementação de polimorfismo na cara dura
    Funcoes para mostrar de uma maneira visualmente bonita para o usuario
  */
  virtual void mapa_de_jogo(void) override;
  void resultado_jogo_vencedor(void);
  void texto_jogador1(void);
  void texto_jogador2(int linha_atual);
};
/* ------------------------------------------------------------------------- */
#endif
