#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Platillo{
    protected:
        string nombre;
        double precio;
    public:
        Platillo(){
            nombre = "[nombre]";
            precio = 0;
        }
        Platillo(string _nombre, double _precio){
            nombre = _nombre;
            precio = _precio;
        }
        virtual void show(){
            cout << "Platillo: " << nombre << ", precio: " << precio << endl;  
        }
        double getPrecio();
};

class Hamburguesa:public Platillo{
    private:
        map<string, double> tamanos  = {{"Regular", 1},{"Grande", 1.25}, {"Jumbo", 1.5}};
        string tamano;
    public:
        Hamburguesa():Platillo(){
            Platillo();
            tamano = "Regular";
        }
        Hamburguesa(string _nombre, double _precio, string _tamano):Platillo(_nombre, _precio){
            Platillo(_nombre, _precio);
            tamano = _tamano;
        }
        void show(){
            cout << "Hamburguesa: " << nombre << ", precio regular: " << precio << ", precio real: " << getPrecio() << " (" << tamano << ")" << endl;  
        }
        double getPrecio(){
            auto it = tamanos.find(tamano);
            return (precio * it->second);
        }
};
class Sushi:public Platillo{
    private:
        map<string, double> ingredientes  = {{"Pepino", 1},{"Salmon", 1.5}, {"Camaron", 2}};
        string ingrediente;
    public:
        Sushi():Platillo(){
            Platillo();
            ingrediente = "Pepino";
        }
        Sushi(string _nombre, double _precio, string _ingrediente):Platillo(_nombre, _precio){
            Platillo(_nombre, _precio);
            ingrediente = _ingrediente;
        }
        void show(){
            cout << "Sushi: " << nombre << ", precio regular: " << precio << ", precio real: " << getPrecio() << " (" << ingrediente << ")" << endl;  
        }
        double getPrecio(){
            auto it = ingredientes.find(ingrediente);
            return (precio * it->second);
        }
};
class Ensalada:public Platillo{
    private:
        map<string, double> aderezos  = {{"Cesar", 1.15},{"Mil islas", 1.25}, {"Ranch", 1.35}};
        string aderezo;
    public:
        Ensalada():Platillo(){
            Platillo();
            aderezo = "Mil islas";
        }
        Ensalada(string _nombre, double _precio, string _aderezo):Platillo(_nombre, _precio){
            Platillo(_nombre, _precio);
            aderezo = _aderezo;
        }
        void show(){
            cout << "Ensalada: " << nombre << ", precio regular: " << precio << ", precio real: " << getPrecio() << " (Aderezo " << aderezo << ")" << endl;  
        }
        double getPrecio(){
            auto it = aderezos.find(aderezo);
            return (precio * it->second);
        }
};


int main(){
    cout << "\nMenu de platillos Bugsracer: " << endl << endl;

    vector<Platillo*> menu;
    menu.push_back(new Platillo("Fetuccini Alfredo", 130));
    menu.push_back(new Hamburguesa("Teriyaki", 100, "Grande"));
    menu.push_back(new Hamburguesa("Western", 120, "Jumbo"));
    menu.push_back(new Sushi("Nigiri", 80, "Salmon"));
    menu.push_back(new Sushi("Maki", 50, "Camaron"));
    menu.push_back(new Ensalada("Capri", 90, "Ranch"));
    menu.push_back(new Ensalada("Griega", 110, "Ranch"));

    for(int i = 0; i < menu.size(); i++){
        menu[i]->show();
    }
    cout << endl;
    return 0;
}