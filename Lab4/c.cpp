#include<iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }

};

struct bst{
    public:
    bst(){
        root = NULL;
    }
    void add(int x){
        node * res = this->add(this->root,x);
        if(root == NULL){
            root = res;
        }
    }
    void print(int x){
        cout<< x<<" ";
        this->print(fun(x));

    }
    
    
    private:
    node * root;
    node * add(node * cur, int x){
        if(cur == NULL){
            cur = new node(x);
        }
        else if(cur->val > x){
            if(cur->left == NULL){
                cur->left = add(cur->left,x);
            }
            else{
                add(cur->left,x);
            }
        }
        else if(cur->val < x){
            if(cur->right == NULL){
                cur->right = add(cur->right, x);
            }
            else{
                add(cur->right,x);
            }
        }
        return cur;
    }
    node* fun(int x){
        node * temp = root;
        while(temp != NULL){
            if(temp ->val == x ){
                return temp;
            }
            else if(temp->val > x){
                temp= temp -> left;
            }
            else {
                temp = temp->right;
            }
        } 
        return temp;
        
    }
    void print(node * cur){
        if(cur == NULL){
            return;
        }
        if(cur->left!= NULL){
            cout<<cur->left->val<<" ";
        }
         print(cur->left);
        if(cur->right != NULL){
            cout<<cur->right->val<<" ";
        }
        
        print(cur->right);
        
    }
            
};

int main(){
    int x; cin>>x;
    bst* b = new bst();

    for(int  i = 0; i < x; i++){
        int a; cin>>a;
        b->add(a);
        
    }
    int a;
    cin>>a;
    b->print(a);

}