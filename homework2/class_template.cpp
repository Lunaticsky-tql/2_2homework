//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class MyArray{
private:
    T *p;
    int len;
public:
    MyArray(int n){
        len=n;
        p=new T[len];
    }
    void Input(){
        for(int i=0;i<len;i++){
            cin>>p[i];
        }
    }
    void Sort(){
        for(int i=0;i<len-1;i++){
            for(int j=0;j<len-i-1;j++){
                if(p[j]>p[j+1]){
                    swap(p[j],p[j+1]);
                }
            }
        }
    }
    void OutPut(){
        for(int i=0;i<len;i++){
            cout<<p[i]<<" ";
        }
    }
};

int main(){
    int tc=3;
    int n;
    while(tc--){
        cin>>n;
        switch(tc){
            case 0:
            {
                MyArray<string> a(n);
                a.Input();
                a.Sort();
                a.OutPut();
                cout<<endl;
                break;
            }
            case 1:
            {
                MyArray<char> a(n);
                a.Input();
                a.Sort();
                a.OutPut();
                cout<<endl;
                break;
            }
            case 2:{
                MyArray<int> a(n);
                a.Input();
                a.Sort();
                a.OutPut();
                cout<<endl;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}