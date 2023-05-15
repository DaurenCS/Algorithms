#include <bits/stdc++.h>

using namespace std;




int main () {
    int n;
    int k = 0;
    int s = 0;
    cin >> n;
    string st;
    cin >> st;
    queue <char> ks;


    for (int i = 0; i < st.size(); i++){
            ks.push(st[i]);
        }

    while (k > ks.size() || s > ks.size() ){
        
        if (ks.front() == 'S' and s == 0){
            k+=1;
            ks.push('S');
            ks.pop();
               
        }
        else if(ks.front() == 'K' && k == 0){
            s+=1;
            ks.push('K');
            ks.pop();
            
            
            
            
        }
        else if(ks.front() == 'K' && k != 0){
            k-=1;
            ks.pop();
            
            
        }
        else if(ks.front() == 'S' && s != 0){
            s-=1;
            ks.pop();
            
        }

    }

   if(ks.front()=='S'){
    cout<<"SAKAYANAGI";
   }
   else if(ks.front()=='K')
   cout<<"KATSURAGI";
    
}