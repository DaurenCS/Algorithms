#include<bits/stdc++.h>

using namespace std;


int main(){
    int n; cin>>n;
    
    int g[n][n];
    vector<bool> ind(n, false);

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
             cin>>g[i][j];
        }
    } 

    int ord[n];

    for(int i =0; i<n; i++){
        int x;cin>>x;
        ord[i] = x-1; 
    }
    
    for(int i = 0; i<n; i++){
        int res = 0;
        int u = ord[i];
        ind[u] = true;
        for(int j = 0; j<n; j++){
            for(int k =0; k<n; k++){
                g[j][k] = min(g[j][k], g[j][u]+g[u][k]);
                if(ind[j]){
                    if(ind[k]){
                        res = max(res, g[j][k]);
                    }
                }
            }
        }
    cout<<res<<endl;
    }
    


}