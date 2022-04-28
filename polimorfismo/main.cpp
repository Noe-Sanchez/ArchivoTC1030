#include <iostream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Envio{
	public:
		Envio(string _nombreD, string _nombreR, string _direccionD, string _direccionR, string _ciudadD, string _ciudadR, string _estadoD, string _estadoR, string _cpD, string _cpR){
			nombreD = _nombreD;
			nombreR = _nombreR;
			direccionD = _direccionD;
			direcccionR = _direccionR;
			ciudadD = _ciudadD;
			ciudadR = _ciudadR;
			estadoD = _estadoD;
			estadoR = _estadoR;
			cpD = _cpD;
			cpR = _cpR;

		}
		virtual double costo(){return 0;};
		virtual string getTipo(){return 0;};
		friend int main();
		friend ostream& operator<< (ostream& out, const Envio& envio);
	private:
		string nombreD, nombreR, direccionD, direcccionR, ciudadD, ciudadR, estadoD, estadoR, cpD, cpR;
};

class Sobre: public Envio{
	public:
		Sobre(string _nombreD, string _nombreR, string _direccionD, string _direccionR, string _ciudadD, string _ciudadR, string _estadoD, string _estadoR, string _cpD, string _cpR, int _largo, int _ancho):Envio(_nombreD, _nombreR, _direccionD, _direccionR, _ciudadD, _ciudadR, _estadoD, _estadoR, _cpD, _cpR){
			Envio(_nombreD, _nombreR, _direccionD, _direccionR, _ciudadD, _ciudadR, _estadoD, _estadoR, _cpD, _cpR);
			largo = _largo;
			ancho = _ancho;
		}
		double costo(){
			return (largo*ancho);
		}
		string getTipo(){
			return("Sobre");
		}
		friend ostream& operator<< (ostream& out, const Sobre& sobre);
	private:
		int largo, ancho;
};

class Paquete: public Envio{
	public:
		Paquete(string _nombreD, string _nombreR, string _direccionD, string _direccionR, string _ciudadD, string _ciudadR, string _estadoD, string _estadoR, string _cpD, string _cpR, int _largo, int _ancho, int _profundidad, int _peso):Envio(_nombreD, _nombreR, _direccionD, _direccionR, _ciudadD, _ciudadR, _estadoD, _estadoR, _cpD, _cpR){
			Envio(_nombreD, _nombreR, _direccionD, _direccionR, _ciudadD, _ciudadR, _estadoD, _estadoR, _cpD, _cpR);
			largo = _largo;
			ancho = _ancho;
			profundidad = _profundidad;
			peso = _peso;
		}
		double costo(){
			return (largo*ancho*profundidad*peso);
		}
		string getTipo(){
			return("Paquete");
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
ostream& operator<< (ostream& out, const Envio& envio){
    out << "Envio";
    return(out);
}

int main(){

	vector<Envio*> envios;
	envios.push_back(new Sobre(string("Nallely"),string("Ivan"), string("Villas de Suiza"), string("Villas Tec"), string("Monterrey"), string("Monterrey"), string("Nuevo Le�n"), string("Nuevo Le�n"), string("66055"), string("34050"), 30, 20));
	envios.push_back(new Paquete(string("Nallely"),string("Ivan"), string("Villas de Suiza"), string("Villas Tec"), string("Monterrey"), string("Monterrey"), string("Nuevo Le�n"), string("Nuevo Le�n"), string("66055"), string("34050"), 30, 20,10,3));

	//Sobre sobre1(string("Nallely"),string("Ivan"), string("Villas de Suiza"), string("Villas Tec"), string("Monterrey"), string("Monterrey"), string("Nuevo Le�n"), string("Nuevo Le�n"), string("66055"), string("34050"), 30, 20);
	//Paquete paquete1(string("Nallely"),string("Ivan"), string("Villas de Suiza"), string("Villas Tec"), string("Monterrey"), string("Monterrey"), string("Nuevo Le�n"), string("Nuevo Le�n"), string("66055"), string("34050"), 30, 20,10,3);
	//for(int l = 0; l < envios.size(); l++){
	//	cout << "Costo del " << *envios[l] << ": " << envios[l]->costo() << ", Para: " << envios[l]->nombreD << ", De: " << envios[l]->nombreR << "\tDesde: " << envios[l]->ciudadR << "\tCon Codigo Postal: " << envios[l]->cpR << "\tHasta: " << envios[l]->ciudadD << "\tCon Codigo Postal: " << envios[l]->cpD << endl;	
	//}
	for(int l = 0; l < envios.size(); l++){
		cout << "Costo del " << envios[l]->getTipo() << ": " << envios[l]->costo() << ", Para: " << envios[l]->nombreD << ", De: " << envios[l]->nombreR << "\tDesde: " << envios[l]->ciudadR << "\tCon Codigo Postal: " << envios[l]->cpR << "\tHasta: " << envios[l]->ciudadD << "\tCon Codigo Postal: " << envios[l]->cpD << endl;	
	}

	//cout << "Costo del " << sobre1 << ": " << sobre1.costo() << ", Para: " << sobre1.nombreD << ", De: " << sobre1.nombreR << "\tDesde: " << sobre1.ciudadR << "\tCon Codigo Postal: " << sobre1.cpR << "\tHasta: " << sobre1.ciudadD << "\tCon Codigo Postal: " << sobre1.cpD << endl;
	//cout << "Costo del " << paquete1 << ": " << paquete1.costo() << ", Para: " << paquete1.nombreD << ", De: " << paquete1.nombreR << "\tDesde: " << sobre1.ciudadR << "\tCon Codigo Postal: " << sobre1.cpR << "\tHasta: " << sobre1.ciudadD << "\tCon Codigo Postal: " << sobre1.cpD << endl;
	return 0;
}
