#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * next;
    node(int x){
        val = x;
        next = NULL;
    }
    // void print(){
    //     cout << val << endl;
    // }
};

struct ll{
    node * head;
    node * tail;
    ll(){
       head = NULL; 
       tail = NULL;
    }

    void add(int x){
        node * n = new node(x);
        if(head == NULL){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            tail = n;
        }
    }
        int Min(int x){
        node * current = head; 
        
        int Min = INT_MAX;
        while(current != NULL){
            if(Min > abs(current->val - x)){
                Min  = abs(current->val - x);
            }
            current = current->next;
        }  
        return Min;
         
    }
     void print(int x,int min){
        node * current = head; 
        int count = 0;
        
        while(current != NULL){
            if(min == abs(current->val - x)){
                cout<<count;
                break;
            }
            current = current->next;
            count++;
        }   
     }
};

int main(){

    ll l;

    int x; 
    cin>>x;

    for(int i = 0; i < x; ++i){
        int a;
        cin>>a;
        l.add(a);
    }

    int b; cin>>b;


    l.print(b,l.Min(b));

    return 0;
}