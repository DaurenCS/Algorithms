#include<bits/stdc++.h>

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
        void lca(int a, int b){
            cout<< this->lca(root, a,b)->val;
        }
        void add(int x){
            node * res = this->add(root,x);
            if(root == NULL){
                root = res;
            }
        }
        
    private:
        node * root;
        node * add(node * cur,int x){
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
        node * lca(node * cur, int a, int b){
            while(cur != NULL){
                if(cur->val > a && cur->val > b)
                    cur = cur->left;
                else if(cur->val < a && cur->val < b)
                    cur = cur->right;
                return cur;
                
            }
            return cur;
        }
        
        
};

int main(){
    bst * b = new bst();

    int s; cin>>s;

    for(int i = 0; i < s; i++){
        int x; cin>>x;
        b->add(x);
    }
    
    int x,y;
    cin>>x>>y;
    b->lca(x,y);
}