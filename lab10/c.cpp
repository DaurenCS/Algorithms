#include<bits/stdc++.h>

using namespace std;
vector<long long> v;

int bfs(int a, int b,vector<bool> ind){
    queue<pair<long,long>> q;
    q.push(make_pair(a,0));
    map<long, long> prev;
    prev[a] = -1;
    ind[a] = true;
    while(q.size() > 0){
        pair<long,long> i = q.front();
        q.pop();
        
        if(i.first == b){
            cout<< i.second<<endl;
            break; 
        }


        if(2*i.first < 10000 && !ind[i.first*2]){
            ind[i.first*2] = true;
            prev[2*i.first] = i.first;
            q.push(make_pair(i.first*2, i.second+1));
            
        }
            
        if (!ind[i.first-1] && i.first - 1 >= 0 ) {
            ind[i.first-1] = true;
            prev[i.first-1] = i.first;
            q.push(make_pair(i.first-1, i.second+1));
            
        }

    }
    // for(auto x : prev)cout << x.first << ' ' << x.second << endl; 
    v.push_back(b); 
    while(1){ 
        if(v[v.size()-1] == a)break; 
        else v.push_back(prev[v[v.size()-1]]); 
    }  

}

int main(){
    int a,b;
    cin>>a>>b;
    vector<bool> ind(10000,false);

    bfs(a,b,ind);

    for(int i =v.size()-2; i >= 0; i--){
        cout<<v[i]<<" ";
    }

}