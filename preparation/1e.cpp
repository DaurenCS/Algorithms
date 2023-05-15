#include<bits/stdc++.h>

using namespace std;

struct node{
    string val; 
    node * next, * prev;
    node(string x){
        val = x;
        next = prev = NULL;
    }

};
struct ll{
    node * head,* tail;
    ll(){
        head = tail = NULL;
    }
    void add(string x){
        node * cur = head;
        if(head == NULL){
            head = tail = new node(x);
        }
        else{
            while(cur!= NULL){
                if(cur->val == x){
                    return;
                }
                cur = cur->next;
            }
            node * n = new node(x);
            tail->next = n;
            n->prev = tail;
            tail = n; 
        }

    }
    void print(node * cur){
        while(cur!= NULL){
            cout<< cur->val<<'\n';
            cur = cur->prev;
        }
        
    }
    int getCnt(){
        int cnt = 0;
        node * cur = head;
        while(cur!= NULL){
            cnt++;
            cur = cur->next;
        }
        return cnt;
    }

};

int main(){
    int a;cin>>a;
    ll * l = new ll();

    for(int i =0; i<a; i++){
        string s; cin>>s;
        l->add(s);
    }
    cout<<"All in all: "<<l->getCnt()<<endl<<"Students:\n";

    l->print(l->tail);
}