//ceiling and floor function

#include <stdio.h>


int Ceiling(float b){
    if(b>0){
        int temp = b *100;
        if((temp%100) == 0){
            int c = b;
         
            return c;
        }else{
            b = b+1;
            int c = b;
            return c;
        }
    }else if(b<0){
        
          int c = b;
          return c;
    }else{
        return 0;
    }
}

int Floor(float k){

    if(k>0){
         int c = k;
         return c;
     }else if(k<0){
        int temp = k*100;
        if((temp%100) == 0){
             int c = k;
         return c;
        }else{
            k = k-1;
            int c = k;
            return c;
        }
        
    }else{
        return 0;
    }

}


int main(){
    int ce,fl;
    float b,c;
      //value input
    printf("Enter the  value: ");
    scanf("%f", &b);

 ce = Ceiling(b);
  fl = Floor(b);  
     printf("Ceiling  is %d\nFloor is %d", ce,fl);

    return 0;
}