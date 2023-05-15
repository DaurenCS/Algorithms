#include <bits/stdc++.h>
using namespace std;

struct node{
    char val;
    node *next;
    node(char x){
        val = x;
        next = NULL;
    }
};

int fun(struct node *head){
   unordered_map<int, int> freqMap;
   for (node *temp=head; temp!=NULL; temp=temp->next){
      freqMap[temp->val]++;
   }
   for (node *temp=head; temp!=NULL; temp=temp->next){
      if (freqMap[temp->val] == 1){
         return temp->val;
      }
   }
   return -1;
}
int main(){
    int n;cin >> n;
    while(n--){
        node *head, *cur;
        int x;cin >> x;
        int s = 0;
        for(int i = 0; i < x; i++){
            char c;cin >> c;
            bool ok = false;
            if(i == 0){
                head = new node(c);
                cur = head;
            }else{
                cur->next = new node(c);
                cur = cur->next;
            }
            if(fun(head) != -1)
                cout << char(fun(head)) << ' ';
            else cout << -1 << ' ';
        }
        cout << endl;
    }

    return 0;
}