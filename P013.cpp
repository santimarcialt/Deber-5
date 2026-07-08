#include<iostream>
using namespace std;

class Logger{
    public:
        virtual void log(string mensaje){
            cout<<"[LOG] "<<mensaje<<endl;
        }

        virtual ~Logger(){}
};

class LoggerFecha:public Logger{
    public:
        void log(string mensaje) override{
            Logger::log(mensaje);
            cout<<"[FECHA] 2024-01-01"<<endl;
        }
};

class LoggerCompleto:public LoggerFecha{
    public:
        void log(string mensaje) override{
            LoggerFecha::log(mensaje);
            cout<<"[NIVEL] INFO"<<endl;
        }
};

int main(){
    Logger l1;
    LoggerFecha l2;
    LoggerCompleto l3;

    cout<<"-- Logger base:"<<endl;
    l1.log("Sistema iniciado");

    cout<<endl;

    cout<<"-- LoggerFecha:"<<endl;
    l2.log("Sistema iniciado");

    cout<<endl;

    cout<<"-- LoggerCompleto:"<<endl;
    l3.log("Sistema iniciado");

    return 0;
}
