#include <bits/stdc++.h>
using namespace std;

struct vertex{
    int r;
    int c;
    vertex(int r, int c){
        this ->r = r;
        this ->c = c;
    }
};

vector <int> v[501];
vector <vertex> c;
int visited[501], cycle, edged[501][501], m , n;

void init(){
    memset(visited, 0, sizeof(visited));
    memset(edged, 0, sizeof(edged));
    cycle = 0;
}

void has_cycle(int u){
    visited[u] = 1;
    for(int i = 0; i < v[u].size(); i++){
        int cur = v[u][i];
        if(!visited[cur]){
            c.push_back(vertex(u, cur));
            has_cycle(cur);
            if(cycle) return;
        }
        if(visited[cur] == 1){
            c.push_back(vertex(u, cur));
            cycle = 1;
            return ;
        }
    }
    visited[u] = 2; 
}

void dfs(int u){
    visited[u] = 1;
    for(int i = 0; i < v[u].size(); i++){
        int cur = v[u][i];
        if(edged[u][cur]) continue;

        if(!visited[cur]){
            dfs(cur);
            if(cycle) return;
        }

        if(visited[cur] == 1){
            cycle = 1;
            return ;
        }
    }

    visited[u] = 2;
}

int main(){
    init();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }

    for(int i =1; i <= n; i++){
        if(!cycle && !visited[i]){
            has_cycle(i);
        }
    }

    if(!cycle){
        cout << "YES" <<"\n";
        return 0;
    }

    for(int i = 0; i < c.size(); i++){
        vertex cur = c[i];
        int f = cur.r , s = cur.c;

        edged[f][s] = 1;
        memset(visited, 0, sizeof(visited)); 
        cycle = 0;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        if(!cycle){
            cout << "YES" << "\n";
            return 0;
        }

        edged[f][s] = 0;
    }

    cout << "NO" << "\n";
    return 0;
}