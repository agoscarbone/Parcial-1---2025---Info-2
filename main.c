#include "lib.h"
#include "audio_player.h"

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
    fseek(f,0,SEEK_END);//llevo el apuntador al final del archivo
    long size=ftell(f);
    rewind(f);
    

    p=read_file(f,&cant_pistas);
    
    for(int i=0; i<cant_pistas; i++)
    {
        printf("\nPista %d: %s",i,p[i].enc.sound_name);
    }

    int seleccion;
    do
    {
        printf("\nSeleccione el numero de pista: ");
        scanf("%d",&seleccion);
    } while (seleccion<0 || seleccion>3);

    int j=0;
    

    /*while(size>ftell(f))
    {
        fread((p)[j].muestras,sizeof(float),p[j].enc.sample_count,f);
        j++;
    }*/

    for(int i=0; i<seleccion; i++)
    {
        if(i!=seleccion)
        {
            fseek(f,p[i].enc.sample_count*sizeof(encabezado),SEEK_CUR);
        }else{
            fread(&(p)[i].muestras,sizeof(float),1,f);
        }
        j++;
    }
    float *audio=malloc((p[seleccion].enc.sample_count)*sizeof(float));
    fread(audio,sizeof(float),p[seleccion].enc.sample_count,f);
    printf("%u,%u",p[seleccion].enc.sample_rate,p[seleccion].enc.sample_count);
    play_audio(p[seleccion].enc.sample_rate, p[seleccion].enc.sample_count, audio);

    int g;
    do{
        printf("\nSeleccione otra pista: ");
        scanf("%d",g);
    }while(g<0 || g>3);
     FILE *t=fopen("sound.raw","wb");
     if(t == NULL)
     {
        printf("ERROR\n");
        return -1;
     }

     fwrite(p[g].muestras,sizeof(float),p[g].enc.sample_count,t);
    


    free(audio);
    free(p);
    fclose(f);
    return 0;
}