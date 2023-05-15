#include <iostream>

using namespace std;

struct node{
    int val;
    node * left, * right;
    node(int x){
        val = x;
        right = left = NULL;
    }
};

int c[1000];

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
    void fun(){
        path(root);
    }
    private:
    node * root;
    node * add(node * cur, int x){
        if (cur == NULL){
            cur = new node(x);
        }
        else if(cur->val > x){
            if(cur->left == NULL){
                cur->left = add(cur->left, x);
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

	void findCnt(node * cur, int ind){
		node * l = cur;
		node * r = cur;
		while(l->left != NULL && r->right != NULL){	
			c[++ind]++;
			r = r->right;
            l = l->left;
		}
	}

	void path(node* cur){
		if(cur == NULL)return;
		path(cur->left);
		path(cur->right);

        findCnt(cur, 1);

	}
};

int main(){
	bst * b = new bst();

	int n;
	cin >> n;

		
	for(int i=0; i<n; i++){
        c[i] = 0;
		int x; cin >> x;
		b->add(x);
	}

	b->fun();

	for(int i=2; i<=n; i++)
		cout<<c[i]<<' ';
}
