#include <stdio.h>

int main(){
    double n, x, i, sum = 0;
    int temp = scanf("%lf", &n);
    if(temp == 1){
        for(i = 1; i <= n; i++){
            temp = scanf("%lf", &x);
            if(temp == 1){
                sum += x - i;
            }
        }

        printf("%lf\n", sum);
    }
    else
    {
        return 1;
    }
    return 0;
}
