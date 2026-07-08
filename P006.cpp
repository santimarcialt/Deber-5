#include<iostream>
using namespace std;

class Instrumento{
    public:
        virtual void tocar()=0;
        virtual ~Instrumento(){}
};

class Guitarra:public Instrumento{
    public:
        void tocar() override{
            cout<<"Tañe las cuerdas"<<endl;
        }
};

class Piano:public Instrumento{
    public:
        void tocar() override{
            cout<<"Presiona las teclas"<<endl;
        }
};

class Bateria:public Instrumento{
    public:
        void tocar() override{
            cout<<"Golpea los parches"<<endl;
        }
};

void concierto(Instrumento* i){
    cout<<"[puntero] ";
    i->tocar();
}

void concierto(Instrumento& i){
    cout<<"[referencia] ";
    i.tocar();
}

int main(){
    Instrumento* i1=new Guitarra();
    Instrumento* i2=new Piano();
    Instrumento* i3=new Bateria();

    concierto(i1);
    concierto(i2);
    concierto(i3);

    delete i1;
    delete i2;
    delete i3;

    i1=nullptr;
    i2=nullptr;
    i3=nullptr;

    Guitarra g;
    Piano p;
    Bateria b;

    concierto(g);
    concierto(p);
    concierto(b);

    return 0;
}
