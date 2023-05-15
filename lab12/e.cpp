#include<bits/stdc++.h>

using namespace std;
#define INF 100000000 

int g[101][101];

int n;


void solve(){
    vector<int> res;
    for(int k =0 ; k<n; k++){
        vector<int> d(n,INF);
        d[k] = 0;
        vector<int> p(n,-1);
        int x;
        for(int i =0; i<n; i++){
            x = -1;
            for(int i = 0; i < n; i++){
                for(int j =0; j<n; j++){
                    if(g[i][j] == 10000)continue;
                    if(d[i] < INF){
                        if(d[j] > d[i] + g[i][j]){
                            d[j] = max(-INF,d[i] + g[i][j]);
                            p[j] = i;
                            x = j;
                        }  
                    }
                }
            }
        }
        if(x == -1){
            cout<<"NO";
            return;
        }
        else{
            int y = x;
            for (int i=0; i<n; ++i)
                y = p[y];
    
            vector<int> path;
            for (int cur=y; ; cur=p[cur]) {
                path.push_back (cur+1);
                if (cur == y && path.size() > 1)  break;
            }
            reverse (path.begin(), path.end());

            
    
            cout << "YES"<<endl;
            cout<< path.size()<<endl;

            res.push_back(path[path.size()-2]);
            for (size_t i=0; i<path.size(); ++i){
                if(path[i] ==path[path.size()-2]){
                    res.push_back(path[i]);
                    break;
                }
                res.push_back(path[i]);
            }
            for(int i =0; i<res.size(); i++)
                cout << res[i] << ' ';
            return ;
        }
    }
}


int main(){
    cin>>n;

    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>g[i][j];
            }
        }
    

    solve();

    // for(int i =0; i<n; i++){
    //     cout<<g[i].a<<" "<<g[i].b<<" "<<g[i].c<<endl;
    // }
}