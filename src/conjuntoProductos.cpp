#include "../include/conjuntoProductos.h"


// Definición de tipo TConjuntoProductos como un puntero a rep_conjuntoproductos
// El conjunto es acotado, y la cantidad máxima de elementos define el rango de 
// identificadores que almacena.
// Los identificadores que almacena el conjunto cumplen 0 <= id < cantMax
struct rep_conjuntoProductos{
    int cantMax;
    int cantActual;
    bool *productos;
};

TConjuntoProductos crearTConjuntoProductos(int cantMax){
    TConjuntoProductos nuevoConjunto = new rep_conjuntoProductos;
    nuevoConjunto->cantMax = cantMax;
    nuevoConjunto->cantActual = 0;
    nuevoConjunto->productos = new bool[cantMax];
    
    for (int i = 0; i < cantMax; i++) {
        nuevoConjunto->productos[i] = false;
    }
    
    return nuevoConjunto;
}

void insertarTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
    bool yaPertenece = perteneceTConjuntoProductos(conjuntoProductos, idProducto);
    bool noHayEspacio = conjuntoProductos->cantActual == conjuntoProductos->cantMax;
    bool fueraDeRango = idProducto > conjuntoProductos->cantMax;

    if (yaPertenece || noHayEspacio || fueraDeRango) return;

    conjuntoProductos->productos[idProducto] = true;
    conjuntoProductos->cantActual++;
}

void imprimirTConjuntoProductos(TConjuntoProductos conjuntoProductos){
    if (esVacioTConjuntoProductos(conjuntoProductos)) return;

    for (int i = 0; i < conjuntoProductos->cantMax; i++) {
        if (conjuntoProductos->productos[i]) {
            printf("%i \n", i);
        }
    }
}

void liberarTConjuntoProductos(TConjuntoProductos &conjuntoProductos){
    if (conjuntoProductos != NULL) {
        delete[] conjuntoProductos->productos;
        delete conjuntoProductos; 
        conjuntoProductos = NULL;
    }
}

bool esVacioTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return conjuntoProductos == NULL; }

int cantidadTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return conjuntoProductos->cantActual; }

int cantMaxTConjuntoProductos(TConjuntoProductos conjuntoProductos){ return conjuntoProductos->cantMax; }

bool perteneceTConjuntoProductos(TConjuntoProductos conjuntoProductos, int idProducto){
    if (conjuntoProductos == NULL || idProducto < 0 || idProducto >= conjuntoProductos->cantMax) {
        return false;
    }
    
    return conjuntoProductos->productos[idProducto];
}

void borrarDeTConjuntoProductos(TConjuntoProductos &conjuntoProductos, int idProducto){
    if (esVacioTConjuntoProductos(conjuntoProductos)) return;

    conjuntoProductos->productos[idProducto] = false;
    conjuntoProductos->cantActual--;
}

void insercion(TConjuntoProductos conjunto, TConjuntoProductos &nuevoConjunto) {
    for (int i  = 0; i < conjunto->cantMax; i++) {
        if (conjunto->productos[i]) {
            insertarTConjuntoProductos(nuevoConjunto, i);
        }
    }
}

TConjuntoProductos unionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){
    int cantMaxCombinado = conjuntoProductos1->cantMax + conjuntoProductos2->cantMax;
    TConjuntoProductos nuevoConjunto = crearTConjuntoProductos(cantMaxCombinado);

    nuevoConjunto->cantActual = conjuntoProductos1->cantActual + conjuntoProductos2->cantActual;

    insercion(conjuntoProductos1, nuevoConjunto);
    insercion(conjuntoProductos2, nuevoConjunto);

    return nuevoConjunto;
}

void insercionInterseccion(TConjuntoProductos conjunto1, TConjuntoProductos conjunto2, TConjuntoProductos &nuevoConjunto) {
    for (int i = 0; i < conjunto1->cantMax; i++) {
        if (perteneceTConjuntoProductos(conjunto2, i)) {
            insertarTConjuntoProductos(nuevoConjunto, i);
        }
    }
}

TConjuntoProductos interseccionTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){ 
    int cantMaxCombinado = conjuntoProductos1->cantMax + conjuntoProductos2->cantMax;
    TConjuntoProductos nuevoConjunto = crearTConjuntoProductos(cantMaxCombinado);

    insercionInterseccion(conjuntoProductos1, conjuntoProductos2, nuevoConjunto);

    return nuevoConjunto;
}

void insercionDiferencia(TConjuntoProductos conjunto1, TConjuntoProductos conjunto2, TConjuntoProductos &nuevoConjunto) {
    for (int i = 0; i < conjunto1->cantMax; i++) {
        if (!perteneceTConjuntoProductos(conjunto2, i)) {
            insertarTConjuntoProductos(nuevoConjunto, i);
        }
    }
}

TConjuntoProductos diferenciaTConjuntoProductos(TConjuntoProductos conjuntoProductos1, TConjuntoProductos conjuntoProductos2){
    int cantMaxCombinado = conjuntoProductos1->cantMax + conjuntoProductos2->cantMax;
    TConjuntoProductos nuevoConjunto = crearTConjuntoProductos(cantMaxCombinado);

    insercionDiferencia(conjuntoProductos1, conjuntoProductos2, nuevoConjunto);

    return nuevoConjunto;
}
