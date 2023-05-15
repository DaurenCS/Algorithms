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
    ll(){
        head = NULL;
        tail = NULL;
    }
    void add(string x){
        node * n = new node(x);
        
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
           
        }
        cout<<"ok"<<endl;
    }
    void push(node** head_ref, string new_data){
        if((*head_ref) == NULL ){
            add(new_data);
        }
        else{
            node* new_node = new node(new_data);
            new_node->next = (*head_ref);
            (*head_ref) = new_node;
            cout<<"ok"<<endl;
        }
        
}

    void remove_f(){
        if(head == NULL){
            cout<<"error"<<endl;
        }
        else{
            node * cur = head;
            cout<<cur->val<<endl;
            head = head->next;
            delete cur;
        }
}
    void remove_b(){
        if(head == NULL){
           cout<<"error"<<endl; 
           return;
        }
           
        string res = head->val;

        if(head->next == NULL){
            head = NULL;
            free(head);
            cout<<res<<endl;

        }
    }
              
    void front(){
        if(head == NULL){
            cout<<"error"<<endl;
            return;
        }
        else
            cout<< head->val<<endl;
    }
    void back(){
        if(head == NULL){
            cout<<"error"<<endl;
            return;

        }
            
        node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        cout<<temp->val<<endl;
     }
     void clear(){
        while(head != NULL){
            node* temp = head;
            head = head->next;
            delete temp;
        }
        cout<<"ok"<<endl;
    }
    
};


int main(){

    ll l;

    while(true){
        string i;
        cin>>i;
        if(i == "exit"){
            cout<<"goodbye";
            break;
        }
        else if(i == "add_back"){
            string a; cin>>a;
            l.add(a);
        
        }
        else if(i == "add_front"){
            string a; cin>>a;
            l.push(&l.head,a);
            
        }
        else if(i == "erase_front"){
            l.remove_f();
            

          
        }
        else if(i == "erase_back"){
            l.remove_b();
            
           
        }
        else if(i == "back"){
            l.back();
            
        }
        else if(i == "front"){
            l.front();
            
        }
        else if(i == "clear"){
            l.clear();
        }

    }

    


}