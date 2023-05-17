//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void Print(T *p,int n){
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
}

template<typename T>
void GetLever(T *p ,int n,T lever){
    vector<T> v;
    vector<T> temp;
    for(int i=0;i<n;i++){
        if(p[i]>lever){
            v.push_back(p[i]);
        }
        else{
            temp.push_back(p[i]);
        }
    }
    int size1=v.size();
    int size2=temp.size();
    for(int i=0;i<size1;i++){
        p[i]=v[i];
    }
    for(int i=0;i<size2;i++){
        p[i+size1]=temp[i];
    }
    Print(p,size1);
}
int main(){
    string type;
    cin>>type;
    int len,n;
    cin>>len>>n;
    if(type=="int"){
        int *p=new int[len];
        for(int i=0;i<len;i++){
            cin>>p[i];
        }
        int lever;
        cin>>lever;
        GetLever(p,n,lever);
    }
    else if(type=="char"){
        char *p=new char[len];
        for(int i=0;i<len;i++){
            cin>>p[i];
        }
        char lever;
        cin>>lever;
        GetLever(p,n,lever);
    }
    else if(type=="float"){
        auto *p=new float[len];
        for(int i=0;i<len;i++){
            cin>>p[i];
        }
        float lever;
        cin>>lever;
        GetLever(p,n,lever);
    }
    else{
        return 0;
    }
    return 0;
}