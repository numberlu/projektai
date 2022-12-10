#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nelyginiai_zodziai(char *array, int out_size)
{
    int x = 0;
    out_size = 255;
    for(int i = 0; i < out_size; ++i)
    {
        if(array[i] == ' '){
            if(x % 2 == 0)          //jeigu lyginis paliekame, pradedame simbolius skaiciuoti is naujo
            {
                x = 0;
            }
            else{                   // jeigu nelyginis trinam
                out_size -= x;

                for(int j = i - x; j < out_size; ++j)     //paslenkam visa masyva i nelyginio zodzio vieta
                {
                    array[j] = array[j+x];
                }

                i -= x;
                x = 0;
            }
        }
        else{
            x++;
        }
    }
    //printf("\n%d", out_size);
    return out_size;
}

void write(FILE *fc, int out_size, char array[])
{
    for(int i=0; i < out_size - 1; ++i)              
    {
        fprintf(fc, "%c", array[i]);
    }
    fprintf(fc, "\n");
    return;
}

int main(int argc, char *argv[])
{
    FILE *fp, *fc;
    int size = 0;
    int out_size;
    char array[255];

    fp = fopen(argv[1], "r"); //pointeris i failo pradzia

    if (fp == NULL) {
        printf("\n***File unable to open***");
        return 0;
    }

    fc = fopen(argv[2], "w+"); 
    if (fc == NULL) {
        printf("\n***Unable to create file***");
        return 0;
    }

    while(fgets(array, 255, fp)){
        out_size = nelyginiai_zodziai(array, out_size);
        write(fc, out_size, array);
        if(array[out_size - 1] != '\n')
        {
            while(fgetc(fp) != '\n') ;
        }
    }

    fclose(fp);
    fclose(fc);
    return 0;
}