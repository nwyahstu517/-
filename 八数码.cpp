#include<iostream>
#include<tr1/unordered_map>
#include<queue>
using namespace std;
using namespace std::tr1;//tr1 ½â¾öc++ 11
unordered_map<string,int> dist;
int bfs(string start){
    string end="12345678x";
    if(start==end)return 0;
    queue<string> q;
    q.push(start);
    
    dist[start] = 0;
    while (q.size())
    {
        string temp=q.front();
        q.pop(); 
        int x,y;
        for(int i=0;i<9;i++){
            if(temp[i]=='x'){
                x=i/3;
                y=i%3;
                break;
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            string state=temp;
            int a=x+dx[i];
            int b=y+dy[i];
            if(a<0||a>=3||b<0||b>=3)continue;
            swap(state[a*3+b],state[x*3+y]);
            if(dist.count(state)==0){
                dist[state]=dist[temp]+1;
                if(state==end)return dist[state];
                q.push(state);
            }
        }
    }
    return -1;
}
int main(){
    string start,c;
    while(cin>>c)start+=c;
    cout<<bfs(start);
    return 0;
}