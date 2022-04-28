#include <String>
#include <iostream>
using namespace std;

class Envio{
	public:
		Envio(string _d, string _r){
			d = _d;
			r = _r;
		}
		virtual double costo(){return 0;};
		friend int main();
	private:
		string d,r;

};

class Sobre: public Envio{
	public:
		Sobre(string _d, string _r, int _largo, int _ancho):Envio(_d, _r){
			Envio(_d, _r);
			largo = _largo;
			ancho = _ancho;
		}
		double costo(){
			return (largo*ancho);
		}
		friend ostream& operator<< (ostream& out, const Sobre& sobre);
	private:
		int largo, ancho;
};

class Paquete: public Envio{
	public:
		Paquete(string _d, string _r, int _largo, int _ancho, int _profundidad, int _peso):Envio(_d, _r){
			Envio(_d, _r);
			largo = _largo;
			ancho = _ancho;
			profundidad = _profundidad;
			peso = _peso;
		}
		double costo(){
			return (largo*ancho*profundidad*peso);
		}

		friend ostream& operator<<(ostream& out, const Paquete& paquete);
	private:
		int largo, ancho, profundidad, peso;
};

ostream& operator<< (ostream& out, const Paquete& paquete){
    out << "Paquete";
    return(out);
} 
ostream& operator<< (ostream& out, const Sobre& sobre){
    out << "Sobre";
    return(out);
} 

int main(){

	Sobre sobre1(string("Nallely"),string("Ivan"), 30, 20);
	Paquete paquete1(string("Nallely"),string("Ivan"), 30, 20,10,3);
	cout << "Costo del " << sobre1 << ": " << sobre1.costo() << ", Para: " << sobre1.d << ", De: " << sobre1.r << endl;
	cout << "Costo del " << paquete1 << ": " << paquete1.costo() << ", Para: " << paquete1.d << ", De: " << paquete1.r << endl;
	return 0;
}
