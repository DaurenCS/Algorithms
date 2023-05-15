#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * right, *left;
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
        void add(int * a, int n){
            node * res = this->fun(root,a,0,n-1);
            if(root == NULL){
                root = res;
            }
        }
        void print(){
            this->print(root);
        }
        
    private: 
        node * root;

        node * fun(node * cur, int * a, int l, int r){
            if(l > r ){
                return NULL;
            }
            
            cur = new node(a[(l+r)/2]);
            cur->left = fun(cur->left,a, l , ((l+r)/2)-1 );
            cur->right = fun(cur->right,a, ((l+r)/2)+1,r);
            return cur;
    
        }
        void print(node * cur){
            if(cur != NULL){
                cout<<cur->val<<" ";
                print(cur->left);
                
                print(cur->right);
            }
        }

};

int main(){
    bst * b = new bst();
    
    int n; cin>>n;
    n = pow(2,n)-1;
    int a[n];
    for(int i = 0; i<n; i++ ){
        cin>>a[i];
        
    }
    sort(a, a+n);

    b->add(a,n);

    b->print();

    

    
}