#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaSimbolos.h"

#define MAX_LENGTH 120
#define TAM_TABLES 100

int main(int argc, char *argv[]){
	FILE *entrada = NULL, *salida = NULL;
	char line[MAX_LENGTH];
	char *token = NULL;
	char *lexema = NULL;
	int id = 0;
	int idNotUsed=0;

	TABLA_SIMBOLOS *ts = NULL;


	if(argc < 3){
		printf("Parametros incorrectos\n");
		printf("Pruebe con ./%s <fichero entrada> <fichero salida>", argv[0]);
		exit(1);
	}

	ts = crear_tabla_simbolos(TAM_TABLES);
	if(!ts){
		printf("Error creando la tabla de simbolos.\n");
		exit(1);
	}
	entrada = fopen(argv[1], "r");
	if(!entrada){
		destruir_tabla_simbolos(ts);
		printf("Error abriendo el archivo de entrada.\n");
		exit(1);
	}

	salida = fopen(argv[2], "w");
	if(!salida){
		destruir_tabla_simbolos(ts);
		fclose(entrada);
		printf("Error abriendo el archivo de salida.\n");
		exit(1);
	}

	while(fgets(line, MAX_LENGTH, entrada) != NULL){
		printf("%s\n", line);

		token = strtok(line, "\t");
		lexema = token;
		token = strtok(NULL, "\t");
		if(token != NULL){;
			id = atoi(token);
			idNotUsed = 0;
		}
		else{
			idNotUsed = 1;
		}

		if(strcmp(lexema, "cierre") && idNotUsed == 0 && id == -999){
			cerrar_ambito(ts);
			fprintf(salida, "cierre\n");
		} else if (idNotUsed == 1){
			fprintf(salida, "%s\t%d\n", lexema, buscar_identificador(ts, lexema));
		} else if (idNotUsed == 0 && id >= 0){
			if(declarar_variable(ts, lexema, ENTERO, ESCALAR, id, 0) == ERR)
				fprintf(salida, "-1\t%s\n", lexema);
			else
				fprintf(salida, "%s\n", lexema);
		} else if (idNotUsed == 0 && id < 0){
			if(declarar_funcion(ts, lexema, ENTERO, ESCALAR, id, 0) == ERR)
				fprintf(salida, "-1\t%s\n", lexema);
			else
				fprintf(salida, "%s\n", lexema);
		}
	}

	fclose(entrada);
	fclose(salida);

	return 0;
}