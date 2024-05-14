#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4

void printSolution(int color[]);

bool isValid(int v,bool graph[V][V],int color[],int c){
    for(int i=0;i<V;i++){
        if(graph[v][i]&&c==color[i]){
            return false;
        }
    }
    return true;
}

bool colorUntil(bool graph[V][V],int m,int color[],int v){
    if(v==V){
        return true;
    }
    
    for(int c=1;c<=m;c++){
        if(isValid(v,graph,color,c)){
            color[v]=c;
            
            if(colorUntil(graph,m,color,v+1)==true){
                return true;
            }
            
            color[v]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[V][V],int m){
    int color[V];
    for(int i=0;i<V;i++){
        color[i]=0;
    }
    
    if(colorUntil(graph,m,color,0)==false){
        printf("No solution");
        return false;
    }
    
    printSolution(color);
    return true;
}

void printSolution(int color[]){
    printf("solution exists following are the colours assigned:");
    for(int i=0;i<V;i++){
        printf("%d",color[i]);
    }
    printf("\n");
}

int main(){
    bool graph[V][V]={
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    
    int m=3;
    
    graphColoring(graph,m);
    return 0;
}

