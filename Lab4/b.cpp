#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->cnt = 0;
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
    void print(int x){
        cout<<this->countNode(Search(x));
    }
    
    node * Search(int data){
	
	node *temp = root;
	
	
	while(temp != NULL)
	{
		
		if(temp->val == data)
		{
			
			return temp;
		}
		
		else if(temp->val > data)
			temp = temp->left;
		
		else
			temp = temp->right;
	}
 
	
	return temp;
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
    
      int countNode(node * root){

        
        if(root==NULL)
            return 0;

        return 1 + countNode(root->left) + countNode(root->right);
    }
    
};


int main(){
    bst * b = new bst();
    

    int x; cin>>x;
    
    for(int i =0; i<x; i++){
        int a; cin>>a;
        b->add(a);
    }
    
   int a; cin>>a;
        b->print(a);

    return 0;
}