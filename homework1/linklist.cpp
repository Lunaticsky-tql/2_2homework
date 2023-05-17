//
// Created by 田佳业 on 2023/4/7.
//
#include<bits/stdc++.h>

using namespace std;
struct node {
    int data;
    node *next;
};

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

class LinkList {
private:
    node *head;
    int len;
public:
    LinkList() {
        head = nullptr;
        len = 0;
    }

    void insert(int num) {
        //insert a num orderly
        node *new_node = new node;
        new_node->data = num;
        new_node->next = nullptr;
        if (head == nullptr) {
            head = new_node;
            return;
        }
        if (num < head->data) {
            new_node->next = head;
            head = new_node;
            return;
        }
        node *cur = head;
        // find the position to insert
        while (cur->next != nullptr && cur->next->data < num) {
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
        len++;
    }

    void print_list() {
        node *cur = head;
        int last_prime = 0;
        int count=0;
        while (cur != nullptr) {
            if (cur->data != last_prime) {
                if(count==len-1)
                    cout << cur->data;
                else
                {
                    cout << cur->data << " ";
                }
                last_prime = cur->data;
            }
            cur = cur->next;
            count++;
        }
    }

    ~LinkList() {
        node *cur = head;
        while (cur != nullptr) {
            node *temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

int main() {
    LinkList l;
    int n;
    while (cin >> n) {
        if (is_prime(n)){
            l.insert(n);
        }
        else{
            break;
        }
    }
    l.print_list();
    return 0;
}