#include <iostream>
#include <vector>
using namespace std;

int nodes = 0, edges = 0;
int p[200002];
int cnt = 0;
vector<int> g[200002];

int getParent(int v){
    if(v == p[v]) return v;
    return p[v] = getParent(p[v]);
}

bool merge(int u, int v){
    u = getParent(u);
    v = getParent(v);
    if(u == v) return false;
    p[u] = v;
    return true;
}

int main(){
    cin >> nodes >> edges;
    int ans[nodes];
    for(int i = 1; i<= nodes; i++){
        p[i] = i;
    }
    for(int i = 0 ; i < edges; i++){
        int u, v; cin >> u >> v;
        if(u < v){
            g[u].push_back(v);
        }else{
            g[v].push_back(u);
        }
    }
    for(int i = nodes; i > 0; i--){
        ans[i-1] = cnt;
        cnt++;
        for(int j = 0; j < g[i].size(); j++){
            if(merge(i,g[i][j])){
                cnt--;
            }
        }
    }
    for(int i = 0;i < nodes; i++){
        cout << ans[i] << endl;
    }

    return 0;
}