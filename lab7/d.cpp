#include<bits/stdc++.h>

using namespace std;

void merge(vector<pair<double, vector<string>>>&a, int l1,int r1, int l2,int r2){
    int n1 = r1 - l1 +1;
    vector<pair<double, vector<string>>> l;
    for(int i = 0; i<n1; i++){
        l.push_back(make_pair(a[i+l1].first,a[i+l1].second));
    }

    int n2 = r2 - l2 +1;
    vector<pair<double, vector<string>>> r;
    for(int i = 0; i<n2; i++){
        r.push_back(make_pair(a[i+l2].first,a[i+l2].second));
    }
    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1<n1 && i2<n2){
        if(l[i1] < r[i2]){
            a[i++] = l[i1++];
        }
        else{
            a[i++] = r[i2++];
        }
    }
    while(i1<n1){
        a[i++] = l[i1++];
    }
    while (i2<n2){
        a[i++] = r[i2++];
    }
    

}

void msort(vector<pair<double, vector<string>>>&a, int l, int r){
    if(l<r){
        int m = ceil((l+r)/2.0);
        msort(a,l,m-1);
        msort(a,m,r);
        merge(a,l,m-1,m,r);
    }
}

int main(){
    int x; cin>>x;
    vector<pair<double, vector<string>>> a;
    for(int i = 0; i<x; i++){
        vector<string> na;
        string n,s;
        cin>>n>>s;
        int sum; 
        na.push_back(n);
        na.push_back(s);
        cin>>sum;
        double total = 0;
        int totc=0;
        for(int i =0; i<sum; i++){
            string g; int cnt; cin>>g>>cnt;
            if(g == "A"){
                total +=(cnt * 3.75);
            }
            else if(g == "A+"){
                total +=(cnt * 4);
            }
            else if(g == "B+"){
                total +=(cnt * 3.50);
            }
            else if(g == "B"){
                total +=(cnt * 3);
            }
            else if(g == "C+"){
                total +=(cnt * 2.5);
            }
             else if(g == "C"){
                total +=(cnt * 2.00);
            }
            else if(g == "D+"){
                total +=(cnt * 1.50);
            }
            else if(g == "D"){
                total +=(cnt * 1.00);
            }
            else if(g == "F"){
                total +=(cnt * 0);
            }
            totc+=cnt;
        }
        a.push_back(make_pair(total/totc, na));
    }

    msort(a,0,a.size()-1);

    for(int i =0;i<a.size();i++)
    {
        cout<<a[i].second[0]<<" "<<a[i].second[1]<<" "<<fixed<<setprecision(3)<<a[i].first<<endl;
    }

}

