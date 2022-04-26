#include <iostream>

class Fecha {
    protected:
        struct _Fecha {
            int day, month, year;
        };
        int diaBisiesto[13] = {0, 31,29,31,30,31,30,31,31,30,31,30,31};
        int diaNoBisiesto[13] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
    public:
        Fecha () {

            _Fecha fechaAct;
            crearFecha(&fechaAct);
            imprimirFecha(&fechaAct);
        }
        int esBisiesto(int _year) {
            if (_year %4 == 0 && (_year %100 == 0 || _year %400 == 0)) {
                return 1;
            } else {
                return 0;
            }
        }
        void crearFecha(_Fecha *date) {
            int boolBisiesto;

            do {
                std::cout << "Ingresar anio: ";
                std::cin >> date->year;
            }while (date->year < 1601);
            boolBisiesto = esBisiesto(date->year);

            do
            {
                std::cout << "Ingresar mes: ";
                std::cin >> date->month;
            } while ( date->month < 1 || date->month > 13);

            if (boolBisiesto == 0) {
                do
                {
                    std::cout << "Ingresar nro de dia: ";
                    std::cin >> date->day;
                } while (date->day < 1 || date->day > diaNoBisiesto[date->day]);

            } else {
                do
                {
                    std::cout << "Ingresar nro de dia: ";
                    std::cin >> date->day;
                } while (date->day < 1 || date->day > diaBisiesto[date->day]);
            }
        }
        void imprimirFecha(_Fecha* f){
            std::cout << "Fecha: " << f->day << "/" << f->month << "/" << f->year << std::endl;
        }
};

class OpFechas: public Fecha {
    _Fecha fecha1;
    _Fecha fecha2;

    public:
        OpFechas (){
            //constructor
        }

        void distanciaEnDias() {
            _Fecha fecha1;
            _Fecha fecha2;
            crearFecha(&fecha1);
            crearFecha(&fecha2);
            int difYears = fecha1.year - fecha2.year ;
            int cantDias = (difYears *365) + (difYears/4) - (difYears/100) + (difYears/400);

            std::cout << "La diferencia entre ambas fechas es de " << cantDias << "dias." << std::endl;
        }

};

class InterfazFecha : public OpFechas {
    public:
        InterfazFecha(){
            int operacion;
            std::cout << "hola";
            operacion = mostrarFunciones();
            operaciones(operacion);
        }

        int mostrarFunciones() {
            int rta;
            std::cout << "Operaciones disponibles:\n";
            std::cout << "1 - Distancia entre fechas.\n";
            std::cout << "\nElegir una opcion: ";
            std::cin >> rta;
            return rta;
        }
        void operaciones(int opcion) {
            switch(opcion) {
                case 1:
                    distanciaEnDias();
                    break;
            }
        }
};

int main() {
    std::cout << "Bienvenido." << std::endl;
    InterfazFecha f;
    return 0;
}
