#include<bits/stdc++.h>

using namespace std;

class heap{
    vector <long long> a;
    public:
        int getSize(){
            return a.size();
        }
        long long parent(long long i){
            return (i-1)/2;
        }
        long long left(long long i){
            return (i * 2)+ 1;
        } 
        long long right(long long i){
            return i*2 + 2;
        } 

        void heap_up(long long i){
            while(i>=0 && a[parent(i)] > a[i]){
                swap(a[i],a[parent(i)]);
                i = parent(i);
            }
        }
        void add(long long i){
            a.push_back(i);
            long long last = a.size()-1;
            heap_up(last);
        }

        void heapify(long long i){
            long long last_i = a.size()-1;
            if(left(i) > last_i)return;
            long long j = left(i);
            if(right(i) <= last_i && a[left(i)] > a[right(i)]){
                j = right(i);
            }
            if(a[i] > a[j]){
                swap(a[i], a[j]);
                heapify(j);
            }
        }
        long long getMax(){
            return a[0];
        }
        long long extract(){
            if(a.size() != 0){
                long long max = getMax();
                swap(a[0], a[a.size()-1]);
                a.pop_back();
                if(a.size() > 0){
                    heapify(0);
                }
                return max;
            }
            return 0;
            
        }
        
       
        void p(){
            long long sum = 0;
            for (auto i: a) sum += i;
            cout << sum << "\n";
        }
};

int main() {
    long long q, k;
    cin >> q >> k;
    heap * h = new heap();
    
    while(k--) {
        h->add(0);
    }

    while (q--) {
        string s;
        cin >> s;
        if (s == "insert") {
            long long x;
            cin >> x;
            if (h->getMax() < x) {
                h->extract();
                h->add(x);
            }
        }
        else {
            h->p();
        }

    }

    return 0;
}