#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * right, * left;
    node(int x){
        right = left = NULL;
        val = x;
    }
};

struct bst{
    public:
    bst(){
        root = NULL;
    }

    void add(int x){
        node * res = add(root,x);
        if(root == NULL){
            root = res;
        }
    }
    void h(){
        cout<<this->height(root);
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

    int height(node * cur){
        if(cur== NULL)
            return 0;
        
        return 1 + max(height(cur->left),height(cur->right));
    }
    bool bal(node* cur){
        if(cur== NULL)return true;
        
    }
    
};

int main(){
    bst * b = new bst();
    int x; cin>>x;

    for(int i = 0; i < x; i++){
        int a;cin>>a;
        b->add(a);
    }

    b->h();
}