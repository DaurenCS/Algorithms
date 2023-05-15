#include<bits/stdc++.h>

using namespace std;

int part(vector<pair<double, vector<string>>> &a, int low, int hight){
    int pivot = hight;
    int i = low -1;
    for(int j =low; j<hight; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[pivot]);
    return i+1;
}

void qsort(vector<pair<double, vector<string>>> &a, int low, int hight){
    if(low< hight){
        int pivot = part(a,low,hight);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, hight);
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

    qsort(a,0,a.size()-1);

    for(int i =0;i<a.size();i++)
    {
        cout<<a[i].second[0]<<" "<<a[i].second[1]<<" "<<fixed<<setprecision(3)<<a[i].first<<endl;
    }

}