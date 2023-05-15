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
    node * head;
    node * tail;
    node * end;
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
            end = n;
            end->next = head;
        }
    }
    
    void Print(int k,int b){
        node * current = head; 
        for(int i = 0; i< k+b; i++){
            if(i >= b){
                cout<<current->val<<" ";
                current = current->next;
            }
            else
            current = current->next;

        }
    }

};
int main(){
    ll l;
    int x,y; cin>>x>>y;
    int cnt = 0;
    

    for(int i = 0; i<x; i++){
        string s;
        cin>>s;
        
            l.add(s);
    }
    l.Print(x,y);
    
    
     
}