#include<iostream>
using namespace std;

class Empleado{
    protected:
        string nombre;

    public:
        Empleado(string nombre){
            this->nombre=nombre;
        }

        string getNombre(){
            return nombre;
        }

        virtual void trabajar(){
            cout<<nombre<<" trabaja."<<endl;
        }

        virtual ~Empleado(){}
};

class Programador:public Empleado{
    private:
        string lenguaje;

    public:
        Programador(string nombre,string lenguaje):Empleado(nombre){
            this->lenguaje=lenguaje;
        }

        void escribirCodigo(){
            cout<<nombre<<" escribe codigo en "<<lenguaje<<endl;
        }
};

class Disenador:public Empleado{
    private:
        string herramienta;

    public:
        Disenador(string nombre,string herramienta):Empleado(nombre){
            this->herramienta=herramienta;
        }

        void crearMockup(){
            cout<<nombre<<" crea mockup en "<<herramienta<<endl;
        }
};

class Gerente:public Empleado{
    private:
        string departamento;

    public:
        Gerente(string nombre,string departamento):Empleado(nombre){
            this->departamento=departamento;
        }
};

void asignarTarea(Empleado* e){
    Programador* p=dynamic_cast<Programador*>(e);

    if(p!=nullptr){
        p->escribirCodigo();
        return;
    }

    Disenador* d=dynamic_cast<Disenador*>(e);

    if(d!=nullptr){
        d->crearMockup();
        return;
    }

    cout<<"Tarea generica."<<endl;
}

int main(){
    Empleado* empleados[3];

    empleados[0]=new Programador("Ana","C++");
    empleados[1]=new Disenador("Luis","Figma");
    empleados[2]=new Gerente("Carla","Ventas");

    for(int i=0;i<3;i++){
        asignarTarea(empleados[i]);
    }

    for(int i=0;i<3;i++){
        delete empleados[i];
        empleados[i]=nullptr;
    }

    return 0;
}
