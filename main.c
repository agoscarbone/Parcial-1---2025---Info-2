#include "lib.h"

typedef struct 
{
    uint32_t sample_rate;
    uint32_t sample_count;
    uint64_t sound_name[64];
}encabezado;

int main()
{
    FILE *f=fopen("audio_list.raw","rb");
    if( f == NULL)
    {
        printf("\nError\n");
        return -1;
    }

    return 0;
}