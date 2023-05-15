
#include <bits/stdc++.h>
using namespace std;
 

string findstem(vector<string> arr)
{
    
    int n = arr.size();
 
    
    string s = arr[0];
    int len = s.length();
 
    string res = "";
 
    for (int i = 0; i < len; i++) {
        for (int j =  1; j <= len; j++) {
            string stem = s.substr(i, j);
            int k = 1;
            for (k = 1; k < n; k++) {
                if (arr[k].find(stem) == std::string::npos)
                    break;
            }
 
            if (k == n && res.length() < stem.length())
                res = stem;
        }
    }
 
    return res;
}
 

int main()
{   int x; cin>>x;
    vector<string> arr(x);
    for(int i =0; i<x; i++){
        cin>>arr[i];
    }
    string stems = findstem(arr);
    cout << stems << endl;
}
 
