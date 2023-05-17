//
// Created by 田佳业 on 2023/4/7.
//
#include<iostream>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    int **A, **B;
    A = new int *[row];
    B = new int *[row];
    for(int i=0;i<row;i++){
        A[i]=new int [col];
        B[i]=new int [col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>B[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<A[i][j]+B[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}