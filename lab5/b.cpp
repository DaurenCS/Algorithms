#include<bits/stdc++.h>

using namespace std;

class heap{
    vector<long long> a;
    public:
        int getSize(){
            return a.size();
        }

        long long parent(long long i){
            return (i - 1)/2;
        }
        long long left(long long i){
            return (2 * i) + 1;
        }
        long long right(long long i){
            return (2 * i) + 2;
        }
        void heap_up(long long i ){
            while(i >= 0 && a[parent(i)] < a[i] ){
                swap(a[i],a[parent(i)]);
                i = parent(i);
            }
        }

        void heapify(long long i){
            long long last_i = a.size()-1;
            if(left(i) > last_i)return;
            long long j = left(i);
            if(right(i) <= last_i && a[left(i)] < a[right(i)]){
                j = right(i);
            }
            if(a[i] < a[j]){
                swap(a[i], a[j]);
                heapify(j);
            }
        }

        void add(long long i){
            a.push_back(i);
            long long last_i = a.size()-1;
            heap_up(last_i);
        }
        void print(){
            if(a.size() != 0){
                for(auto p : a)
                    cout<<p;
            }
            else
                cout<<0;
            
        }
        long long get_max(){
            return a[0];
        }
        long long extract_max(){
            long long max = get_max();
            swap(a[0], a[a.size()-1]);
            a.pop_back();
            if(a.size() > 0){
                heapify(0);
            }
            return max;
        }




};

int main(){
    long long a; cin>>a;
    heap * h = new heap();

    for(long long i = 0; i < a; i++){
        long long s; cin>>s;
        h->add(s);
    }
    
    while(true){
        if(h->getSize() <= 1)break;
        
        long long sum = h->extract_max();
        
        sum -= h->extract_max();
        if(sum!=0){
           h->add(sum); 
        }
        
        
    }


    h->print();
}