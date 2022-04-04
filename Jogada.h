/**
 * @author Augusto dos Santos Gomes Vaz
 * Programa : cabeçalho da implementação da classe jogada do jogo water sort
 */
class Jogada{
    public:
        void setDoador(int doador);    //determina qual é o vidro que da o liquido
        void setReceptor(int receptor);//determina qual é o vidro que recebe o liquido
        int getDoador();               //devolve qual vidro da 
        int getReceptor();             //devolve qual vidro recebe
    private:
        int vidroDoador;
        int vidroReceptor;
};