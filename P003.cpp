#include<iostream>
using namespace std;

class Animal{
    public:
        virtual void hacerSonido()=0;
        virtual ~Animal(){}
};

class Perro:public Animal{
    public:
        void hacerSonido() override{
            cout<<"Guau!"<<endl;
        }
};

class Gato:public Animal{
    public:
        void hacerSonido() override{
            cout<<"Miau!"<<endl;
        }
};

class Vaca:public Animal{
    public:
        void hacerSonido() override{
            cout<<"Muuu!"<<endl;
        }
};

class Pato:public Animal{
    public:
        void hacerSonido() override{
            cout<<"Cuac!"<<endl;
        }
};

int main(){
    Animal* animales[4];

    animales[0]=new Perro();
    animales[1]=new Gato();
    animales[2]=new Vaca();
    animales[3]=new Perro();

    for(int i=0;i<4;i++){
        animales[i]->hacerSonido();
    }

    for(int i=0;i<4;i++){
        delete animales[i];
        animales[i]=nullptr;
    }

    return 0;
} 

// Sin polimorfismo: else if(tipo=="pato") cout<<"Cuac!"<<endl; 
/* Con polimorfismo: class Pato:public Animal{
    public:
        void hacerSonido() override{
            cout<<"Cuac!"<<endl;
        }
};*/ 
//Porque se puede usar Animal* para acceder al metodo reescrito de pato
