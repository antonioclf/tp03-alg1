#ifndef STATION
#define STATION

class Estacao{
    private:
        int tempo;
        int custo;

    public:
        Estacao(){};
        Estacao(int tempo, int custo);
        int get_tempo();
        double get_preco(double desconto);
};

#endif
