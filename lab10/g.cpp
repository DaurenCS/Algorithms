#include <bits/stdc++.h>


using namespace std;

int n, m;
vector<vector<pair<int,int>>> g(501);
int ind[501];
int cnt;

// void dfs(int r,vector<int> a[], vector<int> &ind){
//     ind[r] = 1;

//     for(int i =0; i<a[r].size(); i++){
//         if(ind[a[r][i]] == 0){
//             dfs(a[r][i],a,ind);
//         }
//          else if(ind[a[r][i]] == 1){
//             cout << "Impossible";
//             exit(0);
//         }
//     }
//     res.push_back(r+1);
//     ind[r] = 2;

// }

void dfs(int u) { 
    ind[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        if (!ind[g[u][i].first]) {
            dfs(g[u][i].first);
        }
        else if (ind[g[u][i].first] == 1) {
            cnt++;
        }
    }
    ind[u] = 2;
}

int main() {
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        
        g[u-1].push_back(make_pair(v-1, i));
    }
    for(int i=0; i<n; i++) {
        cnt = 0;
        memset(ind, 0, sizeof ind);
        dfs(i); 
        for (int j = 0; j < n; j++) {
            if (!ind[j]) {
                dfs(j);
            }
        }
        if (cnt <= 1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}