#include<bits/stdc++.h>

using namespace std;

struct node {
    string val;
    node * next, * prev;
    node(string x){
        val = x;
        next = prev = NULL;
    }
};

struct ll{
    node * head, * tail;

    ll(){
        head = tail = NULL;
    }

    void add(string x){
        node * cur = head;
        while(cur!= NULL){
            if(cur->val == x){
                return;
            }
            cur = cur->next;
        }
        node * n = new node(x);      
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void print(node * cur){
        while(cur != NULL){
            cout<<cur->val<<endl;
            cur = cur->next;
        }
        
    }
    

};

int main(){
    int a;cin>>a;
    ll * l = new ll();

    for(int i =0; i < a; i++){
        string x;cin>>x;
        l->add(x);
    }
    l->print(l->head);

}