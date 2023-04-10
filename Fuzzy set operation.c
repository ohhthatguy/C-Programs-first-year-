//fuzzy set and its implementation

#include <stdio.h>

struct fuzzy{
    char label;
    float num;
};


int main(){

    int n,i,j;
    printf("enter total elements of fuzzy set: ");
    scanf("%d",&n);
    
    struct fuzzy setA[n];
    struct fuzzy setB[n];
    struct fuzzy unions[n];
    struct fuzzy intersection[n];

    printf("\n(label,value) => (x,0.12)\n");
    printf("\ngive data of fuzzy set A: \n");
    for(i=0; i<n; i++){
        fflush(stdin);
        printf("enter label: ");
        scanf("%c", &setA[i].label);
        fflush(stdin);
        printf("enter value: ");
        scanf("%f", &setA[i].num);
        fflush(stdin);
    }

    printf("Now, give data of fuzzy set B: \n");

    for(i=0; i<n; i++){
         fflush(stdin);
        printf("enter label: ");
        scanf("%c", &setB[i].label);
        fflush(stdin);
        printf("enter value: ");
        scanf("%f", &setB[i].num);
        fflush(stdin);
    }

    //union

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(setA[i].num > setB[i].num){
                unions[i].num = setA[i].num;
                unions[i].label = setA[i].label;
                break;
            }else{
                unions[i].num = setB[i].num;
                unions[i].label = setB[i].label;
                break;
            }
        }
    }

    //intersection

    for(i=0; i<n; i++){
        
            if(setA[i].num > setB[i].num){
                intersection[i].num = setB[i].num;
                intersection[i].label = setB[i].label;
                break;
            }else{
                intersection[i].num = setA[i].num;
                intersection[i].label = setA[i].label;
                break;
            }
        
    }


    //printing union
    printf("\n union: \n");
    for(i=0; i<n; i++){
        printf("(%c,%.2f)", unions[i].label,unions[i].num);
    }

    //printing intersection
      printf("\n intersection: \n");
    for(i=0; i<n; i++){
        printf("(%c,%.2f)", intersection[i].label,intersection[i].num);
    }

  //printing complement A
      printf("\n complement of fuzzy set A: \n");
    for(i=0; i<n; i++){
        printf("(%c,%.2f)", setA[i].label,(1-setA[i].num));
    }

     //printing complement B
      printf("\n complement of fuzzy set B: \n");
    for(i=0; i<n; i++){
        printf("(%c,%.2f)", setB[i].label,(1-setB[i].num));
    }





    return 0;
}