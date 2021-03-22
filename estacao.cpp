#include "estacao.hpp"

Estacao::Estacao(int tempo, int custo){
    this -> tempo = tempo;
    this -> custo = custo;
}

double Estacao::getCusto(double desconto){
    double custo_final = (double) custo;

    return (custo_final - (custo_final*desconto));
}

int Estacao::getTempo(){
    return tempo;
}
