//#include "../header/tabuleiro.h"
#include "../header/player1.h"
#include "../header/player2.h"
//#include "player1.cpp"
//#include "player2.cpp"
/* ------------------------------------------------------------------------- */
int main(void){
  srand(time(NULL));
  iniciar_jogo();
  jogo game;
/* --------------------- Player Vs. Player -------------------------------- */
  if(game.get_tipo()==1){
    player1<int> Jog1;
    player2<int> Jog2;
    tabuleiro T1(game);
    int i=0;
    int fim_de_jogo;
    // Logica do Player Vs. Player
    for(i=0;i<game.get_palpites();i++){
      if(game.get_corRep()==true){
        Jog1.player1_joga(T1,i);
        fim_de_jogo = Jog2.player2_joga(T1,i);
        if(fim_de_jogo == 1)
          return 0;
      }else{
        Jog1.player1_joga_SEM_COR_REPETIDA(T1,i);
        fim_de_jogo= Jog2.player2_joga(T1,i);
        if(fim_de_jogo==1)
          return 0;
      }
    }
  }
/* ---------------------- Player Vs. PC ------------------------------------ */
  else{
    game.set_nivel();
    // Criação do tabuleiro
    tabuleiro T(game);
    // gerar a senha
    if(game.get_corRep()==true){
        T.cria_senha_com_repetidos(game.get_Ncores());
    }else{
        T.cria_senha_sem_repetidos(game.get_Ncores());
    }

    // avisar para o usuario como ficou as definições do tabuleiro
    game.mapa_de_jogo();
    cout << " --------------------------------------------- \n";
    cout << " -> Essas são suas configurações de tabuleiro,";
    cout << " para continuar, digite qualquer coisa\n\n" << ":";
    string a;
    cin >> a;
    system("clear");
    int i=0;
    int fim_de_jogo;
    player1<int> Jog1;
    // ------------ Player Vs. PC  ( Cor repete ) ---------
    for(i=0;i<game.get_palpites();i++){
      if(game.get_corRep()==true){
        Jog1.player1_joga(T,i);
        fim_de_jogo = T.resposta_do_PC(i);
        if(fim_de_jogo==1)return 0;
      }
      // ------------ Player Vs. PC  ( Cor não repete ) ---------
      else{
        Jog1.player1_joga_SEM_COR_REPETIDA(T,i);
        fim_de_jogo=T.resposta_do_PC(i);
        if(fim_de_jogo==1)return 0;
      }
    }
  }
  cout <<"______________________________________________________________________________"<<endl;
  cout <<"                    COMPUTADOR VENCEU !!! \n";
  cout <<"______________________________________________________________________________"<<endl;
  return 0;
}
