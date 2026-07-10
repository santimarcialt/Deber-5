#include<iostream>
using namespace std;

class Cancion{
    public:
        string titulo;
        string artista;

        Cancion(string t,string a):titulo(t),artista(a){}
};

class Playlist{
    private:
        Cancion** canciones;
        int capacidad;
        int cantidad;

        void expandir(){
            int nuevaCapacidad=capacidad*2;
            Cancion** nuevo=new Cancion*[nuevaCapacidad];

            for(int i=0;i<cantidad;i++){
                nuevo[i]=canciones[i];
            }

            for(int i=cantidad;i<nuevaCapacidad;i++){
                nuevo[i]=nullptr;
            }

            delete[] canciones;

            canciones=nuevo;
            capacidad=nuevaCapacidad;

            cout<<"Playlist expandida a "<<capacidad<<endl;
        }

    public:
        Playlist(int capInicial){
            capacidad=capInicial;
            cantidad=0;
            canciones=new Cancion*[capacidad];

            for(int i=0;i<capacidad;i++){
                canciones[i]=nullptr;
            }
        }

        ~Playlist(){
            for(int i=0;i<cantidad;i++){
                delete canciones[i];
                canciones[i]=nullptr;
            }

            delete[] canciones;
            canciones=nullptr;
        }

        void agregar(string titulo,string artista){
            if(cantidad==capacidad){
                expandir();
            }

            canciones[cantidad]=new Cancion(titulo,artista);
            cantidad++;
        }

        void imprimir() const{
            for(int i=0;i<cantidad;i++){
                cout<<i+1<<". "<<canciones[i]->titulo<<" - "<<canciones[i]->artista<<endl;
            }
        }
};

int main(){
    Playlist p1(2);

    p1.agregar("titulo1","artista1");
    p1.agregar("titulo2","artista2");
    p1.agregar("titulo3","artista3");
    p1.agregar("titulo4","artista4");
    p1.agregar("titulo5","artista5");

    p1.imprimir();

    return 0;
}
