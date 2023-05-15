#include<bits/stdc++.h>

using namespace std; 

struct node{
    string val;
    node * next;
    node(string x){
        val = x;
        next = NULL;
    }
};

struct ll{
    node * head, * tail, * end;
    ll(){
        head = NULL;
        tail = NULL;
    }

    void add(string x){
        node * n = new node(x);
        if(head == NULL){
            head = n;
            tail = n;
            end = n;
        }
        else{
            tail->next = n;
            tail = n;
            end = tail;
            end->next = head;
        }
    }

    void print(int a, int b){
        node * cur = head;
        for(int i = 0; i < a; i++ ){
                cur = cur->next;
            }
        for(int i =0; i< b; i++){
            cout<<cur->val<<" ";
            cur = cur->next;
            a++;
            
        }
    }
};

int main(){
    ll * l = new ll();
    int a,b;cin>>a>>b;

    for(int i = 0; i<a; i++){
        string x;cin>>x;
        l->add(x);
    }
    l->print(b,a);



}

