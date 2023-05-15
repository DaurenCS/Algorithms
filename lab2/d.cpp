#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * next;
    int cnt; 
    node(int x){
        val = x;
        next = NULL;
        cnt = 1;
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
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        } 

    }

    void sort1(node * cur){
        node * temp = NULL;
        int t;
        int a;
        while(cur!= NULL){
            temp = cur->next;
            while(temp != NULL){
                if(cur->cnt > temp->cnt){
                    t = cur->cnt;
                    a = cur->val;
                    cur->cnt = temp->cnt;
                    cur->val = temp->val;
                    temp->cnt = t;
                    temp->val = a;
                }
                temp = temp->next;
            }
            cur = cur->next;
        }      
    }
    void mode(node * cur){
        node * temp = NULL;
        int t;
        while(cur!= NULL){
            temp = cur->next;
            while(temp != NULL){
                if(cur->val == temp->val){
                    cur->cnt++;
                }
                temp = temp->next;
            }
            cur = cur->next;
        }      
    }
    vector<int> v;

    int max(node * cur){
        while(cur->next!= NULL){
            cur = cur->next;
        }
        return cur->cnt;
    }
    void print1(){
        
        reverse(v.begin(), v.end());
        for(auto p:v){
            cout<<p<<" ";
        }
    }
    void addv(node * cur){
        int max1 = max(head);
        while(cur!=NULL){
            if(cur->cnt == max1)v.push_back(cur->val);
            cur=cur->next;
        }
        sort(v.begin(), v.end());
    }

};

int main(){
    int a;cin>>a;
    ll * l = new ll();

    for(int i =0; i < a; i++){
        int x;cin>>x;
        l->add(x);
    }
    
   
    l->mode(l->head);
    l->sort1(l->head);
    l->addv(l->head);
    
    l->print1();

}