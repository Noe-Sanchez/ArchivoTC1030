#include <string>
#include <iostream>
#include <vector>
using namespace std;

class FiguraRegular{
    protected:
        string nombre;
        int base, altura;
    public:
        FiguraRegular(){
            base = 0;
            altura = 0;
            nombre = "";
        }
        FiguraRegular(string _nombre, int _base, int _altura){
            base = _base;
            altura = _altura;
            nombre = _nombre;
        }
        virtual double calculaArea(){
            return 0;
        }
        virtual string data(){
            return ("Figura: " + nombre + ", base: " + to_string(base) + ", altura: " + to_string(altura));
        }
};
class Rectangulo:public FiguraRegular{
    public:
        Rectangulo():FiguraRegular(){
            FiguraRegular();
        }
        Rectangulo(string _nombre, int _base, int _altura):FiguraRegular(_nombre, _base, _altura){
            FiguraRegular(_nombre, _base, _altura);
        }
        double calculaArea(){
            return base*altura;
        }
        string data(){
            return ("Rectangulo: "+ nombre + ", base: " + to_string(base) + ", altura: " + to_string(altura));
        }
};
class Triangulo:public FiguraRegular{
    public:
        Triangulo():FiguraRegular(){
            FiguraRegular();
        }
        Triangulo(string _nombre, int _base, int _altura):FiguraRegular(_nombre, _base, _altura){
            FiguraRegular(_nombre, _base, _altura);
        }
        double calculaArea(){
            return double(base*altura)/2.0;
        }
        string data(){
            return ("Triangulo: " + nombre + ", base: " + to_string(base) + ", altura: " + to_string(altura));
        }
};

int main(){
    vector<FiguraRegular*> figs;

    figs.push_back(new FiguraRegular("Poli", 3, 4));
    figs.push_back(new Rectangulo("Rect1", 4, 5));
    figs.push_back(new Triangulo("Triang1", 1, 3));

    for(int i = 0; i < 3; i++){
        cout << figs[i]->data() << ", area: " << figs[i]->calculaArea() << endl;
    }

    return 0;
}