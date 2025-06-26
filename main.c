#include "lib.h"

int main()
{
    FILE *f=fopen("audio_list.raw","rb");
    if( f == NULL)
    {
        printf("\nError\n");
        return -1;
    }
    pista *p;
    int cant_pistas=0;

    p=read_file(f,&cant_pistas);
    
    for(int i=0; i<cant_pistas; i++)
    {
        printf("\nPista %d: %s",i,p[i].enc.sound_name);
    }

    



    free(p);
    fclose(f);
    return 0;
}