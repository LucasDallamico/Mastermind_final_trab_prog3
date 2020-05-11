#ifndef JOGO_H
#define JOGO_H
/* ---------------------------------------------------------------- */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
/* ---------------------------------------------------------------- */
class jogo{
private:
    int n_cores; // qnt_cores
    int t_codigo; // tamanho da coluna
    int n_palpites; // tamanho da linha
    int tipo_de_jogo;
    bool cores_repetidas;
public:
    //----construtor------------------------------------
    jogo(void);
    jogo(jogo &game);
    // --- informações do jogo para usuario
    virtual void mapa_de_jogo(void);
    // Configurações do nivel
    void set_nivel(void);
    //-------gets---------------------------------------
    int get_Ncores(void);
    int get_Tcodigo(void);
    int get_palpites(void);
    int get_tipo(void);
    bool get_corRep(void);
    //-------sets----------------------------------------
    void set_Tcodigos(int codigos);
    void set_palpites(int palpites);
    void set_Ncores(int cores);
    //---Overload do cout---------------------------------
    friend ostream & operator<<(ostream & saida,jogo & j);
    ~jogo();
};
/* ---------------------------------------------------------------- */
#endif
