#include <stdio.h>
#include <string.h>

#define INT 999999

int mc[50][50];

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int matrixChain(int c[],int i,int j){
    if(i==j){
        return 0;
    }
    if(mc[i][j] != -1){
        return mc[i][j];
    }
    mc[i][j]=INT;
    for(int k=i;k<j;k++){
        mc[i][j]=min(mc[i][j],matrixChain(c,i,k)+matrixChain(c,k+1,j)+c[i-1]*c[k]*c[j]);
    }
    return mc[i][j];
}

int matrix(int c[],int n){
    int i=1,j=n-1;
    return matrixChain(c,i,j);
}

int main(){
    int arr[]={2,1,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    memset(mc,-1,sizeof mc);
    printf("Minimum number of multiplications required:%d",matrix(arr,n));
    return 0;
}

