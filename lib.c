#include "lib.h"

pista *read_file(FILE *f,int *cant_pistas)
{
    fseek(f,0,SEEK_END);//llevo el apuntador al final del archivo
    long size=ftell(f);
    rewind(f);
    pista *p=NULL;
    int i=0;
    
    while(size>ftell(f))
    {
        p=realloc(p,(i+1)*sizeof(pista));
        if(i==0)
        {
            fread(&(p)[i].count_of_sounds,sizeof(uint32_t),1,f);
        }
        fread(&(p)[i].enc.sample_rate,sizeof(uint32_t),1,f);
        fread(&(p)[i].enc.sample_count,sizeof(uint32_t),1,f);
        p[i].muestras = malloc(sizeof(float) * p[i].enc.sample_count);
        fread(&(p)[i].enc.sound_name,sizeof(char),64,f);
       // p[i].muestras = malloc(sizeof(float) * p[i].enc.sample_count);
        
        //fread(&(p)[i].muestras,sizeof(float),1,f);
        i++;
    }
    //i=0;
    *cant_pistas=p[i].count_of_sounds;
    return p;
}