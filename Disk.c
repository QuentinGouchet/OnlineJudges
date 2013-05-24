#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int tube[n];
    int i,j;
    int input;
    for(i=0;i<n;i++)
        scanf("%d",&tube[i]);

    for(i=1;i<n;i++) {              //je fais en sorte kil ny ait pas de disque plus grand sous un disque plus petit
        if(tube[i]>tube[i-1])
            tube[i] = tube[i-1];
    }

    /*for(i=0;i<n;i++)
        printf("%d ",tube[i]);*/

    j = n-1;                                //on part du bas de la pile de disques
    for(i=0;i<m;i++) {
        scanf("%d",&input);
        if(j>-1) {                          //j ne pas pas valoir moins de -1 soit moins de 0 a la fin puisqu'on ajoute 1
            while(tube[j]<input && j>-1)    //on remonte pour placer le disque
                j--;
            if(i<m-1)                       //si on n'est pas au dernier cas, on vient de placer un disque et le suivant ne
                j--;                        //pourra etre au mieux qu'une au dessus
        }
    }

    printf("%d\n",j+1);                     //comme l'index informatique est different on rajoute 1...
    return 0;
}
