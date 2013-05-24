#include<stdio.h>
#include<string.h>

int main()
{
    int nb_cas;
    scanf ("%d",&nb_cas);

    while (nb_cas--) {
        int turtle;
        scanf ("%d",&turtle);
        scanf("\n");

        char initial[turtle][500];
        char final[turtle][500];

        char input[500];

        int i;
        for(i=0;i<turtle;i++) {
            gets(input);
            strcpy(initial[i],input);
        }

        for(i=0;i<turtle;i++) {
            gets(input);
            strcpy(final[i],input);
        }

        int fin = turtle-1;
        while(fin>=0) {
            if(strcmp(initial[fin],final[fin])==0)
                fin--;
            else if (strcmp(initial[fin],"")==0) {
                strcpy(initial[fin],final[fin]);

                printf("%s\n",final[fin]);

                fin--;
            }
            else {
                    for(i=fin-1;i>=0;i--)
                        strcpy(initial[i+1],initial[i]);

                    strcpy(initial[0],"");
            }
        }
        printf("\n");
    }
    return 0;
}
