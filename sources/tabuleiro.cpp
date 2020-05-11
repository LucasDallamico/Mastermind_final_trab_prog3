#include "../header/tabuleiro.h"
#include "../header/bola.h"
#include "../header/jogo.h"
#include "../header/funcoes.h"
/* ------------------------------------------------------------------------- */
tabuleiro::tabuleiro(jogo &game) : jogo(game){
  int i,j;
  // variaveis retiradas do escopo que vao sumir logo
  int tam_senha = get_Tcodigo();
  int n_c = get_Ncores();
  int palpites = get_palpites();

  colors = new string[n_c];// alocando o vetor de cores no construtor
  string vet_10_cores[10]={"VERMELHO","AMARELO","AZUL","VERDE","BRANCO","LILÁS","VIOLETA","ROSA","LARANJA","ROXO"};
  for(int k=0;k<n_c;k++){
    colors[k]=vet_10_cores[k];
  }
  string vazio="[       ]";
  for(i=0;i<palpites;i++){
      for(j=0;j<tam_senha;j++){
          v[i][j].set_cor(vazio);
          resposta[i][j].set_cor(vazio);
      }
  }
}
/* ------------------------------------------------------------------------- */
void tabuleiro::imprime(void){
  int i,j;
  int palpites = get_palpites();
  int tam_senha = get_Tcodigo();
  string cor_posicao;
  for(i=0;i<palpites;i++){
    for(j=0;j<tam_senha;j++){
      cor_posicao=v[i][j].get_cor();
      if(cor_posicao=="[       ]"){
        cout<<"[       ]";
      }else{
        cout<<"[ "<<cor_posicao<<" ]";
      }
    }
    cout<<endl;
  }
}
/* ------------------------------------------------------------------------- */
void tabuleiro::imprime_resposta(void){
  int i,j;
  int palpites = get_palpites();
  int tam_senha = get_Tcodigo();
  string cor_posicao;
  for(i=0;i<palpites;i++){
    for(j=0;j<tam_senha;j++){
      cor_posicao=resposta[i][j].get_cor();
      if(cor_posicao=="[       ]"){
        cout<<"[       ]";
      }else{
        cout<<"[ "<<cor_posicao<<" ]";
      }
    }
    cout<<endl;
  }
}
/* ------------------------------------------------------------------------- */
int tabuleiro::verifica_cor(string color){
  int i;
  int n_c = get_Ncores();
  for(i=0;i<n_c;i++){
    if(colors[i]==color){
      return 1;
    }
  }
  return 0;
}
/* ------------------------------------------------------------------------- */
int tabuleiro::verifica_cor_jogador2(string color){
  if ( color == "PRETO") return 1;
  else if ( color == "BRANCO") return 1;
  else if ( color == "BRANCO") return 1;
  else return 0;
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: set_posicao1(int p, string color, int linha){
    v[linha][p-1].set_cor(color);
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: set_posicao2(int p, string color, int linha){
    resposta[linha][p-1].set_cor(color);
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: imprime_palpite(int l){
  int i;
  string cor_posicao;
  for(i=0;i<get_Tcodigo();i++){
    cor_posicao=v[l][i].get_cor();
    if(cor_posicao=="[       ]"){
      cout<<"[       ]";
    }else{
      cout<<"[ "<<cor_posicao<<" ]";
    }
  }
  cout<<endl;
}
/* ------------------------------------------------------------------------- */
 int tabuleiro:: imprime_palpite2(int l){
  int i;
  int s=0;
  string cor_posicao;
  for(i=0;i<get_Tcodigo();i++){
    cor_posicao=resposta[l][i].get_cor();
    if(cor_posicao=="PRETO"){
      s+=1;
    }
    if(cor_posicao=="[       ]"){
      cout<<"[       ]";
    }else{
      cout<<"[ "<<cor_posicao<<" ]";
      }
  }
  cout<<endl;
  if(s==get_Tcodigo()){
      return 1;
  }
  return 0;
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: mostrar_cores(void){
  //cout<< "------------------------------------------------------------------------------"<<endl;
  cout<<" Você tem acesso a estas cores, digite da mesma maneira que está escrita"<<endl;
  cout<<endl<<" |";
  for(int i=0;i<get_Ncores();i++){
      cout<<"("<<colors[i]<<") ";
  }
  cout<<"|"<<endl;
  cout<<endl;
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: help(void){
  while(1){
    int n;
    cout << endl << endl;
    cout<<" Digite o número corresponde para acessar ao campo desejado"<<endl;
    cout << endl << "  1-Cores acessíveis";
    cout << endl << "  2-Checar estado atual do jogo";
    cout << endl << "  3-Quantides de cores tem que digitar";
    cout << endl << "  4-Voltar ao jogo";
    cout << "\n:";
    cin>>n;
    cout << endl;
    if(n==1) mostrar_cores();
    if(n==2) mapa_de_jogo();
    if(n==3){
      cout << "Numero de cores que precisa digitar: " << get_Tcodigo() << endl;
    }
    if(n==4){
      system("clear");
      break;
    }
  }
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: gera_resposta(int linha){
  int ordem[get_Tcodigo()],i,j;
  int v_pal[get_Tcodigo()];
  int t_senha = get_Tcodigo();
  // estados permitidos 0 - unico 1 copia 2- posicao igual
  //setar as novas matrizes
  for ( i = 0; i < t_senha; i++){
    //v_res[i] = 0;
    v_pal[i] = 0;
  }
  // verificar repetido
  for ( i = 0; i < t_senha; i++){
    for (j = 0; j < t_senha; j++){
      if (v[linha][i].get_cor() == v[linha][j].get_cor() && i != j)
        v_pal[j] = 1;
    }
  }
  /*
  Intervensão - reorganizar a logica
  0 - PRETO
  1- BRANCO
  2 - CINZA

  */
  // setar o vetor ordem com cinza
  for ( i = 0; i < t_senha; i++){
      ordem[i] = 2;
  }

  int k = 0;
  // verificar a presença de pretos
  for ( i = 0; i < t_senha; i++){
    if(v[linha][i].get_cor() == senha_pc[i]){
      // salvar alteração
      v_pal[i] = 2;
      //v_res[i] = 2;
      ordem[k] = 0;
      k++;
    }
  }

  // verificar pinos brancos - usando os vetores de estado
  for ( i = 0; i < t_senha; i++){
    for (j = 0; j < t_senha; j++){
      if(v[linha][i].get_cor() == senha_pc[j] && i != j && v_pal[j] <= 0 ){
        ordem[k] = 1;
        k++;
      }
    }
  }
  // setando a matriz de resposta
  //os primeiros numeros do vetor ordem devem ser 0, depois 1 e por fim 2
 i=0;
 j=0;
 for(i=0;i<t_senha;i++){
     if(ordem[i]==0){
         resposta[linha][i].set_cor("PRETO");
     }else if(ordem[i]==1){
         resposta[linha][i].set_cor("BRANCO");
     }else if(ordem[i]==2){
         resposta[linha][i].set_cor("CINZA");
     }
 }
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: cria_senha_sem_repetidos(int intervalo){
  int t_senha = get_Tcodigo();
  senha_pc=new string[t_senha+1];// alocando o vetor de cores no construtor
  if (!senha_pc)  cout<<"FUDEU\n";
  int *vet_posi=sequencia_aleatoria_sem_repeticao(intervalo);
  string vet_10_cores[10]={"VERMELHO","AMARELO","AZUL","VERDE","BRANCO","LILÁS","VIOLETA","ROSA","LARANJA","ROXO"};
  for(int k=0;k<t_senha;k++){
      senha_pc[k]=vet_10_cores[vet_posi[k]];
  }
  delete [] vet_posi;
}
/* ------------------------------------------------------------------------- */
void tabuleiro:: cria_senha_com_repetidos(int intervalo){
  int t_senha = get_Tcodigo();
  senha_pc = new string[t_senha+1];// alocando o vetor de cores no construtor
  if (!senha_pc)  cout<<"FUDEU\n";
  int *vet_posi = sequencia_aleatoria_com_repeticao(intervalo);
  string vet_10_cores[10]={"VERMELHO","AMARELO","AZUL","VERDE","BRANCO","LILÁS","VIOLETA","ROSA","LARANJA","ROXO"};
  for(int k=0;k<t_senha;k++){
      senha_pc[k]=vet_10_cores[vet_posi[k]];
  }
  delete [] vet_posi;
}
/* ------------------------------------------------------------------------- */
int tabuleiro:: venceu(int linha){
  int i;
  int cont = 0;
  int t_senha = get_Tcodigo();
  for( i = 0; i < t_senha; i++){
    // olhe a cilada aqui
    //if(resposta[linha][i].get_cor() == senha_pc[i]){ cont++;}
    if (resposta[linha][i].get_cor() == "PRETO")
      cont++;
  }
  if(cont==t_senha)return 1;
  else return 0;
}
/* ------------------------------------------------------------------------- */
int tabuleiro::resposta_do_PC(int i){
  string color = " ";
    system("clear");
    cout << "Resposta: "<<endl;
    gera_resposta(i);
    if(venceu(i)==1){
      resultado_jogo_vencedor();
      return 1;
    } else {
      mapa_de_jogo();
      return 0;
    }
}
/* ------------------------------------------------------------------------- */
tabuleiro::~tabuleiro(){
  if (colors != nullptr)
    delete []colors;
  if (senha_pc != nullptr)
    delete []senha_pc;
}
/* ------------------------------------------------------------------------- */
void tabuleiro::mapa_de_jogo(void){
  system("clear");
  cout <<"------------------------------------------------------------------------------"<<endl;
  cout <<"                          MAPA ATUAL DO JOGO\n";
  cout <<"------------------------------------------------------------------------------"<<endl;
  cout << "------------------------- INFORMAÇÕES DO JOGO -------------------------------- \n";
  cout <<" # Número de cores:     " << get_Ncores() <<endl;
  cout <<" # Tamanho do código:   "<< get_Tcodigo()<<endl;
  cout <<" # Número de palpites:  "<<get_palpites()<<endl;
  if(get_corRep()==true){
      cout <<" # Cores Repetidas:  Sim"<<endl;
  }else{
      cout <<" # Cores Repetidas:  Não"<<endl;
  }
  cout <<"------------------------------------------------------------------------------ \n";
  cout << " Impressão dos palpites até agora: \n";
  imprime();
  cout << endl << endl;
  cout << " Impressão das respostas até agora: \n";
  imprime_resposta();
  cout <<endl<<"------------------------------------------------------------------------------"<<endl;
  cout << " Digite qualquer coisa para continuar: ";
  string a;
  cin >> a;
  system("clear");
}
/* ------------------------------------------------------------------------- */
void tabuleiro::resultado_jogo_vencedor(void){
  system("clear");
  cout <<"------------------------------------------------------------------------------"<<endl;
  cout <<"                     MAPA ATUAL DO JOGO\n";
  cout <<"------------------------------------------------------------------------------"<<endl;
  cout << " Impressão dos palpites até agora: \n";
  imprime();
  cout << endl << endl;
  cout << " Impressão das respostas até agora: \n";
  imprime_resposta();
  cout <<endl<<"------------------------------------------------------------------------------"<<endl;
  cout <<"______________________________________________________________________________"<<endl;
  cout <<"                    JOGADOR 1 VENCEU !!! \n";
  cout <<"______________________________________________________________________________"<<endl;
  cout << " Digite qualquer coisa para continuar: ";
  string a;
  cin >> a;
  system("clear");
}
/* ------------------------------------------------------------------------- */
void tabuleiro::texto_jogador1(void){
  cout <<"------------------------------------------------------------------------------"<<endl;
  cout << endl;
  mostrar_cores();
  cout << endl;
  cout <<"------------------------------------------------------------------------------"<<endl;
  cout << "Jogador 1:";
  cout << " Insira seu palpite [MAISUCULO]: "<< endl;
  // colocar aqui as cores disponiveis, para facilitar
  cout << "  - Exemplo de entrada: [AZUL BRANCO CINZA PRETO] " << endl;
  cout << "  - se precisar de ajuda digite [help]" << endl;
  cout <<"------------------------------------------------------------------------------"<<endl;
}
/* ------------------------------------------------------------------------- */
void tabuleiro::texto_jogador2(int linha_atual){
  system("clear");
  cout <<"------------------------------------------------------------------------------"<<endl;
  cout << " Palpite do jogador 1 dado: \n";
  imprime_palpite(linha_atual);
  cout << endl;
  cout << " Jogador 2 : \n";
  cout << " Insira a sequencia da senha [MAISUCULO]: " << endl;
  cout << "   - Exemplo de entrada : Se o usuario acertou " << endl;
  cout << "     [ PRETO BRANCO BRANCO BRANCO]" << endl;
  cout << "  - se precisar de ajuda digite [help]" << endl << endl;
  //cout <<"------------------------------------------------------------------------------"<<endl;
}
/* ------------------------------------------------------------------------- */
