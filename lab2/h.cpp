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
    node* head;
    node* tail;
    ll(){
        head = NULL;
        tail = NULL;
    }

    void add(node * node1 ,int x){
        if (head == NULL){
            head = node1;
            return;
        }

        if (x == 0){
            node1->next = head;
            head = node1;
            return;
        }

        node * temp = head;
        while (x != 1)
        {
            temp = temp->next;
            x--;
        }

        node1->next = temp->next;
        temp->next = node1;

    }
    void remove(int x){
          if (x == 0){
                node * cur = head;
                head = head->next;
                delete cur;
                
            }
            else{

                node *temp = head;
                while (x != 1)
                {
                    temp = temp->next;
                    x--;
                }

                node *cur = temp->next;
                temp->next = cur->next;
                delete (cur);
            }
            
    }
    void replace( int p1, int p2 ){
        if (p1 == p2)
            return;
        node *node1 = head;
        for (int i = 0; i < p1; i++){
            node1 = node1->next;
            }
        node * n = new node(node1->val);
        if(p1 < p2){
           add(n, p2+1);
            remove(p1); 
        }
        else{
            add(n, p2);
            remove(p1+1);
        }
    
        
           
    }
    void reverse(){
        node *prev = NULL, *cur = head;
        while (cur != NULL)
        {
            node *nextt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextt;
        }
        head = prev;
    }
    void cyclic_right(int x){
        if (x == 0)
            return;
        node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = head;
        while (x--)
        {
            head = head->next;
            tail = tail->next;
        }
        tail->next = nullptr;
    }
    void cyclic_left(int x) {
        if (x == 0)
            return ;
        int c = 0;
        node *cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            c++;
        }
        cyclic_right(c - x);
        } 

    
    void Print(node * n){
        node * current = n; 
        if(current == NULL){
            cout << -1 << endl;
            return;
        }
        while(current !=NULL){
                cout<<current->val<<" ";
                current = current->next;
            }
            cout<<endl;
    }
};


int main(){
    ll l;

    while(true){
        int i;
        cin>>i;
        if(i == 0){
            break;
        }
        else if(i == 1){
            int a,b; cin>>a>>b;
            node * new_n = new node(a);
              l.add(new_n,b);
            
            
        }
        else if(i == 2){
            
            int x; cin>>x;
            l.remove(x);
        }
        else if(i == 3){
            
            l.Print(l.head);
        }
        else if(i == 4){
            int a,b; cin>>a>>b;
            l.replace(a,b);
        }
        else if(i == 5){
            l.reverse();
        }
        else if(i == 6){
            int a, b; cin>>a;
            l.cyclic_right(a);
        }
        else if(i == 7){
            int a, b; cin>>a;
            l.cyclic_left(a);

        }
    }
    
    

    
    

}