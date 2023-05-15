#include<iostream>

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
            node * res = this->add(root,x);
            if(root == NULL){
                root = res;
            }
        }
        void print(){
            cout<<this->diameter(root);
        }
        
    private: 
        node * root;
        node * add(node * cur, int x){
            if (cur == NULL){
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
                    cur->right = add(cur->right,x);
                }
                else{
                    add(cur->right,x);
                }
            }
            return cur;
        }
        void print(node * cur){
            if(cur != NULL){
                print(cur->left);
                cout<<cur->val<<" ";
                print(cur->right);
            }
        }
        int height(node * cur){
            if(cur == NULL)
                return 0;
            return 1+ max(height(cur->left),height(cur->right));
        }

        int diameter(node * cur){
            if (cur == NULL)
                return 0;
            return max(1+height(cur->left)+height(cur->right), max(diameter(cur->left),diameter(cur->right)));
        }
};

int main(){
    bst * b = new bst();
    int a;
    cin>>a;

    for(int i = 0; i<a; i++){
        int x; cin>>x;
        b->add(x);
    }

    b->print();
}