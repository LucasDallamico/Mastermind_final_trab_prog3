#include "../header/jogo.h"
#include "../header/bola.h"
#include "../header/funcoes.h"
// ---------- Contrutor de herança ---------------------------------
jogo::jogo(jogo &game){
  this->n_cores = game.get_Ncores();
  this->t_codigo = game.get_Tcodigo();
  this->n_palpites = game.get_palpites();
  this->tipo_de_jogo = game.get_tipo();
  this->cores_repetidas = game.get_corRep();
}
// ------------- Contrutor inicial ----------------------------------
jogo::jogo(void){
  cout << " Configurações iniciais do jogo: \n";
  cout << endl;
  // definir tipo de jogo
  cout << " Tipo de jogo: \n";
  cout << "  - Player Vs. Player [1] \n";
  cout << "  - Player Vs. PC [2] \n";
  cout << ":";
  while(1){
    cin >> tipo_de_jogo;
    if ( tipo_de_jogo < 1 || tipo_de_jogo > 2)
      cout << " Valor inválido, por favor, insira novamente o valor entre [1 a 2]: ";
    else
      break;
  }
  system("clear");
  cout << "----------------------------------------------------------------------------\n";
  // pegar a qnt de cores
  cout << " Insira a quantidade de cores desejadas [4 a 10]: ";
  while(1){
    cin >> n_cores;
    if ( n_cores < 4 || n_cores > 10)
      cout << " Valor inválido, por favor, insira novamente o valor entre [ 4 a 10 ]: ";
    else
      break;
  }

  // pegar o tamanho do codigo (colunas: qnt de numeros para senha)
  cout << " Escolha o tamanho do código [entre 4 e 6]: ";
  while(1){
    cin >> t_codigo;
    if ( t_codigo < 4 || t_codigo > 6 )
      cout << " Valor inválido, por favor, insira novamente o valor entre [4 a 6]: ";
    else
      break;
  }

  // quantos palpites vai poder dar por partida
  cout << " Escolha a quantidade de palpites [entre 4 e 10]: ";
  while(1){
    cin >> n_palpites;
    if (n_palpites < 4 || n_palpites > 10)
      cout << " Valor inválido, por favor, insira novamente o valor entre [4 a 10]: ";
    else
      break;
  }

   // para ter cores repetidas
   char c;
   cout << " Deseja cores repetidas [s/n]: ";
   while(1){
    cin >> c;
    if (c == 's'){
      cores_repetidas = true;
      break;
    }
    else if (c == 'n'){
      cores_repetidas = false;
      break;
    }
    else
      cout << " Insira [s ou n] no campo: \n";
   }
   system("clear");
}
// ----------------------------- NIVEL ---------------------------------------------------------------
void jogo::set_nivel(void){
  int level=0;
  niveis_menu();
  cin>>level;
  if ( level != -1){
    if(level<=0 || level>5){
        while(1){
           cout<<"Valor inválido, por favor insira o valor corretamente [1 a 5]: "<<endl;
           cin>>level;
           if(level>0 && level<=5) break;
        }
    }
    // niveis do jogo
    int a,b,c;
    if(level==1){
      a=10;b=4;c=4;
    }else if(level==2){
      a=9;b=5;c=5;
    }else if(level==3){
      a=6;b=5;c=7;
    }else if(level==4){
      a=5;b=5;c=8;
    }else if(level==5){
      a=4;b=6;c=10;
    }
    // alteração do game ( por causa dos niveis )
    set_palpites(a);
    set_Tcodigos(b);
    set_Ncores(c);
  }
  system("clear");
}
//------------------------------------------gets-------------------------------------------------------
int jogo::get_Ncores(void){ return n_cores;}
int jogo::get_Tcodigo(void){return t_codigo;}
int jogo::get_palpites(void){return n_palpites;}
int jogo::get_tipo(void){return tipo_de_jogo;}
bool jogo::get_corRep(void){return cores_repetidas;}
//------------------------------------------gets-------------------------------------------------------
void jogo::set_Tcodigos(int codigos) { t_codigo = codigos;}
void jogo::set_palpites(int palpites) { n_palpites = palpites;}
void jogo::set_Ncores(int cores) { n_cores = cores;}

//--------------------------------------Overload do cout-----------------------------------------------
ostream & operator<<(ostream & saida, jogo & j){
    saida << " ------------ Dados do jogo ------------ \n";
    saida<<" Número de cores: "<<j.get_Ncores()<<endl;
    saida<<" Tamanho do código: "<<j.get_Tcodigo()<<endl;
    if(j.get_tipo()==1){
        saida<<" Tipo de Jogo: Player Vs. Player"<<endl;
    }else{
        saida<<" Tipo de Jogo: Player Vs. Computador"<<endl;
    }
    saida<<" Número de palpites: "<<j.get_palpites()<<endl;
    if(j.get_corRep()==true){
        saida<<" Cores Repetidas: Sim"<<endl;
    }else{
        saida<<" Cores Repetidas: Não"<<endl;
    }
    saida << " ---------------------------------------- \n";
    return saida;
}
//--------------------------- polimorfismo da cara dura --------------------------------------------------
void jogo::mapa_de_jogo(void){
  cout << " ------------ INFORMAÇÕES DO JOGO ------------ \n";
  cout <<" # Número de cores:     " << n_cores <<endl;
  cout <<" # Tamanho do código:   "<< t_codigo<<endl;
  cout <<" # Número de palpites:  "<<n_palpites<<endl;
  if(cores_repetidas==true){
      cout <<" # Cores Repetidas:  Sim"<<endl;
  }else{
      cout <<" # Cores Repetidas:  Não"<<endl;
  }
}

jogo::~jogo(){}
