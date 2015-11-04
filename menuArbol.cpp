#include <iostream>
#include <cstdlib>
using namespace std;

class Nodo{
    int dato;
    Nodo *izquierda;
    Nodo *derecha;
    friend class Arbol;
};

class Arbol{
private:
    Nodo *raiz;
public:
    Arbol();
    int vacio(Nodo *r);
    void insertar(int x, Nodo *&apuntador);
    void infijo(Nodo *apuntador);
    void preOrden(Nodo *apuntador);
    void postOrden(Nodo *apuntador);
    Nodo * apuntadorRaiz();
    int contar(Nodo *arbol1);
    int altura(Nodo *apuntador);
    int sumar(Nodo *apuntador);
    int numeroHojas(Nodo *apuntador);
    int menor(Nodo *apuntador);
    void eliminar(Nodo *&apuntador, int nodo);

};

Arbol::Arbol(){
    raiz = NULL;
}

int Arbol::vacio(Nodo *r){
    return r == NULL;
}

void Arbol::insertar(int dato1, Nodo *&apuntador){
    if (apuntador == NULL){
        apuntador = new Nodo();
        apuntador -> dato = dato1;
        apuntador -> izquierda = NULL;
        apuntador -> derecha = NULL;
        if(raiz == NULL){
            raiz = apuntador;
        }
    }
    else if (dato1 < apuntador -> dato){
        insertar(dato1, apuntador -> izquierda);
    }
    else if (dato1 > apuntador -> dato){
        insertar(dato1, apuntador -> derecha);
    }
    else{
        cout <<"\nEl dato ya existe.";
    }
}

void Arbol::infijo(Nodo *apuntador){
    if (apuntador == NULL){
        cout <<"\nNo hay árbol.";
    }
    if (apuntador -> izquierda != NULL){
        infijo(apuntador -> izquierda);
    }
    cout << apuntador -> dato <<" ";
    if (apuntador -> derecha != NULL){
        infijo(apuntador -> derecha);
    }
}

void Arbol::preOrden(Nodo *apuntador){
    if (apuntador == NULL){
        cout <<"\nNo hay árbol.";
    }
    cout << apuntador -> dato <<" ";
    if (apuntador -> izquierda != NULL){
        preOrden(apuntador -> izquierda);
    }
    if (apuntador -> derecha != NULL){
        preOrden(apuntador -> derecha);
    }
}

void Arbol::postOrden(Nodo *apuntador){
    if (apuntador == NULL){
        cout <<"\nNo hay árbol.";
    }
    if (apuntador -> izquierda != NULL){
        preOrden(apuntador -> izquierda);
    }
    if (apuntador -> derecha != NULL){
        preOrden(apuntador -> derecha);
    }
    cout << apuntador -> dato <<" ";
}

Nodo *Arbol::apuntadorRaiz(){
    return raiz;
}

int Arbol::contar(Nodo *apuntador){
    if (apuntador == NULL){
        return 0;
    }
    else{
        return (1 + contar(apuntador -> derecha) + contar(apuntador -> izquierda));
    }
}

int Arbol::altura(Nodo *apuntador){
    if (apuntador == NULL){
        return 0;
    }
    int alturaIzquierda = altura(apuntador -> izquierda);
    int alturaDerecha = altura(apuntador -> derecha);
    if (alturaIzquierda > alturaDerecha){
        return alturaIzquierda + 1;
    }
    else{
        return alturaDerecha + 1;
    }
}

int Arbol::sumar(Nodo *apuntador){
    if (apuntador == NULL){
        return 0;
    }
    else{
        return apuntador -> dato + sumar(apuntador -> derecha) + sumar(apuntador -> izquierda);
    }
}

int Arbol::numeroHojas(Nodo *apuntador){
    if (apuntador == NULL){
        return 0;
    }
    if ((apuntador -> derecha == NULL)&&(apuntador -> izquierda == NULL)){
        return 1;
    }
    else{
        return numeroHojas(apuntador -> izquierda) + numeroHojas(apuntador -> derecha);
    }
}

int Arbol::menor(Nodo *apuntador){
    if (apuntador == NULL){
        return 0;
    }
    if (apuntador -> izquierda != NULL){
        return menor(apuntador -> izquierda);
    }
    return apuntador -> dato;
}

void Arbol::eliminar(Nodo *&apuntador, int nodo){
    Nodo *auxiliar;
    if (apuntador == NULL) {
        cout <<"\nÁrbol vacío.";
    }
    if (nodo == apuntador -> dato){
        if (apuntador -> izquierda == NULL){
            auxiliar = apuntador;
            apuntador = apuntador -> derecha;
            delete auxiliar;
        }
        else if (apuntador -> derecha == NULL){
            auxiliar = apuntador;
            apuntador = apuntador -> izquierda;
            delete auxiliar;
        }
            else{
                apuntador -> dato = menor(apuntador -> derecha);
                eliminar(apuntador -> derecha, apuntador -> dato);
            }
        
    }
    else if(nodo < apuntador -> dato){
        eliminar(apuntador -> izquierda, nodo);
    }
        else{
            eliminar(apuntador -> derecha, nodo);
        }
}


int main(int argc, const char * argv[]) {
    int opcion;
    int numeroNodos, dato1;
    Arbol arbol;
    Nodo *r = arbol.apuntadorRaiz();
    do{
        cout <<"\n";
        cout <<"\nMENÚ";
        cout <<"\n";
        cout <<"\n1- Insertar elemento \n2- Orden infijo \n3- Pre-Orden \n4- Post-Orden \n5- Número de nodos";
        cout <<"\n6- Altura del árbol \n7- Suma de los nodos \n8- Número de hojas \n9- Nodo menor \n10- Eliminar \n11- Salir";
        cout <<"\n";
        cout <<"\nIngrese la opcion deseada (1-11): ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                //arbol.apuntadorRaiz();
                cout <<"\n¿Cuántos elementos desea ingresar? ";
                cin >> numeroNodos;
                for (int i=0; i<numeroNodos; i++){
                    cout <<"\nIngrese el nodo " << i+1 <<": ";
                    cin >> dato1;
                    arbol.insertar(dato1, r);
                }
                break;
            case 2:
                //arbol.apuntadorRaiz();
                cout <<"\nOrden infijo: ";
                arbol.infijo(r);
                break;
            case 3:
                //arbol.apuntadorRaiz();
                cout <<"\nPreorden: ";
                arbol.preOrden(r);
                break;
            case 4:
                //arbol.apuntadorRaiz();
                cout <<"\nPostorden: ";
                arbol.postOrden(r);
                break;
            case 5:
                //arbol.apuntadorRaiz();
                cout <<"\nNúmero de nodos: " << arbol.contar(r);
                break;
            case 6:
                //arbol.apuntadorRaiz();
                cout <<"\nAltura del árbol: " << arbol.altura(r);
                break;
            case 7:
                //arbol.apuntadorRaiz();
                cout <<"\nSuma de los nodos: " << arbol.sumar(r);
                break;
            case 8:
                //arbol.apuntadorRaiz();
                cout <<"\nNúmero de hojas: " << arbol.numeroHojas(r);
                break;
            case 9:
                //arbol.apuntadorRaiz();
                cout <<"\nNodo menor: " << arbol.menor(r);
                break;
            case 10:
                //arbol.apuntadorRaiz();
                cout <<"\n¿Cuántos elementos desea eliminar? ";
                cin >> numeroNodos;
                for (int i=0; i<numeroNodos; i++){
                    cout <<"\nIngrese el nodo que desee eliminar: ";
                    cin >> dato1;
                    arbol.eliminar(r, dato1);
                }
                break;
            case 11:
                cout <<"\n¡Hasta pronto!";
                exit(1);
                break;
        }
    }while (opcion != 11);
    cout <<"\n";
    return 0;
}
