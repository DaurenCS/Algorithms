#include<iostream>

using namespace std;

struct node{
    int val;
    
    node * right,*left;
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
        void print(int * a){
            this->sum(root,0,a);
        }
        
        int depth(){
           return this->depth(root);
        }


    private:
        node * root;
        
        int depth (node * cur){
            if(cur == NULL){
                return 0;
            }
            return 1 + max(depth(cur->left),depth(cur->right));
        }

        node* add(node * cur , int x){
            if(cur == NULL){
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
            else if( cur->val < x){
                if(cur->right == NULL){
                   
                    cur->right = add(cur->right,x);
                }
                else{
                    
                    add(cur->right,x);
                }
            }
            return cur;
        }
        void sum (node * cur, int level, int * a){
            if (cur == NULL){
                return;
            }
            a[level] += cur->val;
            sum(cur->left,level+1, a);
            sum(cur->right,level+1, a);

        }

};

int main(){
    int x; cin>>x;
    bst * b = new bst();

    for(int i = 0; i < x; i++){
        int a; cin>>a;
        b->add(a);
    }
    int n = b->depth();
    int a[n];
    for(int i =0; i< n; i++){
        a[i]=0;
    }

    b->print(a);

    cout<<n<<endl;

    for(int i =0; i<n; i++){
        cout<<a[i]<<" ";
    }

}