#include <iostream>

using namespace std;

struct node{
    int val;
    node * left, * right;
    node(int x){
        val = x;
        right = left = NULL;
    }
};

struct bst{
    public: 
    bst(){
        root = NULL;
    }
    void add(int x){
        node * res = this->add(root, x);
        if(root == NULL){
            root = res;
        }
    }
    void print(){
        int res = 0;
        this->print(root, res);

    }
    
    private:
    node * root;
    node * add(node * cur, int x){
        if (cur == NULL){
            cur = new node(x);
        }
        else if(cur->val > x){
            if(cur->left == NULL){
                cur->left = add(cur->left, x);
            }
            else
                add(cur->left,x);
        }
        else if(cur->val < x){
            if(cur->right == NULL){
                cur->right = add(cur->right,x);
            }
            else  
                add(cur->right,x);
        }
        return cur;
    }
    void print(node * cur, int& x){
        if(cur != NULL){
            print(cur->right ,x);
            x+= cur->val;
            cout<<x<<" ";
            print(cur->left, x);
        }
    }
};

int main(){
    bst * b = new bst();
    int x;
    cin>>x;
    
    for(int i = 0 ; i<x ; i++){
        int a; cin>>a;
        b->add(a);
        
    }
    b->print();

}
