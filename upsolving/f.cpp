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
        
        cout<<this->dfs(root, 0);

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
    int dfs(node * cur, int lvl){
        if(cur == NULL)return 0;

        return cur->val- lvl + dfs(cur->left,lvl+1) + dfs(cur->right,lvl+1);
    }


};
int main(){
    int x; cin>>x;
    bst * b = new bst();
    for(int i=0; i<x; i++){
        int a;cin>>a;
        b->add(a);
    }

    b->print();
}