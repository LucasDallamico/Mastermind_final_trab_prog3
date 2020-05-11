#ifndef BOLA_H
#define BOLA_H
/* ------------------------------------------------------------------------ */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
/* ------------------------------------------------------------------------ */
class Bola{
    private:
        string cor;
    public:
        Bola();
        void set_cor(string color);
        string get_cor(void);
        ~Bola();
};
/* ------------------------------------------------------------------------ */
#endif
