#include <stdio.h>

long int main(){
    double a, b, sum;
    if(scanf("%lf %lf", &a, &b) == 2){
        sum = a + b;
        printf("%lf\n", sum);
    }
    else{
        return 1;
    }
    return 0;
}
