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
         int maxW(){
            int m = 0;
            for(int i = 1; i<= this->height(root); i++){
                m = max(m, width(root,i));
            }
            return m;
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

        int width(node * cur, int lvl){
            if(cur == NULL)return 0;
            if(lvl == 1)return 1;

            return width(cur->left, lvl-1) + width(cur->right,lvl-1); 
        }

        int height(node * cur){
            if(cur == NULL)return 0;

            return 1+ max(height(cur->left),height(cur->right));
        }
};