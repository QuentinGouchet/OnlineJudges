#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int match (char a,char b) {
    return (tolower(a)==tolower(b));
}

int main()
{
    int TC;
    scanf("%d",&TC);

    while(TC--) {
        int n,m;
        scanf("%d %d",&n,&m);
        char tab[n][m];

        getchar();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                scanf("%c",&tab[i][j]);
            getchar();
        }

        /*for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                printf("%c",tab[i][j]);
            printf("\n");
        }*/

        int k;
        scanf("%d",&k);

        for(int l=0;l<k;l++) {
            string tmp;
            cin >> tmp;
            //cout << "OK" << endl;

            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {

                    if(match(tmp[0],tab[i][j])) {
                        int test;

                        if(j+1>=tmp.length()) { //checking left
                            test = 1;
                            for(int v=0;v<tmp.length();v++) {
                                if(!match(tab[i][j-v],tmp[v]))
                                    test = 0;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                        if(m-j>=tmp.length()) { //checking right
                            test = 1;
                            for(int v=j;v<j+tmp.length();v++) {
                                if(!match(tab[i][v],tmp[v-j]))
                                    test = 0;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                        if(i+1>=tmp.length()) { //checking up
                            test = 1;
                            for(int v=0;v<tmp.length();v++) {
                                if(!match(tab[i-v][j],tmp[v]))
                                    test = 0;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                        if(n-i>=tmp.length()) { //checking down
                            test = 1;
                            for(int v=i;v<i+tmp.length();v++) {
                                if(!match(tab[v][j],tmp[v-i]))
                                    test = 0;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                        if(i+1>=tmp.length() && m-j>=tmp.length()) { //checking up right
                            test = 1;
                            int pos1 = i;
                            int pos2 = j;
                            for(int v=0;v<tmp.length();v++) {
                                if(!match(tab[pos1][pos2],tmp[v]))
                                    test = 0;
                                pos1--;
                                pos2++;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                        if(n-i>=tmp.length() && m-j>=tmp.length()) { //checking down right
                            test = 1;
                            int pos1 = i;
                            int pos2 = j;
                            for(int v=0;v<tmp.length();v++) {
                                if(!match(tab[pos1][pos2],tmp[v]))
                                    test = 0;
                                pos1++;
                                pos2++;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                        if(j+1>=tmp.length() && n-i>=tmp.length()) { //checking down left
                            test = 1;
                            int pos1 = i;
                            int pos2 = j;
                            for(int v=0;v<tmp.length();v++) {
                                if(!match(tab[pos1][pos2],tmp[v]))
                                    test = 0;
                                pos1++;
                                pos2--;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                        if(j+1>=tmp.length() && i+1>=tmp.length()) { //checking up left
                            test = 1;
                            int pos1 = i;
                            int pos2 = j;
                            for(int v=0;v<tmp.length();v++) {
                                if(!match(tab[pos1][pos2],tmp[v]))
                                    test = 0;
                                pos1--;
                                pos2--;
                            }
                            if(test) {
                                printf("%d %d\n",i+1,j+1);
                                goto next;
                            }
                        }

                    }

                }
            }
            next:;
        }
        if(TC)
            printf("\n");
    }
    return 0;
}
