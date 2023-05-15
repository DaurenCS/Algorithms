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
    node * head;
    node * tail;
    node * end;
    ll(){
        head = NULL;
        tail = NULL;
    }
    void add(int x){
        node * n = new node(x);
        
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
           
        }
    }

    void insertAfter(node* prev_node, int new_data){
            node* new_node = new node(new_data);
            new_node->next = prev_node->next;
            prev_node->next = new_node;
    }
    
    void Print(){
        node * current = head; 
        while(current !=NULL){
                cout<<current->val<<" ";
                current = current->next;
            }

        }
    

};
int main(){
    ll l;
    int x; cin>>x;
    int cnt = 0;
    

    for(int i = 0; i<x; i++){
        int s;
        cin>>s;
            l.add(s);
    }
    int a,b; cin>>a>>b;
    
    if(b == 0){
        node * n = new node(a);
        n->next = l.head;
        l.head = n;

    }
    else{
        node * cur = l.head;
        for(int i = 0; i<b-1; i++){
            cur = cur->next;
        }
        l.insertAfter(cur, a);
    }



    
    
    l.Print();
     
}