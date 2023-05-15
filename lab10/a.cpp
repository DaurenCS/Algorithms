#include<bits/stdc++.h>

using namespace std;

queue<pair<int,int>> q;
int t[1001][1001];

void step(int r, int c, int m, int n, int cur){
    if(r <= m  && c <= n && r >= 1 && c >=1 && t[r][c] == -1 ){
        t[r][c] = cur;
        q.push(make_pair(r,c));
        
    }
}


int main(){
    int m,n;
    cin>>m>>n;

    

     for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            t[i][j] = -1;
        }
    }

    
    vector<vector<int>> v;

    for(int i =0; i<m; i++){
        vector<int> x;
        for(int j =0; j<n; j++){
            int a;cin>>a;
            x.push_back(a);
            
        }
        v.push_back(x);
    }
    
    

    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            if(v[i][j] == 2){
                q.push(make_pair(i+1,j+1));
                t[i+1][j+1] = 0;
            }
            if(v[i][j] == 0){
                t[i+1][j+1] = -2;
            }
        }
    }

       

    while(q.size()>0){
        pair<int,int> cur = q.front();
        q.pop();
        int c = t[cur.first][cur.second];
         
        step(cur.first + 1, cur.second,m,n, c+1);
        step(cur.first - 1, cur.second,m,n, c+1);
        step(cur.first , cur.second+1,m,n, c+1);
        step(cur.first , cur.second-1,m,n, c+1);
    }
    int mx = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(t[i][j] == -1){
                cout<<-1;
                return 0;
            }
            else{
                mx = max(mx, t[i][j]);
            }
        }
        
    }
    cout<<mx;
    
}