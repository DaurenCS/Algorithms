#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * next,*prev;
    node(int x){
        val = x;
        next = prev =  NULL;
    }

};

struct ll{
    node * head;
    node * tail;
    ll(){
        head = tail = NULL;
    }

    void add(int x){
        node * n = new node(x);
        if(head == NULL){
            head = n;
            
        }
        else {
            n->next = head;
            this->head = n;
        }

    }

    void del(node * cur){
        head = head->next;
        delete cur;
    }

    int getMax(node * cur){
        int max = INT_MIN;
        while(cur!= NULL){
            if(max<cur->val){
                max = cur->val;
            }
            cur = cur->next;
        }
        return max;
    }
};

int main(){
    int x; cin>>x;
    ll * l = new ll();
    
    for(int i =0; i<x; i++){
        string s; cin>>s;
        if(s == "add"){
            int a;cin>>a;
            l->add(a);
        }
        else if(s == "delete"){
            l->del(l->head);
        }
        else if(s == "getmax"){
             if(l->head == NULL){
                cout<<"error"<<endl;
            }
            else
            cout<< l->getMax(l->head)<<endl;
        }
        else if(s == "getcur"){
            if(l->head == NULL){
                cout<<"error"<<endl;
            }
            else
            cout<<l->head->val<<endl;
        }
    }

    // l->print();
}