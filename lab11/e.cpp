#include<bits/stdc++.h>

using namespace std;

int p[200001];
vector<int> g[200001];

int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}


bool unit_s(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        p[a] = b;
        return true;
    }
    return false;
}



int main(){
    int n, m; 
    cin>>n>>m;
    vector<int> v(n);
    int cnt =0;
    for(int i =1; i<=n; i++){
        p[i] = i;
    }

    for(int i =0; i<m; i++){
        int a,b; cin>>a>>b;
        if(a > b){
            g[b].push_back(a);
        }
        else    
            g[a].push_back(b);

    }

    for(int i = n; i>0; i--){
        v[i-1] = cnt; cnt++;
        for(int j =0; j<g[i].size(); j++){
            if(unit_s(i, g[i][j])){
                cnt--;
            }
        }  
    }
    for(int i=0; i<n; i++){
        cout << v[i] << endl;
    }

}