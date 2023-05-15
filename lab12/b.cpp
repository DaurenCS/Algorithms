#include<bits/stdc++.h>

using namespace std;

#define INF 100000000
            
// dijkstra
int solve(int a, int b, vector<pair<int,int>> g[],int n) {
    vector<int> d(n+1, INF);
    d[a] = 0;
    set<pair<int,int>> q;
    q.insert(make_pair(d[a],a));
    while(!q.empty()){
        int i = q.begin()->second;
        q.erase(q.begin());
        for(int j = 0; j<g[i].size(); j++){
            if(d[g[i][j].first] > d[i] + g[i][j].second){
                q.erase(make_pair(d[g[i][j].first],g[i][j].first));
                d[g[i][j].first] = d[i]+ g[i][j].second;
                q.insert(make_pair(d[g[i][j].first],g[i][j].first));
            }
        }
    }
    return d[b];
} 


int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int, int>> g[n+1];

    for(int i =0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;

    int a = solve(x1,x2,g,n)+solve(x2,x3,g,n) + solve(x3,x4,g,n);
    int b = solve(x1,x3,g,n)+solve(x3,x2,g,n)+solve(x2,x4,g,n);
    int res = min(a,b);
    if(res <= INF)cout<<res;
    else cout<<-1;  
}