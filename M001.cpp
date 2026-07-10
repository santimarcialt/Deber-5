#include<iostream>
#include<iomanip>
using namespace std;

class Sensor{
    private:
        double* lecturas;
        int n;

    public:
        Sensor(int n){
            this->n=n;
            lecturas=new double[n];

            for(int i=0;i<n;i++){
                lecturas[i]=0;
            }
        }

        virtual ~Sensor(){
            cout<<"~Sensor: liberando lecturas"<<endl;
            delete[] lecturas;
            lecturas=nullptr;
        }

        void setLectura(int i,double val){
            if(i>=0 && i<n){
                lecturas[i]=val;
            }
        }

        double getLectura(int i) const{
            if(i>=0 && i<n){
                return lecturas[i];
            }

            return 0;
        }

        int getN() const{
            return n;
        }

        virtual void imprimir() const=0;
        virtual string tipo() const=0;
};

class SensorTemperatura:public Sensor{
    private:
        string* etiquetas;

    public:
        SensorTemperatura(int n):Sensor(n){
            etiquetas=new string[n];

            for(int i=0;i<n;i++){
                etiquetas[i]="";
            }
        }

        ~SensorTemperatura(){
            cout<<"~SensorTemperatura: liberando etiquetas"<<endl;
            delete[] etiquetas;
            etiquetas=nullptr;
        }

        void setEtiqueta(int i,string e){
            if(i>=0 && i<getN()){
                etiquetas[i]=e;
            }
        }

        string tipo() const override{
            return "Temperatura";
        }

        void imprimir() const override{
            cout<<fixed<<setprecision(2);

            for(int i=0;i<getN();i++){
                cout<<etiquetas[i]<<": "<<getLectura(i)<<endl;
            }
        }
};

int main(){
    SensorTemperatura st(3);

    st.setLectura(0,22.5);
    st.setEtiqueta(0,"Sala");

    st.setLectura(1,18.0);
    st.setEtiqueta(1,"Cocina");

    st.setLectura(2,25.3);
    st.setEtiqueta(2,"Patio");

    Sensor* s=&st;

    s->imprimir();

    cout<<"Tipo: "<<s->tipo()<<endl;

    return 0;
}
