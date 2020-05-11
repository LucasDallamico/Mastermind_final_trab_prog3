#include "../header/player1.h"
/* ------------------------------------------------------------------------- */
template < typename tipo_int>
void player1<tipo_int>::player1_joga_SEM_COR_REPETIDA(tabuleiro &T1, tipo_int i){
  int cont=0;
  int k = 0, h = 0;
  string color="bacate"; // corrigr
  string entrada[T1.get_Tcodigo()];
  // fazer novo padrao de entrada, para ser mais rapido
  salto:
  T1.texto_jogador1();
  while(1){
      cout << ":";
     for ( k = 0; k < T1.get_Tcodigo(); k++){
       cin >> entrada[k];
       if (entrada[k] == "help"){
         T1.help();
         goto salto;
       }
  	 }
     // verificcar se a cor é repetida
     for ( k = 0; k < T1.get_Tcodigo(); k++){
       if (T1.verifica_cor(entrada[k]) == 0)
        cont = -1;
       for ( h = 0; h < T1.get_Tcodigo(); h++){
         if (entrada[k] == entrada[h] && k != h)
          cont = -1;
       }
     }
     if (cont == 0)
      break;
     else{
       cout << endl;
       cout << " - Cores inválidas ou sequência repetida para esse modo de jogo\n";
       cout << " Insira novamente a sequência de cores [MAISCULO]: \n";
       cont = 0;
     }
  }
  // gravando na matriz
  for ( k = 0; k < T1.get_Tcodigo(); k++){
    T1.set_posicao1(k+1,entrada[k],i);
  }
  cout << endl << endl;
  cout <<"------------------------------------------------------------------------------"<<endl;
}
/* ------------------------------------------------------------------------- */
template < typename tipo_int >
void player1<tipo_int>::player1_joga(tabuleiro &T1, tipo_int i){
  int cont=0;
  string color="bacate";
  string entrada[T1.get_Tcodigo()];
  int k = 0;
  // fazer novo padrao de entrada, para ser mais rapido
  salto:
  T1.texto_jogador1();
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
       if (T1.verifica_cor(entrada[k]) == 1){
         cont++;
       }
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
    T1.set_posicao1(k+1,entrada[k],i);
  }
  cout << endl << endl;
  cout <<"------------------------------------------------------------------------------"<<endl;
}
/* ------------------------------------------------------------------------- */
template < typename tipo_int>
player1<tipo_int>::~player1(){}
/* ------------------------------------------------------------------------- */
template class player1<int>;
