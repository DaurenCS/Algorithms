#include<bits/stdc++.h>

using namespace std;

void step(int r, int c, int m, int n,vector<vector<char>> &v, vector<vector<int>> &ind  ){
    if(r < m  && c < n && r >= 0 && c >=0 && v[r][c] == '1' && ind[r][c] == 0 ){
        ind[r][c] = 1;
        step(r+1, c,m,n,v,ind);
        step(r-1, c,m,n,v,ind);
        step(r, c+1,m,n,v,ind);
        step(r, c-1,m,n,v,ind);
    }
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>> v;
    vector<vector<int>> ind; 

    for(int i =0; i<m; i++){
        vector<char> x;
        vector<int> in;
        string s; cin>>s;
        for(int j =0; j<n; j++){
            x.push_back(s[j]);
            in.push_back(0);  
        }
        v.push_back(x);
        ind.push_back(in);
    }
    
    int cnt = 0;
    for(int i =0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(ind[i][j] == 0 && v[i][j] == '1'){
                cnt++;
                step(i, j, m, n, v, ind);
            }
        }
    }

    cout<<cnt;

}