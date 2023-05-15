#include<bits/stdc++.h>

using namespace std;
int x;
vector<int> res;


void dfs(int r,vector<int> a[], vector<int> &ind){
    ind[r] = 1;

    for(int i =0; i<a[r].size(); i++){
        if(ind[a[r][i]] == 0){
            dfs(a[r][i],a,ind);
        }
         else if(ind[a[r][i]] == 1){
            cout << "Impossible";
            exit(0);
        }
    }
    res.push_back(r+1);
    ind[r] = 2;

}

int main(){
    int y; cin>>x>>y;
    vector<int> a[x];
    vector<int> ind(x);
    for(int i =0; i<x; i++){
        ind[i] = 0;
    }
   

    for(int i =0; i<y; i++){
        int d,f;
        cin>>d>>f;
        a[d-1].push_back(f-1);
    }

    for(int i = x-1; i>=0; i--){
        if(ind[i] == 0)
            dfs(i,a,ind);
    }
    
    cout<<"Possible"<<endl;
    for(int i =res.size()-1; i>=0; i--){
        cout<<res[i]<<" ";
    }
    


}