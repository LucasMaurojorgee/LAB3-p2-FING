#include "../include/listaPromociones.h"

struct rep_listaPromociones {

};

TListaPromociones crearTListaPromocionesVacia() { return NULL; }

void agregarPromocionTListaPromociones(TListaPromociones &listaPromociones,
                                       TPromocion promocion) {}

void imprimirTListaPromociones(TListaPromociones listaPromociones) {}

void liberarTListaPromociones(TListaPromociones &listaPromociones,
                              bool liberarPromociones) {}

bool esVaciaTListaPromociones(TListaPromociones promociones) { return false; }



bool pertenecePromocionTListaPromociones(TListaPromociones listaPromociones,
                                         int idPromocion) {
  return false;
}

TPromocion obtenerPromocionTListaPromociones(TListaPromociones listaPromociones,
                                             int idPromocion) {
  return NULL;
}


TListaPromociones obtenerPromocionesFinalizadas(TListaPromociones &listaPromociones,
                                                TFecha fecha) {
  return NULL;
}

TListaPromociones obtenerPromocionesActivas(TListaPromociones &listaPromociones,
                                            TFecha fecha) {
  return NULL;
}

bool esCompatibleTListaPromociones(TListaPromociones listaPromociones,
                                   TPromocion promocion) {
  return false;
}

TListaPromociones unirListaPromociones(TListaPromociones listaPromociones1,
                                       TListaPromociones listaPromociones2) {
  return NULL;
}
