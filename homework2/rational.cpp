//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>

using namespace std;

int gcd(int m, int n) {
    if (m % n == 0) {
        return n;
    } else {
        return gcd(n, m % n);
    }
}

class Rational {
private:
    int numerator;
    int denominator;

    friend void simplify(Rational &r);

public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int a, int b) {
        if (b == 0) {
            cout << "error" << endl;
            exit(0);
        } else {
            if (a == 0) {
                Rational();
            } else {
                if (a * b > 0) {
                    numerator = abs(a);
                    denominator = abs(b);
                } else {
                    numerator = -abs(a);
                    denominator = abs(b);
                }
                simplify(*this);
            }
        }
    }
    Rational(const Rational &r) {
        this->numerator = r.numerator;
        this->denominator = r.denominator;
    }
    friend ostream &operator<<(ostream &os, const Rational &r) {
        if (r.numerator == 0) {
            os << 0;
        } else if (r.denominator == 1) {
            os << r.numerator;
        } else {
            os << r.numerator << "/" << r.denominator;
        }
        return os;
    }
    Rational operator+(const Rational &r) const {
        Rational res;
        res.numerator = this->numerator * r.denominator + this->denominator * r.numerator;
        res.denominator = this->denominator * r.denominator;
        simplify(res);
        return res;
    }
    Rational operator-(const Rational &r) const {
        Rational res;
        res.numerator = this->numerator * r.denominator - this->denominator * r.numerator;
        res.denominator = this->denominator * r.denominator;
        simplify(res);
        return res;
    }
    friend Rational operator*(const Rational &r1, const Rational &r2) {
        Rational res;
        res.numerator = r1.numerator * r2.numerator;
        res.denominator = r1.denominator * r2.denominator;
        simplify(res);
        return res;
    }
    friend Rational operator/(const Rational &r1, const Rational &r2) {
        Rational res;
        res.numerator = r1.numerator * r2.denominator;
        res.denominator = r1.denominator * r2.numerator;
        simplify(res);
        return res;
    }
    Rational &operator=(const Rational &r) {
        this->numerator=r.denominator;
        this->denominator=r.numerator;
        simplify(*this);
        return *this;
    }
    Rational operator++(int){
        Rational res = *this;
        this->numerator += this->denominator;
        simplify(*this);
        return res;
    }
    Rational& operator++(){
        this->numerator += this->denominator;
        simplify(*this);
        return *this;
    }
    Rational operator--(int){
        Rational res = *this;
        this->numerator -= this->denominator;
        simplify(*this);
        return res;
    }
    Rational& operator--(){
        this->numerator -= this->denominator;
        simplify(*this);
        return *this;
    }
};

void simplify(Rational &r) {
    if(r.numerator==0){
        r.denominator=1;
        return;
    }
    if(r.denominator<0){
        r.numerator=-r.numerator;
        r.denominator=-r.denominator;
    }
    int g = gcd(abs(r.numerator), abs(r.denominator));
    r.numerator /= g;
    r.denominator /= g;
}
int main(){
    int n_a,d_a,n_b,d_b;
    cin>>n_a>>d_a>>n_b>>d_b;
    Rational a(n_a,d_a),b(n_b,d_b);
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    a++,b++;
    cout<<a<<" "<<b<<endl;
    // to fit the test data
    a--,b--;
    Rational R1;
    Rational R2;
    R1=a;
    R2=b;
    cout<<R1<<" "<<R2<<endl;
    return 0;
}