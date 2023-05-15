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
    node * head,* tail;
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
    int min(int x){
        int min = INT_MAX;
        node * cur = head;
        while(cur != NULL){
            if(min> abs(cur->val -x)){
                min = abs(cur->val -x);
            }
            cur = cur->next;
        }
        return min;
    }
    int ind(int x,int min){
        node * cur = head;
        int cnt = 0;
        while(cur != NULL){
            if( min == abs(cur->val-x)){
                return cnt;
            }
            cur = cur->next;
            cnt++;
        }
    }
};

int main(){
    ll * l = new ll();

    int x; cin>>x;
    for(int i = 0; i<x ; i++){
        int a;cin>>a;
        l->add(a);
    }
    int s; cin>>s;
    cout<< l->ind(s,l->min(s));
}