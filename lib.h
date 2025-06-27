#pragma once
#include <stdio.h> //para funciones basicas
#include <stdint.h> //para operaciones binarias
#include <stdlib.h> //para memoria dinamica
#include <string.h> // para cadenas de caracteres

typedef struct 
{
    uint32_t sample_rate;
    uint32_t sample_count;
    char sound_name[64];
}encabezado;

typedef struct
{
    uint32_t count_of_sounds; //cantidad de pistas
    encabezado enc;
    float *muestras; //cuantos audios hay
}pista;

pista *read_file(FILE *f,int *cant_pistas);