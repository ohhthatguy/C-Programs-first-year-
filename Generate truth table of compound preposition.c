//generate truth table of compound preposition

#include <stdio.h>

int or(int p, int q){
    if((p==0)&&(q==0)){
        return 0;
    }else{
        return 1;
    }
}

int and(int p, int q){
    if((p==1)&&(q==1)){
        return 1;
    }else{
        return 0;
    }
}

int nor(int p){
    if(p==0){
        return 1;
    }else{
        return 0;
    }
}

int conditional(int p, int q){
    if((p==1)&&(q==0)){
        return 0;
    }else{
        return 1;
    }
}


int bi_conditional(int p, int q){
    if((p==q)){
        return 1;
    }else{
        return 0;
    }
}

int main(){

    int n,x,z=0,i,y=0,j;
    printf("Enter the number of variable: ");
    scanf("%d", &n);

        int table[8][3] = {
            {0,0,0},
            {0,0,1},
            {0,1,0},
            {0,1,1},
            {1,0,0},
            {1,0,1},
            {1,1,0},
            {1,1,1}
        };

    printf("total operation to be done: ");
    scanf("%d", &x);
    char opr,t,vars[2];
    int rel[8][x];
    
    printf("\nOR: |\nAND: &\nNOR: !\nCONDITIONAL: >\nBI-CONDITIONAL <\n");

    for(int yy=0; yy<x; yy++){ // loop
        
        fflush(stdin);
        printf("Enter operation ( | , & , ! , > , < ) : ");//~p
        scanf("%c", &opr);
        fflush(stdin);
        printf("enter Varibales one by one: \n");
        if(opr == '!'){
            scanf("%c", &t);
            fflush(stdin);
        }else{
            for(int k=0; k<2; k++){
                fflush(stdin);
                scanf("%c", &vars[k]);
                fflush(stdin);
            }
        }
        printf("\n Refer to this process as %d\n", z);
        int m,p;

        if(opr != '!'){
        switch(vars[0]){
            case 'p':
                    m=0;
                    break;
            
            case 'q':
                    m=1;
                    break;

            case 'r':
                    m=2;
                    break;
        }

        switch(vars[1]){
            case 'p':
                    p=0;
                    break;
            
            case 'q':
                    p=1;
                    break;

            case 'r':
                    p=2;
                    break;
        }

        //checking if input is general or referred to previous 
        int e,f,sum=0,checkk=0;
        
            if(((vars[1] <= 57) && (vars[1] >= 48)) || ((vars[0] <= 57) || (vars[0] >= 48))){ // check this condition!!!!!!
                for(i=48; i<=57; i++){
                    if(vars[0] == i){
                        e = (i - 48);
                        sum++;
                       checkk = 10;
                        break;
                    }
                }
                for(i=48; i<=57; i++){
                    if(vars[1] == i){
                        f = (i - 48);
                        sum++;
                        checkk = 20;
                        break;
                    }
                }

            }
       // printf("\nsum: %d\n", sum);
        

        if(sum==0){
        //operation
        switch(opr){
            case '&':
                    for(j=0; j<8; j++){
                        rel[j][y] = and(table[j][m], table[j][p]);
                    }
                    break;
            case '|':
                    for(j=0; j<8; j++){
                        rel[j][y] = or(table[j][m], table[j][p]);
                    }
                    break;
            case '>':
                    for(j=0; j<8; j++){
                        rel[j][y] = conditional(table[j][m], table[j][p]);
                    }
                    break;  
            case '<':
                    for(j=0; j<8; j++){
                        rel[j][y] = bi_conditional(table[j][m], table[j][p]);
                    }
                    break;
     
        }
        }else if(sum == 1){
            if(checkk == 20){
            switch(opr){
            case '&':
                    for(j=0; j<8; j++){
                        rel[j][y] = and(table[j][m], rel[j][f]);
                    }
                    break;
            case '|':
                    for(j=0; j<8; j++){
                        rel[j][y] = or(table[j][m], rel[j][f]);
                    }
                    break;
            case '>':
                    for(j=0; j<8; j++){
                        rel[j][y] = conditional(table[j][m], rel[j][f]);
                    }
                    break;  
            case '<':
                    for(j=0; j<8; j++){
                        rel[j][y] = bi_conditional(table[j][m], rel[j][f]);
                    }
                    break;
     
        } 
            }else if(checkk == 10){

                switch(opr){
            case '&':
                    for(j=0; j<8; j++){
                        rel[j][y] = and(rel[j][e], table[j][p]);
                    }               
                    break;
            case '|':
                    for(j=0; j<8; j++){
                        rel[j][y] = or(rel[j][e], table[j][p]);
                    }
                    break;
            case '>':
                    for(j=0; j<8; j++){
                        rel[j][y] = conditional(rel[j][e], table[j][p]);
                    }
                    break;  
            case '<':
                    for(j=0; j<8; j++){
                        rel[j][y] = bi_conditional(rel[j][e], table[j][p]);
                    }
                    break;
     
        } 


            }
        }else if(sum==2){

            switch(opr){
            case '&':
                    for(j=0; j<8; j++){
                        rel[j][y] = and(rel[j][e], rel[j][f]);
                    }
                    break;
            case '|':
                    for(j=0; j<8; j++){
                        rel[j][y] = or(rel[j][e], rel[j][f]);
                    }
                    break;
            case '>':
                    for(j=0; j<8; j++){
                        rel[j][y] = conditional(rel[j][e], rel[j][f]);
                    }
                    break;  
            case '<':
                    for(j=0; j<8; j++){
                        rel[j][y] = bi_conditional(rel[j][e], rel[j][f]);
                    }
                    break;
     
        } 

        }

        }else{ // opr == '!;
           int g;
        switch(t){
            case 'p':
                    g=0;
                    break;
            
            case 'q':
                    g=1;
                    break;

            case 'r':
                    g=2;
                    break;
        }
        int po = 0;
   
            if(((t<=57)||(t>=48))){
                g=(t-48);
                po++;
                break;

            }
        

        for(j=0; j<8; j++){
            if(po==0){
            rel[j][y] = nor(table[j][g]);
            }else{
                rel[j][y] = nor(rel[j][g]);
            }
        }
        
    

    }


        z++; // refering varibale number
        y++; //  indexing of array rel
        
       
    }

    //end of long loop

//sum is always beinfg 0


    // printing
  
    int countt = 0;

    for(i=0; i<y; i++){
        printf(" operation no. %d: \n", i+1);
        for(j=0; j<8; j++){
           
               if(countt != 0){
               printf("\t");
               }
                printf("%d", rel[j][i]);
                printf("\n");
                
            
        }
          printf("\n------\n");

     
    }

    // check its validity (tautology)
    int valid;
    for(j=0; j<8; j++){
        if(rel[j][(x-1)] == 0){
            valid=0;
            break;
        }else{
            valid =1;
        }
    }

    if(valid == 1){
        printf("\nThis is valid\n");
    }else{
        printf("\nThis is not valid\n");
    }

    return 0;
}