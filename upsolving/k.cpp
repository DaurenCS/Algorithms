#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * next;

    node(int x){
        val = x;
        next = NULL;
    }

};

struct ll{
    node * head, * tail;
    ll(){
        head = tail = NULL;
    }

    void add(int x){
        node * n = new node(x);
        if(head == NULL){
            head = tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        } 

    }

    void add_front(int x){
        node * n = new node(x);
        if(head == NULL){
            tail = head = n;
        }
        else{
            n->next = head;
            head = n;
        }
    }

    void print(){
        node * cur = head;
        while(cur!= NULL){
            cout<<cur->val<<" ";
            cur = cur->next;
        }

    }

};


int main(){

    int x; cin>>x;
    ll * l1 = new ll();
    ll * l2 = new ll();
    

    for(int i = 0; i<x; i++){
        int a; cin>>a;
        if(a == 1){
            int s; cin>>s;
            l1->add(s);
            l2->add_front(s);
        }
        else if(a==2){
            ll * t = l1;
            l1 = l2;
            l2 = t;
        }
    }
    l1->print();
}