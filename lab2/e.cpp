#include <iostream>

using namespace std; 

class node  
{  
    public: 
    string data;  
    node* next;  
};  
  

int getCount(node* head)  
{  
    int cnt = 0; 

    node* temp = head;
    while(temp != NULL){
    	cnt++;
    	temp = temp->next;
    }

    return cnt;  
}  
void removeDuplicates(node* head)  
{  
	node* temp = head;
	if(temp == NULL || temp->next == NULL)
		return;

	string cur_data = temp->data;
	while(temp->next != NULL){
		if(cur_data == temp->next->data){
			node* node = temp->next;
			temp->next = node->next;
			delete node;
		}
		else{
			temp = temp->next;
		}
		cur_data = temp->data;
	}
}  



void push(node** head_ref, string new_data)  
{  

    node* new_node = new node(); 
    new_node->data = new_data;  

    new_node->next = (*head_ref);      
    (*head_ref) = new_node;  
}  
 

void printList(node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}