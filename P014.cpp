#include<iostream>
#include<iomanip>
using namespace std;

class Mascota{
    protected:
        string nombre;
        double precio;

    public:
        Mascota(string nombre,double precio){
            this->nombre=nombre;
            this->precio=precio;
        }

        virtual string tipo() const=0;
        virtual string sonido() const=0;

        virtual void describir() const{
            cout<<fixed<<setprecision(2);
            cout<<"["<<tipo()<<"] "<<nombre<<" - $"<<precio<<" - "<<sonido()<<endl;
        }

        virtual ~Mascota(){}
};

class Perro:public Mascota{
    private:
        string raza;

    public:
        Perro(string nombre,string raza,double precio):Mascota(nombre,precio){
            this->raza=raza;
        }

        string tipo() const override{
            return "Perro";
        }

        string sonido() const override{
            return "Guau!";
        }

        void describir() const override{
            cout<<fixed<<setprecision(2);
            cout<<"["<<tipo()<<"] "<<nombre<<" ("<<raza<<") - $"<<precio<<" - "<<sonido()<<endl;
        }
};

class Gato:public Mascota{
    private:
        string colorOjos;

    public:
        Gato(string nombre,string colorOjos,double precio):Mascota(nombre,precio){
            this->colorOjos=colorOjos;
        }

        string tipo() const override{
            return "Gato";
        }

        string sonido() const override{
            return "Miau!";
        }

        void describir() const override{
            cout<<fixed<<setprecision(2);
            cout<<"["<<tipo()<<"] "<<nombre<<" ("<<colorOjos<<") - $"<<precio<<" - "<<sonido()<<endl;
        }
};

class Conejo:public Mascota{
    private:
        double pesoKg;

    public:
        Conejo(string nombre,double pesoKg,double precio):Mascota(nombre,precio){
            this->pesoKg=pesoKg;
        }

        string tipo() const override{
            return "Conejo";
        }

        string sonido() const override{
            return "Sniff!";
        }

        void describir() const override{
            cout<<fixed<<setprecision(2);
            cout<<"["<<tipo()<<"] "<<nombre<<" ("<<pesoKg<<" kg) - $"<<precio<<" - "<<sonido()<<endl;
        }
};

int main(){
    Mascota** mascotas=new Mascota*[10];
    int cantidad=0;
    int opcion;

    for(int i=0;i<10;i++){
        mascotas[i]=nullptr;
    }

    do{
        cout<<"=== TIENDA DE MASCOTAS ==="<<endl;
        cout<<"1. Agregar  2. Listar  3. Buscar  4. Salir"<<endl;
        cout<<"> ";
        cin>>opcion;

        if(opcion==1){
            if(cantidad>=10){
                cout<<"No hay espacio disponible."<<endl;
            }else{
                string tipo;
                string nombre;
                double precio;

                cout<<"Tipo (perro/gato/conejo): ";
                cin>>tipo;

                if(tipo=="perro"){
                    string raza;

                    cout<<"Nombre: ";
                    cin>>nombre;
                    cout<<"Raza: ";
                    cin>>raza;
                    cout<<"Precio: ";
                    cin>>precio;

                    mascotas[cantidad]=new Perro(nombre,raza,precio);
                    cantidad++;
                }else if(tipo=="gato"){
                    string colorOjos;

                    cout<<"Nombre: ";
                    cin>>nombre;
                    cout<<"Color ojos: ";
                    cin>>colorOjos;
                    cout<<"Precio: ";
                    cin>>precio;

                    mascotas[cantidad]=new Gato(nombre,colorOjos,precio);
                    cantidad++;
                }else if(tipo=="conejo"){
                    double pesoKg;

                    cout<<"Nombre: ";
                    cin>>nombre;
                    cout<<"Peso kg: ";
                    cin>>pesoKg;
                    cout<<"Precio: ";
                    cin>>precio;

                    mascotas[cantidad]=new Conejo(nombre,pesoKg,precio);
                    cantidad++;
                }else{
                    cout<<"Tipo invalido."<<endl;
                }
            }
        }else if(opcion==2){
            for(int i=0;i<cantidad;i++){
                mascotas[i]->describir();
            }
        }else if(opcion==3){
            string tipo;
            bool encontrado=false;

            cout<<"Buscar tipo: ";
            cin>>tipo;

            for(int i=0;i<cantidad;i++){
                if(tipo=="perro"){
                    Perro* p=dynamic_cast<Perro*>(mascotas[i]);

                    if(p!=nullptr){
                        p->describir();
                        encontrado=true;
                    }
                }else if(tipo=="gato"){
                    Gato* g=dynamic_cast<Gato*>(mascotas[i]);

                    if(g!=nullptr){
                        g->describir();
                        encontrado=true;
                    }
                }else if(tipo=="conejo"){
                    Conejo* c=dynamic_cast<Conejo*>(mascotas[i]);

                    if(c!=nullptr){
                        c->describir();
                        encontrado=true;
                    }
                }
            }

            if(!encontrado){
                cout<<"No hay mascotas de ese tipo."<<endl;
            }
        }else if(opcion==4){
            for(int i=0;i<cantidad;i++){
                delete mascotas[i];
                mascotas[i]=nullptr;
            }

            delete[] mascotas;
            mascotas=nullptr;

            cout<<"Hasta luego. Memoria liberada."<<endl;
        }else{
            cout<<"Opcion invalida."<<endl;
        }

    }while(opcion!=4);

    return 0;
}
