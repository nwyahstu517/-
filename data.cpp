#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<ctime>
#define digitInt 10//���������� 
#define digitLLInt 19
#define digitBigInt 30
#define digitStringInt 100
#define digitFloat 7
#define digitDouble 15
using namespace std;

string LLMax="9223372036854775807";
string IntMax="2147483647";
string SmellAlphabet="abcdefghijklmnopqrstuvwxyz";
string UpperAlphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//��������
string RnadomInt();
string RandomLLInt();
string RandomBigInteger();
string RandomString();
string RandomFloat();
string RandomDouble();
string RandomInt()
{
    int n=rand()%digitInt+1;//����������nλ��
    string s;
    if(n==digitInt)//���⴦����Ϊint��Ҫ��[-2^31,2^31-1]֮��
    {
        s+=rand()%2+1+'0';//2
        for(int i=1;i<n;i++)
        {
            int temp=rand()%10;//9
            while(temp>IntMax[i]-'0'){
            temp=rand()%10;	
			}
            s+=temp+'0';
        }
        return s;
    }
    if(n==1) s+=rand()%10+'0';//
    else s+=rand()%9+1+'0';//��һλΪ1-9֮�����
    for(int i=2;i<=n;i++) s+=rand()%10+'0';//���������2-nλ�ϵ�����
    if(rand()%2==1) s='-'+s;//��������
    return s;
}
string RandomLLInt()
{
    int n=rand()%digitLLInt+1;//����������nλ��
    string s;
    if(n==digitLLInt)//���⴦����Ϊint��Ҫ��[-2^31,2^31-1]֮��
    {
        s+=rand()%2+1+'0';//2
        for(int i=1;i<n;i++)
        {
            int temp=rand()%10;//9
            while(temp>LLMax[i]-'0'){
            temp=rand()%10;	
			}
            s+=temp+'0';
        }
        return s;
    }
    if(n==1) s+=rand()%10+'0';//
    else s+=rand()%9+1+'0';//��һλΪ1-9֮�����
    for(int i=2;i<=n;i++) s+=rand()%10+'0';//���������2-nλ�ϵ�����
    if(rand()%2==1) s='-'+s;//��������
    return s;
}
string RandomBigInteger()
{
    int n=rand()%digitBigInt+1;//����������nλ��
    string s;
    if(n==1) s+=rand()%10+'0';//
    else s+=rand()%9+1+'0';//��һλΪ1-9֮�����
    for(int i=2;i<=n;i++) s+=rand()%10+'0';//���������2-nλ�ϵ�����
    //if(rand()%2==1) s='-'+s;//��������
    return s;
}
string RandomString()
{
    int n=rand()%digitStringInt+1;//����������nλ�ַ���
    string s;
    for(int i=0;i<n;i++) s+=SmellAlphabet[rand()%26];//��������ַ���
    return s;
}
string RandomFloat(){
	string s=RandomInt();
	stringstream ls;
    int temp=rand()%10000000;
	ls<<temp;
	string ss;
	ls>>ss;
	ls.str("");
	s.append(".").append(ss);
	return s;
}
string RandomDouble(){
	string s=RandomLLInt();
	s.append(".").append(RandomLLInt());
	int pos=s.rfind("-");
	if(pos!=string::npos&&pos!=0)
		s.erase(pos,1);
	return s;
}
int main()
{
    ofstream in("1.txt");
    srand((unsigned)time(NULL));
    int n=rand()%10+1;
    int w=rand()%10+1;
    in<<n<<" "<<w<<endl;
    for(int i=0;i<n;i++){
		for(int j=0;j<w;j++){
            if(rand()%2==0){
                in<<0<<" ";
            }else{
                in<<-1<<" ";
            }
        }
        in<<endl;
	} 
        
    return 0;
}
