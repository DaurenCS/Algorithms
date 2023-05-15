#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * right,* left;
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
        void p(){
            int n = getLevel(root);
            int a[n];
            
            for(int i=0; i<n; i++){
                a[i]=0;
                }
                dfs(root,a,0);
            for(int i=0; i<n; i++){
                cout<<a[i]<<" ";
                }
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
        int getLevel(node * cur){
            if(cur == NULL)return 0;

            return 1+ max(getLevel(cur->left),getLevel(cur->right));
        }

        void dfs(node * cur, int * a, int lev){
            if (cur == NULL)return;
            a[lev] += cur->val;
            dfs(cur->left,a,lev+1);
            dfs(cur->right,a,lev+1);


        }
        


};

int main(){
    int x; cin>>x;
    bst * b = new bst();

    for(int i =0; i< x; i++){
        int a;cin>>a;
        b->add(a);
    }
    b->p();
    
}