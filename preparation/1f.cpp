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
            head = tail = new node(x); 
        }
        else{
            
            tail->next = n;
            tail = n;

        }
        }
    void insertAfter(int ind, int x){
        node * n = new node(x);
        node * cur = head;
        for(int i = 1; i < ind; i++){
            cur = cur->next;
        }
        n->next = cur->next;
        cur->next = n;
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
    ll * l = new ll();
    int x; cin>>x;
    for(int i = 0; i<x; i++){
        int a; cin>>a;
        l->add(a);
    }
    int a,b;
    cin>>a>>b;
    if(b == 0){
        node * n = new node (a);
        n->next = l->head;
        l->head = n;
    }
    else
        l->insertAfter(b,a);
    l->print();

}
    