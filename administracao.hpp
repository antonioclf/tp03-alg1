#ifndef ADMINISTRACAO_HPP
#define ADMINISTRACAO_HPP

#include <vector>
#include "estacao.hpp"

using namespace std;

class Administracao{
    private:
        int contador_estacoes;
        int max_estacoes;
        int tempo_limite_desconto;
        vector <double> descontos;
        vector <Estacao> estacoes;
        double** custos;

    public:
        Administracao();
        void custoInicial(); //mudar nome
        void inicio();
        void matrizCustos(); //olhar isso pra mudar o nome
        double getMinimo(int);
};

#endif