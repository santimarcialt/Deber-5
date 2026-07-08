#include<iostream>
using namespace std;

class Vehiculo{
    protected:
        string marca;

    public:
        Vehiculo(string marca){
            this->marca=marca;
        }

        virtual void describir(){
            cout<<"Vehiculo de marca "<<marca<<endl;
        }

        virtual ~Vehiculo(){}
};

class Auto:public Vehiculo{
    private:
        int puertas;

    public:
        Auto(string marca,int puertas):Vehiculo(marca){
            this->puertas=puertas;
        }

        void describir() override{
            cout<<"Auto de marca "<<marca<<" con "<<puertas<<" puertas"<<endl;
        }

        void abrirMaletero(){
            cout<<"Maletero abierto"<<endl;
        }
};

class Camion:public Vehiculo{
    private:
        double toneladas;

    public:
        Camion(string marca,double toneladas):Vehiculo(marca){
            this->toneladas=toneladas;
        }

        void describir() override{
            cout<<"Camion de marca "<<marca<<" con capacidad de "<<toneladas<<" toneladas"<<endl;
        }

        void cargarMercancia(){
            cout<<"Mercancia cargada"<<endl;
        }
};

int main(){
    Auto* auto1=new Auto("Toyota",4);

    auto1->describir();
    auto1->abrirMaletero();

    // a) Con Auto* se puede llamar describir() y abrirMaletero().
    // Esto pasa porque el puntero es de tipo Auto* y conoce los metodos propios de Auto.

    Vehiculo* vehiculo1=auto1;

    vehiculo1->describir();

    // b) Aqui ocurre upcasting: un Auto* se guarda en un Vehiculo*.
    // describir() si funciona porque existe en Vehiculo y es virtual.
    // Como el objeto real sigue siendo Auto, se ejecuta Auto::describir().

    // vehiculo1->abrirMaletero();

    // No se puede llamar abrirMaletero() desde Vehiculo*.
    // Error del compilador:
    // class Vehiculo has no member named abrirMaletero
    // Aunque el objeto real sea Auto, el puntero base Vehiculo* solo permite acceder
    // a metodos declarados en Vehiculo.
    // En el upcasting se conserva el comportamiento polimorfico de los metodos virtuales,
    // pero se pierde el acceso directo a los metodos exclusivos de la clase hija.

    cout<<endl;

    Vehiculo* vehiculos[2];

    vehiculos[0]=new Auto("Chevrolet",2);
    vehiculos[1]=new Camion("Volvo",8.5);

    for(int i=0;i<2;i++){
        vehiculos[i]->describir();
    }

    // c) En el arreglo Vehiculo* se pueden guardar objetos Auto y Camion.
    // La llamada vehiculos[i]->describir() llega a la implementacion correcta
    // porque describir() es virtual.
    // Si el objeto real es Auto, llama a Auto::describir().
    // Si el objeto real es Camion, llama a Camion::describir().

    // vehiculos[0]->abrirMaletero();
    // vehiculos[1]->cargarMercancia();

    // Estas llamadas no funcionan desde Vehiculo* porque abrirMaletero()
    // solo existe en Auto y cargarMercancia() solo existe en Camion.
    // El puntero base solo ve lo que esta declarado en la clase base Vehiculo.

    delete auto1;
    auto1=nullptr;
    vehiculo1=nullptr;

    for(int i=0;i<2;i++){
        delete vehiculos[i];
        vehiculos[i]=nullptr;
    }

    return 0;
}
