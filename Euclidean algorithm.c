//euclidian algorithm 

#include <stdio.h>

int GCD(int a, int b){
    int c = a%b;
    if(c!=0){
        a=b;
        b=c;
        GCD(a,b);
    }else{
        return b;
    }
}

 
int main(){

    int x,y;
    int a,b;
    printf("enter first digit:\n=>  ");
    scanf("%d", &a);
        printf("enter second digit:\n=>  ");
    scanf("%d", &b);

    if(a>b){
        int temp = GCD(a,b);
        printf("The GCD by Euclidian Algo is %d.",temp);
    }else{
        int temp = GCD(b,a);
        printf("The GCD by Euclidian Algo is %d.",temp);
    }

    //by extended

    return 0;
}