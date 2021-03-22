#include "administracao.hpp"
#include "estacao.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Administracao::Administracao(){
    this->contador_estacoes = 0;
    this->max_estacoes = 0;
    this->tempo_limite_desconto = 0;
}

void Administracao::custoInicial(){
    this->custos = new double* [this->contador_estacoes];
    for(int i = 0;i < this ->contador_estacoes;i++){
        this->custos[i] = new double[this->contador_estacoes];
    }
}

double Administracao::getMinimo(int coluna){
    if(coluna < 0){
        return 0;
    }

    double minimo = this->custos[0][coluna];

    for(int i = 1; i < this->contador_estacoes; i++){
        double custo = custos[i][coluna];

        if(custo < minimo && custo > 0){
            minimo = custo; 
        }
    }

    return minimo;
}

void Administracao::matrizCustos(){

    for(int i = 0; i < this->contador_estacoes; i++){
        int tempo_cum = 0;
        int desconto_cum = 0;
        int estacoes_visitadas = 0;
        double minimo_atual = getMinimo(i-1);

        for(int j = i; j < this->contador_estacoes; j++){
            Estacao estacao = this->estacoes.at(j);

            if(estacoes_visitadas < this->max_estacoes){
                desconto_cum += this->descontos.at(j);
            }
            else{
                desconto_cum = 0; 
            }

            this->custos[i][j] = minimo_atual + estacao.getCusto(desconto_cum/100.0);
            minimo_atual = this->custos[i][j];
            estacoes_visitadas++;
            tempo_cum += estacao.getTempo();

            if(tempo_cum >= this->tempo_limite_desconto){
                desconto_cum = 0;
                tempo_cum = 0;
                estacoes_visitadas = 0; 
            }
        }
    }
}

void Administracao::inicio(){

    cin >> this->contador_estacoes >> this->max_estacoes >> this->tempo_limite_desconto; 

    for(int i = 0; i < this->max_estacoes; i++){
        int desconto;
        cin >> desconto;

        this->descontos.push_back(desconto);

    }

    for (int j=0; j < this->contador_estacoes; j++){
        int tempo;
        int custo;

        cin >> tempo >> custo;
        this->estacoes.push_back(Estacao(tempo,custo));

    }

    custoInicial();
    matrizCustos();

    double custo_minimo = getMinimo(this->contador_estacoes - 1);
    cout << fixed << setprecision(2) << custo_minimo << endl;

}
