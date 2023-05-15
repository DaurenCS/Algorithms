#include <bits/stdc++.h>

using namespace std;
#define INF 10000000

int bfs(int a, int n, vector<pair<int,int>> g[]){
    vector<bool> ind(n+1, false);
    vector<int> cost(n+1,INF);

    queue<int> q;
    q.push(a);

    ind[a] = true;
    cost[a] = 0;
    
    while(q.size()>0){
        int i = q.front();
        q.pop();
      
        for(int j = 0; j<g[i].size(); j++){
            if(cost[g[i][j].first] > cost[i]+g[i][j].second){
                cost[g[i][j].first] = cost[i]+g[i][j].second;
                if(!ind[g[i][j].first]){
                    ind[g[i][j].first] = true;
                    q.push(g[i][j].first);
                }
               

            }
        }
    }
    return cost[n];
}

int main(){
    int n,m; 
    cin>>n>>m;
    vector<pair<int,int>> g[n+1];
    vector<pair<int,int>> g1[n+1];
    bool flag[n+1][n+1];
    for(int i =1; i<=n; i++){
        for(int j =1; j<=n; j++){
            flag[i][j] = false;
        }
    }

    for(int i =0; i<m; i++){
        int x,y; cin>>x>>y;
        g[x].push_back(make_pair(y,1));
        g[y].push_back(make_pair(x,1));
        flag[x][y] = flag[y][x] = true;
    }
    int res1 = bfs(1,n, g);

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i != j && !flag[i][j]){
                g1[i].push_back(make_pair(j,1));
                g[j].push_back(make_pair(i,1));
                flag[i][j] = true;
            }
        }
    }


    
    
    int res2 = bfs(1,n,g1);

    if(res1 == INF || res2 == INF){
        cout<<-1; return 0;
    }
    cout<<max(res1,res2);
    

}

