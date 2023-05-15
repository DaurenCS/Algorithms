#include<bits/stdc++.h>

using namespace std;

class heap{
    vector<long long> a;
    public:
        int getSize(){
            return a.size();
        }

        long long parent(long long i){
            return (i-1)/2;
        }
        long long left(long long i){
            return i*2 + 1;
        }
        long long right(long long i){
            return i*2 +2;
        }

        void heap_up(long long i){
            while(i>= 0 && a[parent(i)] < a[i]){
                swap(a[i],a[parent(i)]);
                i = parent(i);
            }
        }
        void add(long long i){
            a.push_back(i);
            long long last = a.size()-1;
            heap_up(last);   
        }

        int search(int x, int y){
            a[x-1] += y;
            int i = x-1;
            while(i>= 0 && a[parent(i)] < a[i]){
                swap(a[i],a[parent(i)]);
                i = parent(i);
                
            }
            return i+1;

        }
        void print(){
            for(int i =0; i<a.size(); i++){
                cout<<a[i]<<" ";
            }
        }
        
};



int main(){
    int x; cin>>x;
    vector<int> v;
    heap * h = new heap();
    for(int i =0; i<x ; i++){
        int a; cin>>a;
        
        h->add(a);
    }
   
    int s; cin>>s;

    for(int i =0; i<s; i++){
       int a, b; cin>>a>>b;
        v.push_back(h->search(a,b));
    }
    for(int i=0; i<v.size(); i++){
        cout<< v[i]<<endl;
    }
    h->print();


    
    
    

    
    
    
    

}