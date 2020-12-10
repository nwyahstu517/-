#include<iostream>
using namespace std;
void printArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
}
int maxbit(int data[],int n){
    int d=1;//保存最大的位数
    int p=10;
    for (int i = 0; i < n; i++)
    {
            while(data[i]>=p){
                p*=10;
                d++;
            }
    }
    return d;
    
}
void radixsort(int data[],int n){
    int d=maxbit(data,n);
    int tmp[n];
    int count[10];
    int i,j,k;
    int radix=1;
    for(i=1;i<=d;i++){
        for(j=0;j<10;j++){
            count[j]=0;   
        }
        for(j=0;j<n;j++){
            k=(data[j]/radix)%10;
            count[k]++;
        }
        for(j=1;j<10;j++){
            count[j]=count[j-1]+count[j];
        }
        for(j=n-1;j>=0;j--){
            k=(data[j]/radix)%10;
            tmp[count[k]-1]=data[j];
            count[k]--;
        }
      /*  for(j=0;j<n;j++){
        	cout<<tmp[j]<<" ";
		}
		cout<<endl;*/
        for(j=0;j<n;j++){
            data[j]=tmp[j];
        }
        radix*=10;
    }
}
int main(){
    
    int array[10]={12,432,65,10,76,45,3,123,87,35};
    radixsort(array,10);
    printArray(array,10);
    return 0;
}
