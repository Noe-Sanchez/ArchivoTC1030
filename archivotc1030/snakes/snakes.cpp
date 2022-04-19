#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>

class Player{

    public:
        Player(int _id){
            casilla = 0;
            id = _id;
        }

        int getCasilla(){
            return(casilla);
        }
        int getId(){
            return(id);
        }

        void moveCasilla(int _casilla){
            casilla += _casilla;
        }
        void setCasilla(int _casilla){
            casilla = _casilla;
        }

        friend std::ostream& operator<< (std::ostream& out, const Player& player);                

    private:
        int casilla, id;
};

class Casilla{
    public:
        Casilla(char _tipo){
            tipo = _tipo;
            if(tipo == 'S'){
                value = -3;
            }else{
                value = 3;
            }
        }

        int getValue(){
            return(value);
        }
        char getType(){
            return(tipo);
        }

        friend std::ostream& operator<< (std::ostream& out, const Casilla& casilla);                

    private:
        int value;
        char tipo;
};

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
        MyGame(int l, int n){
            srand(time(NULL));
            int r;
            bool sw = true;
            int sl = 0;
            std::vector<char> vcasillas;

            for(int cell = 0; cell < l; cell++){
                    vcasillas.push_back('N');
            }

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
            for(int i = 0; i < vcasillas.size(); i++){
                board.push_back(Casilla(vcasillas[i]));
            }
        }

        void print_board(){
            std::cout << "Game board: " << std::endl;
            for(int l = 0; l < board.size(); l++){
                std::cout << board[l];
            }
            std::cout << std::endl;
        }

        void print_party(){
            std::cout << "Players: " << std::endl;
            for(int m = 0; m < party.size(); m++){
                std::cout << party[m];
            }
        }

        void addPlayer(Player player){
            party.push_back(player);
        }

        void start(){
            
            print_board();
            print_party();
            
            bool in_game = true, in_query = true, qend = false;
            int turn = 0, roll = 1, nowp = 1;
            char ipt;
            srand (time(NULL));
            
            while(in_game == true){
                roll = (rand() % 6) + 1;
                nowp = turn % party.size();
                /*
                std::cout << "Turno: " << turn+1 << ", el Jugador " << party[nowp].getId() << " en la casilla " << party[nowp].getCasilla() 
                << ", roleo un " << roll << ", lo que lo puso en una casilla de tipo ";
                party[nowp].moveCasilla(roll); 
                std::cout << board[party[nowp].getCasilla()].getType();
                std::cout << "[" << party[nowp].getCasilla() << "]"; 

                if(board[party[nowp].getCasilla()].getType() != 'N'){
                    party[nowp].moveCasilla(board[party[nowp].getCasilla()].getValue());
                }

                std::cout << ", que al final lo puso en la posición " << party[nowp].getCasilla() << std::endl; 
                */
                std::cout << turn+1 <<" "<< party[nowp].getId() <<" "<< party[nowp].getCasilla()+1;
                party[nowp].moveCasilla(roll); 
                 if (party[nowp].getCasilla()< 1){
                    party[nowp].moveCasilla(1);
                 }
                    
                std::cout << " " << roll << " " << board[party[nowp].getCasilla()].getType();
                if(board[party[nowp].getCasilla()].getType() != 'N'){
                    party[nowp].moveCasilla(board[party[nowp].getCasilla()].getValue());
                }
                if(party[nowp].getCasilla() >= board.size()){
                    qend = true;
                    party[nowp].setCasilla(board.size()-1);     
                }
                std::cout << " " << party[nowp].getCasilla()+1 << std::endl;
                if(qend == true){
                    break;
                }
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
                turn++;
            }
            std::cout << "GAM OVERRR!!!" << std::endl << "Player " << party[nowp].getId() << " won" << std::endl;
            print_party();
        }

    private:
        std::vector<Casilla> board;
        std::vector<Player> party;
};

int main(){
    int a, b, c;

    std::cout << "Number of tiles" << std::endl;
    std::cin >> a;
    std::cout << "Number of special tiles" << std::endl;
    std::cin >> b; 
    std::cout << "Number of players" << std::endl;
    std::cin >> c; 

    MyGame g(a, b);
    for(int id = 1; id <= c; id ++){
        g.addPlayer(Player(id));
    }

    g.start();
    return 0;
}
