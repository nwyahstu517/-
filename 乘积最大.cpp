#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
using namespace std;
ifstream fin("1.txt");
ofstream fout("2.txt");
int main(){
    int n;
    cin>>n;
    double a[1001];
    if(n==1){
        a[n]=1;
    }else if(n==2){
        a[n]=1;
    }else if(n==3){
        a[n]=2;
    }else if(n==4){
        a[n]=4;
    }else{
        int k;
        int y=n%3;
        double res;
        if(y==0){
            k=n/3;
            res=pow(3,k);
        }   
        else if(y==1){
            k=n/3-1;
            res=pow(3,k)*4;
        }else{
            k=n/3;
            res=pow(3,k)*2;
        }
        a[n]=res;
    }
    printf("%.0lf",a[n]);
    return 0;
}