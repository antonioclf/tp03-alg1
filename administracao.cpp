#include "estacao.hpp"
#include "administracao.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Administracao::Administracao(){
    this->contador_estacoes = 0;
    this->max_estacoes = 0;
    this->tempo_desconto_limite = 0;
}

void Administracao::inicializar_custos(){
    this->custos = new double* [this->contador_estacoes];
    for (int i = 0; i < this->contador_estacoes; i++){
        this->custos[i] = new double[this->contador_estacoes];
    }

}

double Administracao::get_minimo(int coluna){

    if(coluna < 0){
        return 0;
    }

    double minimo = this->custos[0][coluna];

    for(int row = 1; row < this->contador_estacoes; row++){
        double custo = custos[row][coluna];

        if(custo < minimo && custo > 0){
            minimo = custo;
        }
    }

    return minimo;
}

void Administracao::matriz_custos(){

    for (int i = 0; i < this->contador_estacoes; i++){
        int tempo_cum = 0;
        int disconto_cum = 0;
        int estacoes_visitadas = 0;
        double minimo_atual = get_minimo(i -1);

        for (int j = i; j < this->contador_estacoes; j++){
            Estacao Estacao = this->estacoes.at(j);

            if(estacoes_visitadas < this->max_estacoes){
                disconto_cum += this->descontos.at(estacoes_visitadas);
            }
            else{
                disconto_cum = 0;
            }

            this->custos[i][j] = minimo_atual + Estacao.get_preco(disconto_cum / 100.0);
            minimo_atual = this->custos[i][j];
            estacoes_visitadas++;
            tempo_cum += Estacao.get_tempo();

            if(tempo_cum >= this->tempo_desconto_limite){
                disconto_cum = 0;
                tempo_cum = 0;
                estacoes_visitadas = 0;
            }
        }
    }
}

void Administracao::inicio(){

    cin >> this->contador_estacoes >> this->max_estacoes >> this->tempo_desconto_limite;

    for (int i = 0; i < this->max_estacoes; i++){
        int desconto;
        cin >> desconto;

        this->descontos.push_back(desconto);
    }

    for (int i = 0; i < this->contador_estacoes; i++){
        int tempo;
        int custo;

        cin >> tempo >> custo;

        this->estacoes.push_back(Estacao(tempo, custo));
    }

    inicializar_custos();
    matriz_custos();

    double custo_minimo = get_minimo(this->contador_estacoes - 1);
    cout << fixed << setprecision(2) << custo_minimo << endl;

}