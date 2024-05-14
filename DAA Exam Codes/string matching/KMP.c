#include <stdio.h>
#include <string.h>

void prefixSuffixArray(char *pat,int m,int *pps){
    int lenght=0;
    pps[0]=0;
    
    int i=1;
    
    while(i<m){
        if(pat[i]==pat[lenght]){
            lenght++;
            pps[i]=lenght;
            i++;
        }
        else{
            if(lenght!=0){
                lenght=pat[lenght-1];
            }
            else{
                pps[i]=0;
                i++;
            }
        }
    }
}

void Kmp(char *txt,char *pat){
    int M=strlen(pat);
    int N=strlen(txt);
    int pps[M];
    prefixSuffixArray(pat,M,pps);
    
    int i=0;
    int j=0;
    
    while(i<N){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        
        if(j==M){
            printf("Pattern found at index:%d",i-j);
            j=pps[j-1];
        }
        
        else if(i<N && pat[j]!=txt[i]){
            if(j!=0){
                j=pps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }
}

int main(){
    char txt[]="abcdefghijklmnopqrstuvwxyz";
    char pat[]="opqrstu";
    
    Kmp(txt,pat);
    return 0;
}

