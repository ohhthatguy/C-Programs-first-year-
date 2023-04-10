//boolean matrix join, meet and boolean product

#include <stdio.h>

int main(){
    int a,b;
    printf("enetr the number of rows: ");
    scanf("%d",&a);
    printf("enetr the number of columns: ");
    scanf("%d",&b);
    
    int A[a][b], B[a][b];
    printf("enter first boolean matrix: ");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("enter second boolean matrix: ");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            scanf("%d", &B[i][j]);
        }
    }

    //join
    int join[a][b];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            if((A[i][j] == 1) && (B[i][j] == 1)){
                join[i][j] = 1;

            }else{
                join[i][j] = (A[i][j] + B[i][j]);
            }
        }
    }

    //meet
    int meet[a][b];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            meet[i][j] = (A[i][j] * B[i][j]);
        }
    }

    //Boolean Product
    int product[a][b];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            product[i][j] = 0;
            for(int k=0; k<a; k++){
                
                int pp  = product[i][j] + A[i][k] * B[k][j];
                 if((pp!=1) && (pp!=0)){
                    pp = 1;
                 }
                 product[i][j] = pp;
            
            }
        }
    }

    //print
    printf("\njoin:\n");
  
    for(int i=0; i<a; i++){
          printf("[ ");
        for(int j=0; j<b; j++){
            printf("%d ", join[i][j]);
        }
        printf(" ]\n");
    }

printf("\nMeet:\n");
  
    for(int i=0; i<a; i++){
          printf("[ ");
        for(int j=0; j<b; j++){
            printf("%d ", meet[i][j]);
        }
        printf(" ]\n");
    }

    printf("\nBoolean product:\n");
  
    for(int i=0; i<a; i++){
          printf("[ ");
        for(int j=0; j<b; j++){
            printf("%d ", product[i][j]);
        }
        printf(" ]\n");
    }


    return 0;
    
}