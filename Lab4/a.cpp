#include <iostream>

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
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print(){
        this->print(this->root);
    }
    
    void fun(string s){
        node * cur = root;
        int cnt = 0;
        for(int i =0; i<s.length(); i++){
                if(s[i] == 'L'){
                    if(cur->left == NULL){
                        break;
                    }
                    else{
                        cur = cur->left;
                    }
                   
                    
                }
                else if(s[i] == 'R'){
                    if(cur->right == NULL){
                        break;
                    }
                    else{
                        cur = cur ->right;
                    }
                }
                cnt++;
        }
        
        if(cnt == s.length() ){
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }

    private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
            }
        }
        return current;
    }
    
    void print(node * current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }
    
};


int main(){
    bst * b = new bst();
    

    int x,y; cin>>x>>y;
    string arr[y];
    for(int i =0; i<x; i++){
        int a; cin>>a;
        b->add(a);
    }
    for(int i = 0; i<y; i++){
        string a;
        cin>>a;
        arr[i] = a;

    }
    for(int i =0; i<y; i++){
        b->fun(arr[i]);
    }

    
    

    return 0;
}