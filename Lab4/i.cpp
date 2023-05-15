#include<iostream>
using namespace std;


struct node{
    int val;
    int cnt;
    node * right, * left;
    node(int x){
        val = x;
        cnt = 1;
        right = left = NULL;
    }
};

struct bst{
    public:
        bst(){
            root = NULL;
        }
        void add(int x){
            node * res = this->add(root,x,false);
            if(root == NULL){
                root = res;
            }
        }
        void del(int x){
            node * res = this->add(root,x,true);
            if(root == NULL){
                root = res;
            }
        }
        void print(){
            this->print(root);
        }
        void search(int x){
            cout<<this->search(root, x)<<endl;
        }
        
    private:
        node * root;
        node * add(node * cur , int x, bool f){
            if (cur == NULL){
                cur = new node(x);
            }
            else if(cur -> val > x){
                if(cur -> left == NULL){
                    cur->left = add(cur->left,x, f);
                }
                else{
                    add(cur->left,x,f );
                }
            }
            else if(cur->val < x){
                if(cur->right == NULL){
                    cur->right = add(cur->right,x,f);
                }
                else {
                    add(cur->right ,x,f);
                }
            }
            
            else if(cur->val == x){
                if(f == false)
                    cur->cnt ++;
                else
                    cur->cnt--;
            }
            return cur;
        }
        int search(node * cur, int x){
            while(cur!= NULL){
                if(cur->val == x){
                    return cur->cnt;
                }
                else if(cur->val > x)
		        	cur = cur->left;
		
	        	else
			        cur = cur->right;
            }
            return 0;

        }
        void print(node * cur){
            if(cur != NULL){
                print(cur->left);
                cout<< cur->cnt<<" ";
                print(cur->right);
            }
        }
};

int main(){
    bst * b = new bst();
    int x; cin>>x;

    for(int i =0; i<x; i++){
        string s; cin>>s;
        int a; cin>>a;
        if(s == "insert"){
            b->add(a);
        }
        else if(s == "cnt"){
            b->search(a);
        }
        else if(s == "delete"){
            b->del(a);

        }
    }
    
}