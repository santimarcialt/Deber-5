#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

class Figura{
    public:
        virtual double area()=0;
        virtual double perimetro()=0;
        virtual void imprimir() const=0;
        virtual ~Figura(){}
};

class Circulo:public Figura{
    private:
        double radio;

    public:
        Circulo(double radio){
            this->radio=radio;
        }

        double area() override{
            return 3.14159*radio*radio;
        }

        double perimetro() override{
            return 2*3.14159*radio;
        }

        void imprimir() const override{
            Circulo* c=(Circulo*)this;
            cout<<"Circulo    : area="<<fixed<<setprecision(2)<<c->area()<<"  perim="<<c->perimetro()<<endl;
        }
};

class Cuadrado:public Figura{
    private:
        double lado;

    public:
        Cuadrado(double lado){
            this->lado=lado;
        }

        double area() override{
            return lado*lado;
        }

        double perimetro() override{
            return 4*lado;
        }

        void imprimir() const override{
            Cuadrado* c=(Cuadrado*)this;
            cout<<"Cuadrado   : area="<<fixed<<setprecision(2)<<c->area()<<"  perim="<<c->perimetro()<<endl;
        }
};

class TrianguloR:public Figura{
    private:
        double cateto1;
        double cateto2;
        double hipotenusa;

    public:
        TrianguloR(double cateto1,double cateto2){
            this->cateto1=cateto1;
            this->cateto2=cateto2;
            hipotenusa=sqrt(cateto1*cateto1+cateto2*cateto2);
        }

        double area() override{
            return cateto1*cateto2/2;
        }

        double perimetro() override{
            return cateto1+cateto2+hipotenusa;
        }

        void imprimir() const override{
            TrianguloR* t=(TrianguloR*)this;
            cout<<"TrianguloR : area="<<fixed<<setprecision(2)<<t->area()<<"  perim="<<t->perimetro()<<endl;
        }
};

int main(){
    Figura* figuras[5];

    figuras[0]=new Circulo(5);
    figuras[1]=new Cuadrado(5);
    figuras[2]=new TrianguloR(3,4);
    figuras[3]=new Circulo(2);
    figuras[4]=new Cuadrado(3);

    for(int i=0;i<5;i++){
        figuras[i]->imprimir();
    }

    for(int i=0;i<5;i++){
        delete figuras[i];
        figuras[i]=nullptr;
    }

    return 0;
}
