/* 
 * Fichero: tablaSimbolos.c
 * Autores: Miguel Álvarez Lesmes & Marcos Asenjo Gonzalez
 * Curso: 2017-18
 */

#include <stdio.h>
#include "tablaHash.h"
#include "tablaSimbolos.h"

TABLA_SIMBOLOS *crear_tabla_simbolos(int tam){

	TABLA_SIMBOLOS *ts = NULL;

	if ((ts = (TABLA_SIMBOLOS *) malloc(sizeof(TABLA_SIMBOLOS)))){
		return ts;
	}

	if(ts->tglobal = crear_tabla(tam) == NULL){
		free(ts);
		return NULL;
	}
	ts->local = NULL;
	return ts;
}

void destruir_tabla_simbolos(TABLA_SIMBOLOS * ts){
	liberar_tabla(ts->tglobal);

	free(ts);
}

STATUS declarar_global(TABLA_SIMBOLOS * ts, char * lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int id, int param_extra){

	if(insertar_simbolo(ts->th, lexema, categ, tipo, clase, id, param_extra, 0) == ERR){
		return EER;
	}

	return OK;
}

