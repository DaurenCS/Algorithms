#include<bits/stdc++.h>

using namespace std;

int n;
#define INF 9999999
int g[501][501];

int MST(){
    int no_edge = 0;
    int ind[n];
    memset (ind, false, sizeof (ind));
    ind[0] = true;
    int x;            
    int y;            
    int cost = 0;
    while(no_edge < n-1){
        int min = INF;
        x = y = 0;
        for(int i =0; i<n; i++){
            if(ind[i]){
                for(int j =0; j<n; j++){
                    if(!ind[j] && g[i][j]){
                        if(min > g[i][j]){
                            min = g[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
    cost+=g[x][y];
    ind[y] = true;
    no_edge++;
    }
    return cost;

}


int main(){
    cin>>n;
    vector<int> v(n);
    
    for(int i =0; i<n; i++){
        cin>>v[i];
    }

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            if(i != j)
            g[i][j] = v[i]+v[j];
            else
                g[i][j] = 0;
        }
    }

    // for(int i =0; i<n; i++){
    //     for(int j =0; j<n; j++){
    //        cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<MST();


}