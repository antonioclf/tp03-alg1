#include "estacao.hpp"

Estacao::Estacao(int tempo, int custo){
    this->tempo = tempo;
    this->custo = custo;
}

int Estacao::get_tempo(){
    return tempo;
}

double Estacao::get_preco(double desconto){
    double doublePrice = (double)custo;

    return (doublePrice - (doublePrice * desconto));
}
