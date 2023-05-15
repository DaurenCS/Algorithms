    #include<iostream>

    using namespace std;

    struct node{
        int val;
        node * left;
        node * right;
        int cnt;
        node(int val){
            this->val = val;
            this->left = this->right = NULL;
        }

    };

    struct bst{
        public:
        bst(){
            root = NULL;
        }
        void add(int x){
            node * res = this->add(this->root,x);
            if(root == NULL){
                root = res;
            }
        }
        void print(){
            this->findTriangle(root);
            cout<<cnt;
        
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
                else{
                    add(cur->left,x);
                }
            }
            else if(cur->val < x){
                if(cur->right == NULL){
                    cur->right = add(cur->right, x);
                }
                else{
                    add(cur->right,x);
                }
            }
            return cur;
        }
        int cnt = 0;
        void findTriangle(node * temp){

            if(temp == NULL){
                return;
            }
            if(temp->left != NULL && temp ->right != NULL){
                cnt++;
            }
                findTriangle(temp->left);
                findTriangle(temp->right);
                
        }
        
        void print(node * cur ){
            if(cur!= NULL){
                print(cur->left);
                cout<<cur->val<<" ";
                print(cur->right);
            }
        }
                
    };

    int main(){
        int x; cin>>x;
        bst* b = new bst();

        for(int  i = 0; i < x; i++){
            int a; cin>>a;
            b->add(a);
            
        }
        
        b->print();

    }