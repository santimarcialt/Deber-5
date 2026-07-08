#include<iostream>
#include<iomanip>
using namespace std;

class MedioPago{
    public:
        virtual void procesar(double monto)=0;
        virtual bool fueExitoso()=0;
        virtual void imprimirComprobante(double monto)=0;
        virtual ~MedioPago(){}
};

class TarjetaCredito:public MedioPago{
    private:
        string codigo;
        bool exitoso;

    public:
        TarjetaCredito(string codigo){
            this->codigo=codigo;
            exitoso=false;
        }

        void procesar(double monto) override{
            exitoso=true;
            cout<<"[Tarjeta] Procesando $"<<fixed<<setprecision(2)<<monto<<"... Aprobado."<<endl;
        }

        bool fueExitoso() override{
            return exitoso;
        }

        void imprimirComprobante(double monto) override{
            if(exitoso){
                cout<<"Comprobante: "<<codigo<<" $"<<fixed<<setprecision(2)<<monto<<endl;
            }
        }
};

class Transferencia:public MedioPago{
    private:
        string codigo;
        bool exitoso;

    public:
        Transferencia(string codigo){
            this->codigo=codigo;
            exitoso=false;
        }

        void procesar(double monto) override{
            exitoso=true;
            cout<<"[Transferencia] Procesando $"<<fixed<<setprecision(2)<<monto<<"... Aprobado."<<endl;
        }

        bool fueExitoso() override{
            return exitoso;
        }

        void imprimirComprobante(double monto) override{
            if(exitoso){
                cout<<"Comprobante: "<<codigo<<" $"<<fixed<<setprecision(2)<<monto<<endl;
            }
        }
};

class Efectivo:public MedioPago{
    private:
        string codigo;
        bool exitoso;

    public:
        Efectivo(string codigo){
            this->codigo=codigo;
            exitoso=false;
        }

        void procesar(double monto) override{
            exitoso=true;
            cout<<"[Efectivo] Procesando $"<<fixed<<setprecision(2)<<monto<<"... Aprobado."<<endl;
        }

        bool fueExitoso() override{
            return exitoso;
        }

        void imprimirComprobante(double monto) override{
            if(exitoso){
                cout<<"Comprobante: "<<codigo<<" $"<<fixed<<setprecision(2)<<monto<<endl;
            }
        }
};

int main(){
    MedioPago* pagos[3];

    pagos[0]=new TarjetaCredito("TC-****1234");
    pagos[1]=new Transferencia("TR-001");
    pagos[2]=new Efectivo("EF-001");

    double montos[3]={150.0,500.0,20.0};

    for(int i=0;i<3;i++){
        pagos[i]->procesar(montos[i]);
        pagos[i]->imprimirComprobante(montos[i]);
    }
    
    for(int i=0;i<3;i++){
        delete pagos[i];
        pagos[i]=nullptr;
    }

    return 0;
    // d) La ventaja de usar MedioPago como interfaz es que el main trabaja
    // con MedioPago*, no con clases concretas.
    // Si mañana se agrega Criptomoneda, solo se crea una nueva clase hija
    // que implemente procesar(), fueExitoso() e imprimirComprobante().
    // No es necesario cambiar la logica principal del sistema.
}
