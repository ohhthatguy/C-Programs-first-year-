//set union, intersection, difference, cartesian product.

#include <stdio.h>

int main(){

    int a[5],b[5];
    printf("enter first 5 number of Set A: \n");
    for(int i=0; i<5; i++){
        scanf("%d", &a[i]);
    }

    printf("enter first 5 number of Set B: \n");
    for(int i=0; i<5; i++){
        scanf("%d", &b[i]);
    }

    //union
    int count_union = 10;
    int count_intersection = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(a[i] == b[j]){
                count_intersection++;
            }
        }
    }

    int intersection[count_intersection];

    int k=0;
     for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(a[i] == b[j]){
                intersection[k] = a[i];
                k++;
            }
        }
    }

int count_diff = 5 - count_intersection;
int diffA[count_diff];
int diffB[count_diff];
int x=0,y=0;
//int l=0,;

    for(int i=0; i<5; i++){ //set a
    int countda=0;
        for(int j=0; j<count_intersection; j++){ // intersection 
                if(a[i] != intersection[j]){
                    countda++;
                }
                
            }
            if(countda == count_intersection){
                diffA[x] = a[i];
                x++;
            }
            
        }
    
    for(int i=0; i<5; i++){ //set b
    int countdb=0;
        for(int j=0; j<count_intersection; j++){ // intersection 
                if(b[i] != intersection[j]){
                    countdb++;
                }
                
            }
            if(countdb == count_intersection){
                diffB[y] = b[i];
                y++;
            }
            
        }

   int z = count_diff + count_diff + count_intersection;
   int Union[z];

   for(int i=0; i<count_diff; i++){
    Union[i] = diffA[i];
   }
   int l=0;
   for(int i=count_diff; i<(count_diff + count_diff); i++){
    Union[i] = diffB[l];
    l++;
   }
    int ll=0;
   for(int i=(count_diff + count_diff); i<z; i++){
    Union[i] = intersection[ll];
    ll++;
   }

    //print intersection
    printf("Intersection: ");
    for(int i=0; i<count_intersection; i++){
        printf("%d, ", intersection[i]);
    }


    //print diffA
    
    printf("\nDiffA: ");
    //for(int i=0; i<count_diff; i++){
    for(int i=0; i<count_diff; i++){
        printf("%d, ", diffA[i]);
    }


    //print diffB
  
    printf("\nDiffB: ");
    for(int i=0; i<count_diff; i++){
        printf("%d, ", diffB[i]);
    }

    //print union

    printf("\nunion: ");
    for(int i=0; i<z; i++){
        printf("%d, ", Union[i]);
    }

    //cartesian product: A*B
    printf("\n(cartesian product)A*B: ");
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("(%d,%d), ", a[i], b[j]);
        }
    }
    printf("\n(cartesian product)A*B: ");
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("(%d,%d), ", b[i], a[j]);
        }
    }

    return 0;
}

