#include <iostream>
#include <vector>
using namespace std;
struct fun{
    int s;
    vector<int> v;
    fun(){
        s = 0;
    }
    void append(int x){
        s += x;
        v.push_back(x);
    }
    void print(){
        for(int i = 0; i<v.size(); ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    bool greater(fun * other){
        if(s>other->s) return true;
        if(s == other->s){
            for(int i = 0; i < v.size(); ++i){
                if(v[i] != other->v[i]){
                    return v[i]<other->v[i];
                }
            }
            return false;
        }
        return false;
    }
};

void merge(fun * a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    fun L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }
    int n2 = r2 - l2 + 1;
    fun R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }
    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 && i2 < n2){
        if(L[i1].greater(&R[i2])){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
        }
    }
    while(i1 < n1)
        a[i++] = L[i1++];
    
    while(i2 < n2)
        a[i++] = R[i2++];
    
    
}

void msort(fun * a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}
int main(){
    int n, m, x;
    cin >> n >> m;
    fun row[n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> x;
            row[i].append(x);
        }
    }
    msort(row, 0, n - 1);
    
    for(int i = 0; i < n; ++i){
        row[i].print();
    }
    
    return 0;
}