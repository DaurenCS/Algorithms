#include<bits/stdc++.h>

using namespace std;

vector<size_t> f(string s){
    size_t n = s.size();

    vector<size_t>v(n);

    v[0] = 0;

    for(size_t i =1; i<n; i++){
        size_t j = v[i-1];
        while( j>0 && s[j]!=s[i]){
            j = v[j-1];
        }

        if(s[i] == s[j]){
            v[i] = j+1;
        }
    }
    
    return v;
}

int main(){
    string s;
    int x;
    cin>>s>>x;
    vector<string>arr;
    vector<vector<size_t>>v;
    for(int i =0; i<x; i++){
        string a; cin>>a;
        arr.push_back(a);
    }
    s[0] = tolower(s[0]);
    for(int i =0; i<x; i++){
        arr[i][0]= tolower(arr[i][0]);
    }

    for(int i =0; i<arr.size(); i++){
        string res = arr[i] + "#" + s;
        vector<size_t> x = f(res);
        v.push_back(x);
    }
    int maxi = 0;

    // for(int i =0; i<v.size(); i++){
    //     for(int j =v[i].size()-1; j>0; j--){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // return 0;
    vector<int> ind(x);
    for(int i =0; i<v.size(); i++){
        if(v[i][v[i].size()-1] >= maxi ){
            maxi = v[i][v[i].size()-1];
            ind[i] = maxi;
            
        }  
    }
    if(maxi == 0){
        cout<<0;
        return 0;
    } 
    
    int maxx= 0;
    for(int i =0; i<ind.size(); i++){
        if(ind[i] > maxx){
            maxx = ind[i];
        }
    }
    
    int cnt = 0;
    for(int i =0; i<ind.size(); i++){
        if(ind[i] == maxx){
            cnt++;
        } 
    }
      for(int i =0; i<x; i++){
        arr[i][0]= toupper(arr[i][0]);
    }
    cout<<cnt<<endl;
    for(int i =0; i<ind.size(); i++){
        if(ind[i] == maxx){
            cout<<arr[i]<<endl;
        } 
    }  


    
    

    
}