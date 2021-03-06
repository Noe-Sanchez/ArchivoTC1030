#include <iostream>
#include <tuple>
#include <string>
#include <cstddef>
#include <type_traits>
#include <utility>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Video{
    protected:
        tuple<int,string,string>* data;
    public:
        virtual string getData() = 0;
        virtual tuple<int,string,string>* getPtr(){
            return data;
        }
        virtual void setTemp(int _temp) =0;
        virtual void setDuracion(float _duracion)=0;
        virtual void setCali(float _cali)=0;
        virtual float getCali()=0;
        virtual void addEpisodio(tuple<int,string,string, float, float, int>* epi)=0;
        virtual vector<tuple<int,string,string, float, float, int>*> getEpisodio()=0;
};

class Pelicula:public Video{
    private:
        float cali, duracion;
    public:
        Pelicula(){
            data = new tuple<int,string,string>(0,"","");
            cali = 0; duracion = 0;
        }
        Pelicula(int id, string nombre, string genero,float _duracion, float _cali){
            data = new tuple<int,string,string>(id,nombre,genero);
            cali = _cali;
            duracion = _duracion;
        }
        string getData(){
            string out = to_string(get<0>(*data)) + ", " + get<1>(*data) + ", " + 
            get<2>(*data) + ", " + to_string(duracion)  + ", " + to_string(cali);
            return (out);
        }
        void setCali(float _cali){
            cali = _cali;
        }
        void setDuracion(float _duracion){
            duracion = _duracion;
        }
        float getCali(){
            return cali;
        }
        void setTemp(int _temp){}
        void addEpisodio(tuple<int,string,string, float, float, int>* epi){}
        vector<tuple<int,string,string, float, float, int>*> getEpisodio(){}
};

class Serie:public Video{
    private:
        int temp;
        vector<tuple<int,string,string, float, float, int>*> episodios;
    public:
        Serie(){
            data = new tuple<int,string,string>(0,"","");
            temp = 0;
        }
        Serie(int id, string nombre, string genero, int _temp){
            data = new tuple<int,string,string>(id,nombre,genero);
            temp = _temp;
        }
        string getData(){
            string out = to_string(get<0>(*data)) + ", " + get<1>(*data) + ", " + 
            get<2>(*data) + ", " + to_string(temp);
            string out2 = "\nEpisodios: ";
            for(int e = 0; e < episodios.size();e++){
                out2 += "\n     ->" + get<2>(*episodios[e]) + ", " + to_string(get<4>(*episodios[e]));
            }
            return (out+out2);
        }
        void setTemp(int _temp){
            temp = _temp;
        }
        void addEpisodio(tuple<int,string,string, float, float, int>* epi){
            episodios.push_back(epi);
        }
        vector<tuple<int,string,string, float, float, int>*> getEpisodio(){
            return episodios;
        }
        void setCali(float _cali){}
        void setDuracion(float _duracion){}
        float getCali(){return 0;}
};

void leerArchivos(vector<Video*> &catalogo){
    ifstream input;
    input.open("pelis.csv");
    string renglon_s;

    int i = 0;
    while(getline(input, renglon_s)){
            
        stringstream renglon(renglon_s);
        string celda;
            
        catalogo.push_back(new Pelicula());
        int j = 0;
        while(getline(renglon, celda,',')){
                switch(j++){                    
                case 0:
                    get<0>(*catalogo[i]->getPtr()) = stoi(celda, nullptr,10);
                    break;
                case 1:
                    get<1>(*catalogo[i]->getPtr()) = celda;
                    break;
                case 2:
                    //cout << catalogo[i]->getCali() << endl;
                    catalogo[i]->setDuracion(stof(celda));
                    //cout << catalogo[i]->getCali() << endl;
                    break;
                case 3:
                    get<2>(*catalogo[i]->getPtr()) = celda;
                    break;
                case 4:
                    catalogo[i]->setCali(stof(celda));
                    break;
            }
        }
        i++;
    }
    input.close();

    input.open("series.csv");
    while(getline(input, renglon_s)){
        stringstream renglon(renglon_s);
        string celda;

        catalogo.push_back(new Serie());
        int j = 0;
        
        while(getline(renglon, celda,',')){
            switch(j++){
                case 0:
                    get<0>(*catalogo[i]->getPtr()) = stoi(celda, nullptr,10);
                    break;
                case 1:
                    get<1>(*catalogo[i]->getPtr()) = celda;
                    break;
                case 2:
                    get<2>(*catalogo[i]->getPtr()) = celda;
                    break;
                case 3:
                    catalogo[i]->setTemp(stoi(celda, nullptr, 10));
                    break;    
            }
        }
        i++;
    }
    input.close();

    input.open("epis.csv");
    while(getline(input, renglon_s)){
            
        stringstream renglon(renglon_s);
        string celda;
        
        tuple<int,string,string, float, float, int>* v_epi = new tuple<int,string,string, float, float, int>(0,"","",0,0,0);
        int j = 0;
        while(getline(renglon, celda,',')){
            switch(j++){
                case 0:
                    get<0>(*v_epi) = stoi(celda, nullptr,10);
                    break;
                case 1:
                    get<1>(*v_epi) = celda;
                    break;
                case 2:
                    get<2>(*v_epi) = celda;
                    break;
                case 3:
                    get<3>(*v_epi) = stof(celda);
                    break;
                case 4:
                    get<4>(*v_epi) = stof(celda);
                    break;
                case 5:
                    get<5>(*v_epi) = stoi(celda, nullptr,10);
                    break;
            }
        }
        for(int l = 0; l < catalogo.size();l++){
            if(stoi(get<1>(*v_epi).substr(0,8), nullptr,10) == get<0>(*catalogo[l]->getPtr())){
                catalogo[l]->addEpisodio(v_epi);    
                    //cout << "a??adio episodio" << endl;
            }
        }
    }
    input.close();
}

void printVideos(vector<Video*> &catalogo){
    for(int n = 0; n < catalogo.size(); n++){
        cout << catalogo[n]->getData() << endl;
    }
}

void pelisxCali(vector<Video*> &catalogo, float qcali){
    for(int n = 0; n < catalogo.size(); n++){
        if(catalogo[n]->getCali() == qcali){
            cout << "Pelicula: " << get<1>(*catalogo[n]->getPtr()) << endl;
        }
    }
}
void vidsxCalioGenero(vector<Video*> &catalogo, float query){
    for(int n = 0; n < catalogo.size(); n++){
        if(catalogo[n]->getCali() == 0){
            auto vvect = catalogo[n]->getEpisodio();
            for(int k = 0; k < vvect.size(); k++){
                if (get<4>(*vvect[k]) == query ){
                    cout << get<2>(*vvect[k]) << endl;
                }
            }
        }else{
            if(catalogo[n]->getCali() == query){
                cout << get<1>(*catalogo[n]->getPtr()) << endl;
            }
        }
    }
}
void vidsxCalioGenero(vector<Video*> &catalogo, string query){
    for(int n = 0; n < catalogo.size(); n++){
        if(get<2>(*catalogo[n]->getPtr()) == query){
            cout << get<1>(*catalogo[n]->getPtr()) << endl;
        }
    }
}
void epixCali(vector<Video*> &catalogo, float query){
    for(int n = 0; n < catalogo.size(); n++){
        if(catalogo[n]->getCali() == 0){
            auto vvect = catalogo[n]->getEpisodio();
            for(int k = 0; k < vvect.size(); k++){
                if (get<4>(*vvect[k]) == query ){
                    cout << "Episodio: " << get<2>(*vvect[k]) << endl;
                }
            }
        }
    }
}
void calificarVideo(vector<Video*> &catalogo, string qtitulo,float qcali){
    for(int n = 0; n < catalogo.size(); n++){
        if(catalogo[n]->getCali() == 0){
            auto vvect = catalogo[n]->getEpisodio();
            for(int k = 0; k < vvect.size(); k++){
                if (get<2>(*vvect[k]) == qtitulo ){
                    get<4>(*vvect[k]) = qcali;
                }
            }
        }else{
            if (get<1>(*catalogo[n]->getPtr()) == qtitulo){    
                catalogo[n]->setCali(qcali);
            }
        }
    }
}

int main(){
    /*Pelicula peli(1298723, "Peli de prueba", "Drama", 46, 9.5);
    Serie serie(1298723, "Serie de prueba", "Suspenso", 2);

    cout << "Hello world: Pelicula" << endl;
    cout << "Datos peli: " << peli.getData() << endl;
    cout << "Datos serie: " << serie.getData() << endl;
    Pelicula* peliptr = &peli; 
    */
    vector<Video*> catalogo;

    int query = 0; bool boolvar = true;
    while(boolvar){
        cout << "1.Cargar archivos.csv\n2.Mostrar video con calificacion o genero\n3.Mostrar episodios por calificacion\n4.Mostrar peliculas con cierta calificacion\n5.Calificar video\n6.Mostrar videos\n7.Salir" << endl;
        cin >> query;
        switch(query){
            case 1:
                leerArchivos(catalogo);
                cout << "Se leyeron les archives" << endl;
                break;
            case 2:{
                cout << "1.Genero\n2.Calificacion" << endl;

                int opt;
                cin >> opt;

                if(opt == 1){
                    cout << "Genero a buscar: ";
                    string query;
                    cin >> query;
                    vidsxCalioGenero(catalogo,query);
                }else if(opt == 2){
                    cout << "Calificacion a buscar: ";
                    float query;
                    cin >> query;
                    vidsxCalioGenero(catalogo,query);
                }else{
                    cout << "Opcion invalida" << endl;
                }   
                break;
            }
            case 3:
                cout << "Calificacion a buscar: ";
                float query;
                cin >> query;
                epixCali(catalogo,query);
                break;
            case 4:
                cout << "Calificacion a buscar: ";
                float qcali;
                cin >> qcali;
                pelisxCali(catalogo, qcali);
                break;
            case 5:{
                cout << "Titulo a calificar: ";
                string qtitulo = "";
                cin.ignore();
                getline(cin, qtitulo);
                cout << "Nueva calificacion: ";
                float qcali;
                cin >> qcali;

                calificarVideo(catalogo, qtitulo, qcali);
                break;
            }
            case 6:
                printVideos(catalogo);
                break;
            case 7:
                boolvar = false;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }

    //cout << "eof" << endl;
    return 0;

}