//
// Created by 田佳业 on 2023/4/30.
//
#include<bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    int n;
    vector<int> v;
    int temp;
    while (tc--) {
        cin >> n;
        v.clear();
        v.reserve(n);
        while (n--) {
            // considering the performance, push_back() and then reverse() is better than insert() at the beginning
            cin >> temp;
            auto it = find(v.begin(), v.end(), temp);
            if (it == v.end()) {
                v.push_back(temp);
            } else {
                //move *it to the end of the vector
                v.erase(it);
                v.push_back(temp);
            }
        }
        reverse(v.begin(), v.end());
        for (int & it : v) {
            cout << it << " ";
        }
        cout<<endl;
    }
}