//
// Created by 田佳业 on 2023/4/30.
//
//更正：指针动态联编
#include<iostream>
using namespace std;
class Distance{
protected:
    int x1,x2,y1,y2;
public:
    Distance(int x1,int y1,int x2,int y2):x1(x1),x2(x2),y1(y1),y2(y2){}
    virtual int getDistance()=0;
};
class ManhattanDistance: public Distance{
public:
    ManhattanDistance(int i, int i1, int i2, int i3) : Distance(i, i1, i2, i3) {
    }
    int getDistance() override
    {
        return abs(x1-x2)+abs(y1-y2);
    }

};
class EuclideanDistance: public Distance{
public:
    EuclideanDistance(int i, int i1, int i2, int i3) : Distance(i, i1, i2, i3) {
    }
    int getDistance() override
    {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
};
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Distance* d1=new ManhattanDistance(a,b,c,d);
    Distance* d2=new EuclideanDistance(a,b,c,d);
    cout<<d1->getDistance()<<" "<<d2->getDistance();
    return 0;

}