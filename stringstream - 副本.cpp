#include<bits/stdc++.h>
using namespace std;
int main(){
char *p1="1 ";
      
     std::stringstream stringstr1;
     stringstr1 << p1;
     int id;
     while(!stringstr1.eof())
     {
          stringstr1 >> id;
          std::cout<<id<<std::endl;
      }
      std::cout<< "***************************" <<std::endl;
     char *p2="1   9 ";
     std::stringstream stringstr2;
     stringstr2 << p2;
     while(!stringstr2.eof())
     {
         stringstr2 >> id;
         std::cout<<id<<std::endl;
      }     
      getchar();
return 0;
}

