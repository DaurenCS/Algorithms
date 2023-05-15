#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * right, * left;
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
            node * res = add(root,x);
            if(root == NULL){
                root = res;
            }
        }
        void pr(){
            cout<< this->dfs(root,0);
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

        void print(node * cur){
            if(cur != NULL){
                print(cur->left);
                cout<< cur->val<<" ";
                print(cur->right);
            }
        }

        

        int dfs(node * cur, int sum){
            if(cur == NULL)return 0;

            sum = sum * 10 + cur->val;
            if(cur->left==NULL && cur->right==NULL){
                return sum;
            }
            return dfs(cur->right, sum) + dfs(cur->left,sum);
    
        } 
};

int main(){
    bst * b = new bst();

    int x; cin>>x;
    for(int i =0; i<x; i++){
        int a; cin>>a; 
        b->add(a);        
    }
    b->pr();

}