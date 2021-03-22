#ifndef ESTACAO_HPP
#define ESTACAO_HPP

class Estacao {
    private:
        int tempo;
        int custo;
    
    public:
        Estacao(){};
        Estacao(int tempo, int custo);
        double getCusto (double desconto);
        int getTempo ();
};

#endif