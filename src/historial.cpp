#include "../include/historial.h"

struct rep_historial {
};

THistorial crearTHistorial(TFecha fecha) { return NULL; }

void agregarPromocionTHistorial(THistorial historial, TPromocion promocion) {}

void agregarProductoAPromocionTHistorial(THistorial historial,
                                         TProducto producto, int idPromo) {}

void avanzarAFechaTHistorial(THistorial historial, TFecha fecha) {}

void imprimirPromocionesFinalizadosTHistorial(THistorial historial) {}

void imprimirPromocionesActivasTHistorial(THistorial historial) {}

void imprimirPromocionesFuturasTHistorial(THistorial historial) {}

bool esCompatiblePromocionTHistorial(THistorial historial,
                                     TPromocion promocion) { return false; }

void liberarTHistorial(THistorial &historial) {}
