//reperesent graph, find shortest path, generate minimum spanning tree

//representing graph in adjcaent matrix
#include <stdio.h>



int main(){
    printf("representing graph in zero-one matrix: \n");
    int i,j,n;
    printf("Enter the total number of variable: ");
    scanf("%d", &n);
    char var[n];
    printf("Enter the variables used: ");
    for(i=0; i<n; i++){
        fflush(stdin);
        scanf("%c", &var[i]);
    }
    //int m=(n*n);
    int result[n][n];
    printf("\n1 for yes, 0 for no\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("is %c and %c connected?", var[i], var[j]);
            scanf("%d", &result[i][j]);
        }
    }
    printf("\nAdjacent amtrix representing the graph is: ");

    printf("\n\t");
    for(i=0; i<n; i++){
        
         printf("%c\t", var[i]);
        
    }
    printf("\n");
    for(i=0; i<n; i++){
        printf("%c\t", var[i]);
        for(j=0; j<n; j++){
            
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    
//shortest path
printf("\n shortest path\n");

   int n1, x,y,k=0;
   printf("total vertices: ");
   scanf("%d", &n1);
   int m=n1-1;
   char reached[n1];
   printf("Enter the starting vertice: ");
    fflush(stdin);
   scanf("%c", &reached[0]);
   fflush(stdin);
      printf("\nEnter the ending vertice: ");
    scanf("%c",&reached[(n1-1)]);
    fflush(stdin);
    char z = reached[n1-1];
    //int size[n];
    int final=0;
   while(z != reached[k]){

    printf("How many vetrices is %c connected to ignoring itself and other vertices which are previously asked ?\n", reached[k]);
     k++;
    scanf("%d", &x);
    int size[x];
    printf("enetr the weights of the connected vertices: ");
    for(i=0; i<x; i++){
        scanf("%d", &size[i]);
    }
    //finds smallest weight
     for(i=0; i<x; i++){
        for(j=0; j<x; j++){
           if(size[i] > size[j+1]){
            int temp = size[i];
            size[i] = size[j+1];
            size[j+1] = temp;
           } 
        }
    }
    final = final + size[0];
    fflush(stdin);
    printf("which of the current eneterd vertices has weight of %d", size[0]);
    scanf("%c", &reached[k]);
    fflush(stdin);
    printf("\n");
   }

   printf("shortest path: ");
   for(i=0; i<=k; i++){
    printf("%c-", reached[i]);
   }
   printf("\n shortest length: %d", final);



// minimum spanning tree
printf("\nminimum spanning tree\n");

    int v,e;
    printf("Enetr number of vertex: ");
    scanf("%d", &v);
    printf("Enetr number of edge: ");
    scanf("%d", &e);
    int weight[e],edge[e][2], span[e][2];
    printf("enetr all %d weights of the graph:", e);
    for(i=0; i<e; i++){
        scanf("%d", &weight[i]);
    }

    //ascending order this weight
    
     for(i=0; i<e; i++){
        for(j=i; j<e; j++){
           if(weight[i] > weight[j+1]){
            int temp = weight[i];
            weight[i] = weight[j+1];
            weight[j+1] = temp;
           } 
        }
    }
/*
    for(i=0; i<e; i++){
        printf("%d,", weight[i]);
    }
*/
    for(i=0; i<e; i++){
        printf("enter edge having weight of %d: ", weight[i]);
        for(j=0; j<2; j++){
            fflush(stdin);
            scanf("%c", &edge[i][j]);
            //fflush(stdin);
            
        }
    }

    char check='n';
    int counts = 0;
    printf("press y if these edges form a cycle & n if they don't:\n ");
   
   fflush(stdin);
   int val[e],w=0;
   
   //if they form cycle, val[i] = 0 ,else val[i]  =1
   //problrem 
   printf("Check the edge which dont form cycle and shown edge before pressing y/n\n");
    for(i=0; i<e; i++){
        if(check == 'y'){
            val[i]=0;
            }else{
                val[i]=1;
            }
           
        counts++;
        for(j=0; j<2; j++){
        printf("%c", edge[i][j]);
        }
       // printf(",%c%c", edge[i][j], edge[i][j+1]);
         
        printf("\n=> ");
        scanf("%c", &check);
        fflush(stdin);  
        printf("\n");

    }


    //logic
     counts = counts - 1;
    for(i=0; i<(counts); i++){
        if(val[i] == 1){

        for(j=0; j<(2); j++){
            printf("%c", edge[i][j]);
        }
        printf(" - ");
     
        }
        
    }
    int sum=0;
    for(i=0; i<(counts); i++){
        if(val[i] == 1){
            sum = sum + weight[i];
        }
    }
    printf("\nweight: %d", sum);
    
   


    return 0;
}