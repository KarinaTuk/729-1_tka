#include <stdio.h>

int main(){
    double n, x, i, count;
    count = 0;
    int tempValue = scanf("%lf", &n);
    if(tempValue == 1){
        for(i = 1; i <= n; i++){
            tempValue = scanf("%lf", &x);
            if(tempValue == 1){
                if(x <= 0)
                {
		            count++;
                }
            }
        }

        printf("%lf\n", count);
    }

    return 0;
}
