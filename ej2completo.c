#include "ej2.h"

#include <string.h>

// OPCIONAL: implementar en C
void invocar_habilidad(void* carta_generica, char* habilidad) {
	card_t* carta = (card_t*) carta_generica;

	while (carta != NULL) {
		directory_t dir = carta->__dir;
		uint16_t cant_entradas = carta->__dir_entries;

		for (int i = 0; i < cant_entradas; i++) {
			directory_entry_t* entrada = dir[i];  // porque directory_t es un **

			if (strcmp(entrada->ability_name, habilidad) == 0) {
				ability_function_t* funcion = (ability_function_t*) entrada->ability_ptr;
				funcion(carta);  // llamamos a la función con el puntero a la carta actual
				return;
			}
		}

		// Si no está la habilidad en la carta actual, seguimos con su arquetipo
		carta = (card_t*) carta->__archetype;
	}

	// Si salimos del while, es porque no encontramos la habilidad: no hacemos nada
}
