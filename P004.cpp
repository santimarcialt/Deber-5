#include<iostream>
#include<iomanip>
using namespace std;

class Empleado{
    protected:
        string nombre;
        double salario;

    public:
        Empleado(string nombre,double salario){
            this->nombre=nombre;
            this->salario=salario;
        }

        string getNombre(){
            return nombre;
        }

        virtual string tipo()=0;
        virtual double calcularPago()=0;

        virtual ~Empleado(){}
};

class EmpleadoTC:public Empleado{
    public:
        EmpleadoTC(string nombre,double salario):Empleado(nombre,salario){}

        string tipo() override{
            return "TC";
        }

        double calcularPago() override{
            return salario;
        }
};

class EmpleadoFL:public Empleado{
    private:
        double horas;
        double tarifa;

    public:
        EmpleadoFL(string nombre,double horas,double tarifa):Empleado(nombre,0){
            this->horas=horas;
            this->tarifa=tarifa;
        }

        string tipo() override{
            return "FL";
        }

        double calcularPago() override{
            return horas*tarifa;
        }
};

void mostrarPago(Empleado* e){
    cout<<fixed<<setprecision(2);
    cout<<e->getNombre()<<" ["<<e->tipo()<<"]: $"<<e->calcularPago()<<endl;
}

int main(){
    Empleado* e1=new EmpleadoTC("Ana",3500.0);
    Empleado* e2=new EmpleadoFL("Luis",60,20.0);

    mostrarPago(e1);
    mostrarPago(e2);

    delete e1;
    delete e2;

    e1=nullptr;
    e2=nullptr;

    return 0;
}
