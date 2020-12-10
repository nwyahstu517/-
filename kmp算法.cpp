#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int cn;
void prefix_table(char pattern[],int prefix[],int n){
    prefix[0]=0;
    int len=0;
    int i=1;
    while(i<n){
        if(pattern[i]==pattern[len]){
            len++;
            prefix[i]=len;
            i++;
        }else{
            if(len>0){
              len=prefix[len-1];  
            }else{
                prefix[i]=len;
                i++;
            }
        }
    }

}
void move_prefix_table(int prefix[],int n){
    for(int i=n-1;i>0;i--){
        prefix[i]=prefix[i-1];
    }
    prefix[0]=-1;
}
void kmp_search(char text[],char pattern[]){
    int n=strlen(pattern);
    int m=strlen(text);
    int* prefix=(int*)malloc(sizeof(int)*n);
    prefix_table(pattern,prefix,n);
    move_prefix_table(prefix,n);
    int i=0,j=0;//text[i]  pattern[j]
    while(i<m){
        if(j==n-1&&text[i]==pattern[j]){
            //cout<<"find:"<<i-j<<endl;
            cn++;
            j=prefix[j];
        }
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            j=prefix[j];
            if(j==-1){
                i++;
                j++;
            }
        }
    }
}
const int N=1e6+10;
char pattern[N];
char text[N];
int main(){
    cin>>text>>pattern;
    kmp_search(text,pattern);
    cout<<cn;
}