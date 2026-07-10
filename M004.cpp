#include<iostream>
using namespace std;

class Animal{
    protected:
        string nombre;

    public:
        Animal(string n):nombre(n){}

        virtual string sonido() const=0;
        virtual string especie() const=0;

        virtual void describir() const{
            cout<<"["<<especie()<<"] "<<nombre<<" dice: "<<sonido()<<endl;
        }

        virtual ~Animal(){}
};

class Leon:public Animal{
    public:
        Leon(string n):Animal(n){}

        string sonido() const override{
            return "Roar";
        }

        string especie() const override{
            return "Felino";
        }
};

class Aguila:public Animal{
    public:
        Aguila(string n):Animal(n){}

        string sonido() const override{
            return "Squak";
        }

        string especie() const override{
            return "Ave";
        }
};

class Serpiente:public Animal{
    public:
        Serpiente(string n):Animal(n){}

        string sonido() const override{
            return "Ssss";
        }

        string especie() const override{
            return "Reptil";
        }
};

class Zoologico{
    private:
        Animal** animales;
        int capacidad;
        int cantidad;

    public:
        Zoologico(int cap){
            capacidad=cap;
            cantidad=0;
            animales=new Animal*[capacidad];

            for(int i=0;i<capacidad;i++){
                animales[i]=nullptr;
            }
        }

        ~Zoologico(){
            for(int i=0;i<cantidad;i++){
                delete animales[i];
                animales[i]=nullptr;
            }

            delete[] animales;
            animales=nullptr;
        }

        void agregar(Animal* a){
            if(cantidad<capacidad){
                animales[cantidad]=a;
                cantidad++;
            }else{
                delete a;
            }
        }

        void listar() const{
            for(int i=0;i<cantidad;i++){
                animales[i]->describir();
            }
        }

        int contarEspecie(string esp) const{
            int contador=0;

            for(int i=0;i<cantidad;i++){
                if(animales[i]->especie()==esp){
                    contador++;
                }
            }

            return contador;
        }
};

int main(){
    Zoologico zoo(5);

    zoo.agregar(new Leon("Simba"));
    zoo.agregar(new Aguila("Zeus"));
    zoo.agregar(new Leon("Nala"));
    zoo.agregar(new Serpiente("Kaa"));

    zoo.listar();

    cout<<"Felinos: "<<zoo.contarEspecie("Felino")<<endl;

    return 0;
}
