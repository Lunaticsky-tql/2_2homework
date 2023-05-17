//
// Created by 田佳业 on 2023/4/7.
//
#include <cstring>
#include<iostream>
using namespace std;
char a[1000];//原始字符串
char b[1000];//压缩后的字符串
void stringZip(const char *a, int len, char *b){
    //函数实现
    int n=0;
    int p_b=0;
    for(int i=1;i<len;i++){
        if(a[i-1]==a[i]){
            n++;
        }
        else{
            if(n>0)
            {
                b[p_b++]=n+'1';
                b[p_b++]=a[i-1];
                n=0;
            }
            else{
                b[p_b++]=a[i-1];
            }
        }
    }
    if(n>0){
        b[p_b++]=n+'1';
        b[p_b++]=a[len-1];
    }
    else{
        b[p_b++]=a[len-1];
    }
}
int main()
{

    cin>>a;
    int len;//字符串长度
    len=strlen(a);
    stringZip(a,len,b);
    cout<<b<<endl;
    return 0;
}