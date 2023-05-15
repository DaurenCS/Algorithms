#include<bits/stdc++.h>

using namespace std;


int m;




int bfs(int ar, vector<int> v[], bool col[]){
    if(col[ar])return 0;
    bool ind[m+1];
    int cnt[m+1];
    for(int i =0; i<m+1; i++){
        ind[i] = false;
        cnt[i] = INT_MAX;
    }

    queue<int> q;
    q.push(ar);
    ind[ar]= true;
    cnt[ar] = 0;

    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(int j =0; j<v[i].size(); j++){
            if(!ind[v[i][j]]){
                ind[v[i][j]]= true;
                cnt[v[i][j]] = cnt[i]+1;
                if(col[v[i][j]])return cnt[v[i][j]];
                q.push(v[i][j]);
    
            }
             
        }    
    }
    return -1;
}

int main(){
    int n,x;
    cin>>m>>n>>x;

   vector<int> v[m+1];
   bool col[m+1];
    for(int i =0; i<m+1; i++)
        col[i] = false;

    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i =0; i<x; i++){
        int t,c; cin>>t>>c;
        if(t == 1){
           col[c] = true;
           }
        else{
            cout<<bfs(c,v,col)<<endl;
        }

    }
   
}