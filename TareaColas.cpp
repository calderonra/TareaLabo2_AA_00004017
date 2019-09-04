#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
} * final;

class Cola
{
private:
    Nodo *inicio;

public:
    Nodo *crearNodo(int valor)
    {
        Nodo *n = new Nodo;
        n->dato = valor;
        n->siguiente = nullptr;
        return n;
    }

    Nodo getNodo()
    {
        return *inicio;
    }

    void push(int valor)
    {
        Nodo *n = crearNodo(valor);
        if (!inicio)
        {
            inicio = n;
            final = n;
        }
        else
        {
            final->siguiente = n;
            final = n;
        }
    }

    void pop()
    {

        Nodo *temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }

    void mostrarCola()
    {
        Nodo *temp = inicio;
        if (!inicio)
        {
            cout << "Cola vacia" << endl;
        }
        else
        {
            while (temp)
            {
                cout << temp->dato << ", ";
                temp = temp->siguiente;
            }
        }
    }

    float promedioF()
    {
        float promedio = 0;
        float cont = 0;
        float acum = 0;
        Nodo *temp = inicio;
        Nodo *elfin = final;
        if (!inicio)
        {
            cout << "Cola vacia" << endl;
        }
        else
        {
            while (temp)
            {
                acum = acum + temp->dato;
                temp = temp->siguiente;
                cont++;
                if (temp == elfin)
                {

                    promedio = acum / cont;
                    cout << "El promedio es: " << promedio << endl;
                    return promedio;
                }
            }
        }
    }

    Cola invert(Cola colacao)
    {

        Nodo *temp = inicio;
        Nodo *saltin = final;
        int data = 0;
        if (!inicio)
        {
            cout << "Cola vacia" << endl;
        }
        else
        {
            data = inicio->dato;
            pop();
            colacao = invert(colacao);
            push(data);
            return colacao;
        }
    }
};

void nuevaCola(Cola uno, Cola dos)
{
    int multiplo = 0;
    uno.promedioF() = multiplo;

    Nodo *temp = uno.getNodo();

    while (temp)
    {
        cout << temp->dato << ", ";
        if(temp->dato%multiplo==0){
            dos.push(temp->dato);
        }
        temp = temp->siguiente;
    }
}

int main()
{
    Cola pasty;
    Cola MultiploPromedio;

    pasty.push(5);
    pasty.push(7);
    pasty.push(4);
    pasty.push(6);
    pasty.push(8);
    pasty.push(10);
    pasty.mostrarCola();
    pasty.invert(pasty);
    pasty.mostrarCola();
    pasty.promedioF();
    nuevaCola(pasty,MultiploPromedio);
MultiploPromedio.mostrarCola();

    return 0;
}