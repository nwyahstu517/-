#include<iostream>
#include<sstream>
#include<cstring> 
using namespace std;
int main(int argc, char const *argv[])
{
	string my_string; 
    while(getline(cin, my_string, '\n')) {  
     char *pch; 
     char str[128]; 
     //c_str()���ص���һ����ʱָ�룬����ֱ�Ӹ��� 
     strcpy(str, my_string.c_str());  
     pch = strtok(str, " -,.");  // �ո�'-'��',','.'���Ƿָ���  ����ʵҲ�ǰ�����ָ����滻Ϊ�ո�
        while(pch != NULL) { 
             cout << pch << endl; 
             pch = strtok(NULL, " -,.");  // ע��������NULL 
        } 
    } 
	return 0;
}
