#include<iostream>
#include<cstring>
using namespace std;
const int SIZE = 25;
bool used[SIZE];
int data[SIZE];
int n, m, i, j, k;
bool flag;
int main(){
    cin>>n>>m;
    memset(used, false, sizeof(used));
    for (i = 1; i <= m; i++){
        data[i] = i;
        used[i] = true;
    }
    flag = true;
    while (flag){
        for (i = 1; i <= m; i++)cout<<data[i]<<" ";
        cout<<endl;
        flag =0;
        for (i = m; i >= 1; i--){
            used[data[i]]=0;
            for (j = data[i]+1; j <= n; j++)
                if (!used[j]){
                    used[j] = true;
                    data[i] =j;
                    flag = true;
                    break;
                }
                if (flag){
                    for (k = i+1; k <= m; k++)
                         for (j = 1; j <=n; j++)
                            if (!used[j]){
                            data[k] = j;
                            used[j] = true;
                            break;
                            }
                    break;
                }
        }
    }
    return 0;
}
