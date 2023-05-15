#include<iostream>

using namespace std;

struct node{
    int val;
    int cnt;
    
    node* left,* right;
    node(int x){
        val = x;
        right = left = NULL;
    }

};

struct bst{
    public:
        bst(){
            root = new node(1);
        }
       
        void add(int x,int y, int z){   
            this->add(root,x,y,z);

        }
        int maxW(){
            int m = 0;
            for(int i = 1; i<= this->height(root); i++){
                m = max(m, width(root,i));
            }
            return m;
        }
        void pr(){
            this->pr(root);
        }

    private:
        node * root;
        void add(node * cur,int x,int y, int z){
            if (cur == NULL){
                return;
            }
            if(cur->val == x){
                if(z == 1){
                    cur->right = new node(y); 
                }
                else
                    cur->left = new node(y);
                return;
            }
            add(cur->left,x,y,z);
            add(cur->right,x,y,z);
        }

        int width(node * cur, int lvl){
            if(cur == NULL){
                return 0;
            }
            if(lvl == 1){
                return 1;
            }
            return width(cur->right, lvl-1) + width(cur->left, lvl-1);
        }

        int height(node * cur){
            if(cur == NULL)return 0;
            return 1+ max(height(cur->left),height(cur->right));
        }

        void pr(node * cur){
            if(cur!=NULL){
                pr(cur->left);
                cout<<cur->val<<" ";
                pr(cur->right);
            }
        }

        
        

};

int main(){
    bst * b = new bst();

    int a; cin>>a;

    for (int i = 0; i<a-1; i++){
        int x,y,z;
        cin>>x>>y>>z;
        b->add(x,y,z);
    }
    
    cout<<b->maxW();

    
}
