#include "../header/funcoes.h"
/* ------------------------------------------------------------------------- */
void iniciar_jogo(void){
  system("clear");
  cout << " -------------------------------------------------------------- \n";
  cout << "                         MASTERMIND\n";
  cout << " -------------------------------------------------------------- \n";
  cout << " Desenvolvido por L. Dallamico e M. Morais\n";
  cout << " - Adoraria que tivesse easter egg\n  ";
  cout << "_______________________________________________________________ \n";
  cout << endl;
}
/* ------------------------------------------------------------------------- */
void niveis_menu(void){
  cout << " -------------------------------------------------------------- \n";
  cout<<" Selecione o nível de dificuldade"<<endl;
  cout<<"   1-Fácil"<<endl;
  cout<<"   2-Médio"<<endl;
  cout<<"   3-Difíl"<<endl;
  cout<<"   4-Extreme"<<endl;
  cout<<"   5-Deus"<<endl;
  cout<<" -> Aviso: os niveis vão altear as predefinições iniciais, se " <<
                    "deseja manter os mesmos digite [-1]\n";
  cout << " -------------------------------------------------------------- \n";
  cout << ":";
}
/* ------------------------------------------------------------------------- */
int * sequencia_aleatoria_com_repeticao(int intervalo){
    int * vet = new int[intervalo];
    int i;
    for( i = 0; i < intervalo; i++){
        vet[i] = (rand()%intervalo);
    }
    return vet;
}
/* ------------------------------------------------------------------------- */
int * sequencia_aleatoria_sem_repeticao (int intervalo){
  int * vet = new int[intervalo];
  int i,j;
  int achou = 0;
  for( i = 0; i < intervalo; i++){
    do {
      vet[i] = rand()%intervalo;
      achou = 0;
      for (j = 0; j < i; j++){
        if (vet[i] == vet[j]){
          achou = 1;
          break;
        }
      }
    } while (achou);
  }
  return vet;
}
/* ------------------------------------------------------------------------- */
