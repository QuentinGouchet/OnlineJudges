#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    int square_left = 0;
    unsigned long long int compteur = n;
    int i = 2;

    while(i*i<=n) {
        square_left = n - i*i;
        compteur++;
        compteur += square_left/i;
        i++;
    }
    printf("%llu",compteur);
    return 0;
}
