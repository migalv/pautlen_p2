#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include "tablaHash.h"

typedef struct _TablaSimbolos TABLA_SIMBOLOS;

TABLA_SIMBOLOS *crear_tabla_simbolos(int tam);
void destruir_tabla_simbolos(TABLA_SIMBOLOS * ts);
STATUS declarar_variable(TABLA_SIMBOLOS * ts, char * lexema, TIPO tipo, CLASE clase, int id, int param_extra);
STATUS declarar_funcion(TABLA_SIMBOLOS * ts, char * lexema, TIPO tipo, CLASE clase, int id, int param_extra);
STATUS declarar_parametro(TABLA_SIMBOLOS * ts, char * lexema, TIPO tipo, CLASE clase, int id, int param_extra);
int buscar_identificador(TABLA_SIMBOLOS *ts, char * lexema);
void cerrar_ambito(TABLA_SIMBOLOS *ts);

#endif