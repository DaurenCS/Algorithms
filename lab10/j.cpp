#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> parent, ind, child;
vector<vector<int>> a;

void dfs2(int v, int vis[]){
    vis[v] = 1;
    for(int i : a[v]){
        if(not vis[i])
            dfs2(i, vis);
    }
}

void dfs(int x){
    ind[x] = 1;
    int cnt = 0;
    // if(x == root)cnt++;
    for(int i = 0; i < a[x].size(); i++){
        if(not ind[a[x][i]]){
            parent[a[x][i]] = x;
            cnt++;
            child[x] = cnt;
            dfs(a[x][i]);
        }
    }
}

int res(){
    int vis[n+1];
    for(int i = 0; i < n + 1; i++){
        vis[i] = 0;
    }
    int cnt = 0;
    for(int i = 1; i < n+1; i++){
        if(not vis[i]){
            dfs2(i, vis);
            cnt++;
            
        }
    }

    return cnt;
}


int main(){
    cin>>n>>m;
    int x,v;
    a.assign(n+1, vector<int>());
    ind.assign(n+1, 0);
    parent.assign(n+1, 0);
    child.assign(n+1, 0);
    for(int i =0; i<m; i++){
        cin>>x>>v;
        a[x].push_back(v);
        a[v].push_back(x);
    }

    for(int i = 0; i < n+1; i++){
        ind[i] = 0;
        parent[i] = 0;
        child[i] = 0;
    }

    for(int i = 0; i<n; i++){
        if(!ind[i])
            dfs(i);
    }

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(child[parent[i]] < child[i] && parent[i])
            cnt++;
    }

    cout << res() + cnt;

    return 0;

}