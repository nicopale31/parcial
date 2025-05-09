
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "ej1.h"

/**


 * Marca el ejercicio 1A como hecho (`true`) o pendiente (`false`).


 *


 * Funciones a implementar:


 *   - init_fantastruco_dir


 */

bool EJERCICIO_1A_HECHO = true;

// Implementación en C de init_fantastruco_dir

void init_fantastruco_dir(fantastruco_t *card)
{

    if (!card)
        return;

    // Reservar espacio para los punteros a directory_entry_t*

    card->__dir = malloc(sizeof(directory_entry_t *) * 2);

    if (!card->__dir)
        return;

    // Número de habilidades del arquetipo Fantastruco

    card->__dir_entries = 2;

    // El arquetipo genérico no tiene __archetype apuntando a otra cosa

    card->__archetype = NULL;

    // Inicialmente boca arriba

    card->face_up = true;

    // Crear y asignar la entrada para "sleep"

    card->__dir[0] = create_dir_entry("sleep", sleep);

    // Crear y asignar la entrada para "wakeup"

    card->__dir[1] = create_dir_entry("wakeup", wakeup);
}

/**


 * Marca el ejercicio 1B como hecho (`true`) o pendiente (`false`).


 *


 * Funciones a implementar:


 *   - summon_fantastruco


 */

bool EJERCICIO_1B_HECHO = true;

// Implementación en C de summon_fantastruco

fantastruco_t *summon_fantastruco()
{

    fantastruco_t *card = malloc(sizeof(fantastruco_t));
    if (!card)
        return NULL;

    init_fantastruco_dir(card);

    return card;
}
