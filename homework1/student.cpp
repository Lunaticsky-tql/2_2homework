//
// Created by 田佳业 on 2023/4/7.
//
#include<bits/stdc++.h>

using namespace std;

class Student {
public :
    int id;
    int score;
};
bool cmp(const Student& s1,const Student& s2){
    return s1.id<s2.id;
}
void find_max_score_student(Student* s, int n){
    int max_score=-1;
    for(int i=0;i<n;i++){
        if(s[i].score>max_score){
            max_score=s[i].score;
        }
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        if(s[i].score==max_score){
            cout<<s[i].id<<' '<<s[i].score<<endl;
        }
    }
}
int main() {
    Student students[4];
    for(auto & student : students){
        cin>>student.id>>student.score;
    }
    find_max_score_student(students,4);
    return 0;
}