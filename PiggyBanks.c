#include <stdio.h>
#include<stdlib.h>

struct liste {
	int numero_noeud;
	struct liste * next;
};
typedef struct liste * liste;

struct noeud {
    int pere;
    int marquage;
    liste fils;
};
typedef struct noeud noeud;

liste add (int key,liste L) {
	liste l = malloc(sizeof(liste));
	l->numero_noeud = key;
	l->next = L;
	return l;
}

int dfs (int sommet,noeud graph[]) {
    graph[sommet].marquage = 1;
    //printf("on marque %d\n",sommet);
    liste fils = graph[sommet].fils;
    while(fils!=NULL) {
        if(graph[fils->numero_noeud-1].marquage==0) {
            //printf("son fils %d nest pas marque.\n",fils->numero_noeud);
            dfs(fils->numero_noeud-1,graph);
        }
        fils = fils->next;
    }
    return 0;
}

int main()
{
    int nb;
    scanf("%d",&nb);
    noeud graph[nb];

    int i;
    for(i=0;i<nb;i++) {
        graph[i].marquage = 0;
        graph[i].pere = 0;
        graph[i].fils = NULL;
    }

    int input;
    for(i=0;i<nb;i++) {
        scanf("%d",&input);
        if(i+1!=input)
            graph[i].pere = input;
        graph[input-1].fils = add(i+1,graph[input-1].fils);
    }

    /*liste tmp;
    for(i=0;i<nb;i++) {
        printf("Case: %d Pere: %d ",i,graph[i].pere);
        printf("Marquage: %d\n",graph[i].marquage);
        tmp = graph[i].fils;
        printf("Fils: ");
        while(tmp!=NULL) {
            printf("%d ",tmp->numero_noeud);
            tmp = tmp->next;
        }
        printf("\n");
    }*/

    int compteur = 0;
    for(i=0;i<nb;i++) {
        if(graph[i].marquage==0) {
            dfs(i,graph);
            if(graph[i].pere==0 || graph[graph[i].pere-1].marquage!=0)
               compteur++;
        }
    }

   /*for(i=0;i<nb;i++) {
        printf("Case: %d Pere: %d ",i,graph[i].pere);
        printf("Marquage: %d\n",graph[i].marquage);
        tmp = graph[i].fils;
        printf("Fils: ");
        while(tmp!=NULL) {
            printf("%d ",tmp->numero_noeud);
            tmp = tmp->next;
        }
        printf("\n");
    }*/

    printf("%d",compteur);
    return 0;
}
