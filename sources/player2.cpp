#include "../header/player2.h"
/* ------------------------------------------------------------------------- */
template < typename tipo_int >
tipo_int player2<tipo_int>::player2_joga(tabuleiro &T1, tipo_int  i){
  int k=0;
  int cont=0;
  string color="bacate";
  string entrada[T1.get_Tcodigo()];
  salto:
  T1.texto_jogador2(i);
  // pegar a resposta
  while(1){
    cout << ":";
    for ( k = 0; k < T1.get_Tcodigo(); k++){
      cin >> entrada[k];
      if (entrada[k] == "help"){
        T1.help();
        goto salto;
      }
    }
    // verificar na entrada se as cores são validas
    for ( k = 0; k < T1.get_Tcodigo(); k++){
      cont += T1.verifica_cor_jogador2(entrada[k]);
     }
     if (cont == T1.get_Tcodigo())
      break;
     else{
       cout << endl;
       cout << " - Cores inválidas ou sequência repetida para esse modo de jogo\n";
       cout << " Insira novamente a sequência de cores [MAISCULO]: \n";
       cont = 0;
     }
  }

  for ( k = 0; k < T1.get_Tcodigo(); k++){
    T1.set_posicao2(k+1,entrada[k],i);
  }

  // verificar se o jogador ganhou antes
  if(T1.imprime_palpite2(i)==1){
    T1.resultado_jogo_vencedor();
    return 1;
  } else {
    // o contrario continuar
    T1.mapa_de_jogo();
    return 0;
  }
}
/* ------------------------------------------------------------------------- */
template < typename tipo_int>
player2<tipo_int>::~player2(){}
/* ------------------------------------------------------------------------- */
template class player2<int>;
