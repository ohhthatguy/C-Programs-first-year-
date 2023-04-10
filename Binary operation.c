//binary addition, subtraction, multiplication, divison

#include <stdio.h>
#include <math.h>

int sizeoff(int x){ //use at input data
    int size = 0, temp = 1;
    for(int i=0; temp!=0; i++){
        temp = x/10;
        size++;
        x=temp;
    }
    return size;
}

int sizeoffprocessing(int f){ //use at processing data
     int size = 0, temp = 1;
    for(int i=0; temp!=0; i++){
        temp = f/2;
        size++;
        f=temp;
    }
    return size;
}

int todecimal(int a[], int n){
  int sum=0;
    for(int i=0; i<n; i++){
        sum = sum + (a[i]*pow(2,i));
    }
    return sum;
}

void tobinary(int s[], int n, int opr){
    int flag = 0;
    if(opr < 0){
    opr = opr * (-1);
    flag = 1;
   }
    for(int i=0; i<n; i++){
        int temp = opr %2;
        s[i] = temp;
        int ctemp = opr/2;
        opr = ctemp;
    }
    
   // reverseit;
    
    if(flag == 1){printf("-");}
    for(int i=(n-1); i>=0; i--){
       printf("%d",s[i]);
    }

}


void main(){
    int i,j,a,b;
    printf("Enter the first binary: ");
    scanf("%d", &a);
    printf("Enter another binary number: ");
    scanf("%d", &b);

    int sizeA = sizeoff(a);
    int sizeB = sizeoff(b);

    int binaryA[sizeA];
    int binaryB[sizeB];

    //puting the digits of A in arrys
    for(i=0; i<sizeA; i++){
        int temp = a%10;
        binaryA[i] = temp;
        int ctemp = a/10;
        a = ctemp;

    }
    
     //puting the digits of B in arrys
    for(i=0; i<sizeB; i++){
         int temp = b%10;
        binaryB[i] = temp;
        int ctemp = b/10;
        b = ctemp;
    }

   //changing this into decimal
    int k = todecimal(binaryA,sizeA);
    int p = todecimal(binaryB, sizeB);
   
   //operations
   int sums = (k+p);
   //int diffs = (k-p);
   int muls = (k*p);
   int divs = (k/p);

   int sizeSum = sizeoffprocessing(sums);
   //int sizeDiff = sizeoffprocessing(diffs);
   int sizeMul = sizeoffprocessing(muls);
   int sizeDiv = sizeoffprocessing(divs);

   int sum[sizeSum], mul[sizeMul], div[sizeDiv];
    //int diff[sizeDiff];

   printf("SUM: ");
   tobinary(sum, sizeSum, sums);
   printf("\n");
   
    /*
   printf("DIFFERENCE: ");
   tobinary(diff, sizeDiff, diffs);
   printf("\n");
   */

   printf("MULTIPLY: ");
   tobinary(mul, sizeMul, muls);
   printf("\n");   
   
   printf("DIVIDE: ");
   tobinary(div, sizeDiv, divs);
   printf("\n");

}
