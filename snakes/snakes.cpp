#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>

class Player{

    public:
        //Constructor
        Player(int _id){
            casilla = 0;
            id = _id;
        }

        //Getters
        int getCasilla(){
            return(casilla);
        }
        int getId(){
            return(id);
        }

        //Setters
        void moveCasilla(int _casilla){
            casilla += _casilla;
        }
        void setCasilla(int _casilla){
            casilla = _casilla;
        }

        //Output
        friend std::ostream& operator<< (std::ostream& out, const Player& player);                

    private:
        int casilla, id;
};

class Casilla{
    public:
        //Constructores
        Casilla(char _tipo){
            tipo = _tipo;
            if(tipo == 'S'){
                value = -3;
            }else{
                value = 3;
            }
        }

        //Getters
        int getValue(){
            return(value);
        }
        char getType(){
            return(tipo);
        }

        //Output
        friend std::ostream& operator<< (std::ostream& out, const Casilla& casilla);                

    private:
        int value;
        char tipo;
};

//Sobrecarga
std::ostream& operator<< (std::ostream& out, const Player& player){
    out << "Player " << player.id << " at tile " << player.casilla+1 << std::endl;
    return(out);
} 
std::ostream& operator<< (std::ostream& out, const Casilla& casilla){
    out << casilla.tipo;
    return(out);
} 

class MyGame{
    public:
        //Constructor
        MyGame(int l, int n){
            srand(time(NULL));
            int r;
            bool sw = true;
            int sl = 0;
            std::vector<char> vcasillas;

            //Creamos un vector de casillas normales
            for(int cell = 0; cell < l; cell++){
                    vcasillas.push_back('N');
            }

            //Remplazamos n casillas por casillas especiales
            while(sl < n){
                    r = rand() % l;
                    if(vcasillas[r] == 'N'){
                        if(sw == true){
                            vcasillas[r] = 'L';        
                        }else{
                            vcasillas[r] = 'S';
                        }
                        sl++;
                        sw = !sw;
                    }
            }

            //Asignamos al miembro via constructor
            for(int i = 0; i < vcasillas.size(); i++){
                board.push_back(Casilla(vcasillas[i]));
            }
        }

        //Output
        void print_board(){
            std::cout << "\nGame board: " << std::endl;
            for(int l = 0; l < board.size(); l++){
                std::cout << board[l];
            }
            std::cout << std::endl;
        }
        void print_party(){
            std::cout << "\nPlayers: " << std::endl;
            for(int m = 0; m < party.size(); m++){
                std::cout << party[m];
            }
            std::cout << std::endl;
        }

        //Setter
        void addPlayer(Player player){
            party.push_back(player);
        }

        //Mainloop
        void start(){
            //Estado del arte
            print_board();
            print_party();
            
            //Setup
            bool in_game = true, in_query = true, qend = false;
            int turn = 0, roll = 1, nowp = 1;
            char ipt;
            srand (time(NULL));
            
            while(in_game == true){
                //Rolleamos un numero aleatorio y pasamos al siguiente jugador
                roll = (rand() % 6) + 1;
                nowp = turn % party.size();
                
                //Imprimimos turno, id, y casilla inicial
                std::cout << turn+1 <<" "<< party[nowp].getId() <<" "<< party[nowp].getCasilla()+1;

                //Movemos al jugador
                party[nowp].moveCasilla(roll); 

                //Checamos y printeamos el tipo de casilla donde cayó
                std::cout << " " << roll << " " << board[party[nowp].getCasilla()].getType();

                //Si es casilla especial, aplica su valor
                if(board[party[nowp].getCasilla()].getType() != 'N'){
                    party[nowp].moveCasilla(board[party[nowp].getCasilla()].getValue());
                }

                //Checa si alguien ganó
                if(party[nowp].getCasilla() >= board.size()){
                    qend = true;
                    party[nowp].setCasilla(board.size()-1);
                }

                //Plotea la casilla final
                std::cout << " " << party[nowp].getCasilla()+1 << std::endl;
                if(qend == true){
                    break;
                }

                //Pide continuar o terminar
                in_query= true;
                while(in_query == true){ 
                    std::cin >> ipt; 
                    if(ipt == 'E'){
                        std::cout << "Thanks for playing" << std::endl;
                        in_game = false;
                        break;
                    }else if(ipt == 'C'){
                        in_query = false;
                    }else{
                        std::cout << "Invalid option" << std::endl;
                    }
                }              
                //Incremento
                turn++;
            }
            //Print final
            std::cout << "\nGAME OVERRR!" << std::endl << "Player " << party[nowp].getId() << " won" << std::endl;
            print_party();
        }

    private:
        std::vector<Casilla> board;
        std::vector<Player> party;
};

int main(){
    //Setup
    int a, b, c;

    std::cout << "Number of tiles" << std::endl;
    std::cin >> a;
    std::cout << "Number of special tiles" << std::endl;
    std::cin >> b; 
    std::cout << "Number of players" << std::endl;
    std::cin >> c; 

    //Genera el tablero con los specs
    MyGame g(a, b);

    //Añade los jugadores
    for(int id = 1; id <= c; id ++){
        g.addPlayer(Player(id));
    }

    //Empieza el juego
    g.start();
    return 0;
}
