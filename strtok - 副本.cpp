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
     //c_str()返回的是一个临时指针，不能直接复制 
     strcpy(str, my_string.c_str());  
     pch = strtok(str, " -,.");  // 空格，'-'，',','.'都是分隔符  ，其实也是把这个分隔符替换为空格
        while(pch != NULL) { 
             cout << pch << endl; 
             pch = strtok(NULL, " -,.");  // 注意这里是NULL 
        } 
    } 
	return 0;
}
