#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int DSU[100007];
int SIZE[100007];

void make_set(int a){
    DSU[a] = a;
    SIZE[a] = 1;
}

int set_find(int a){
    if(DSU[a] == a){
        return a;
    }
    return DSU[a] = set_find(DSU[a]);
}

void set_union(int a, int b){
    a = set_find(a);
    b = set_find(b);
    if(a != b){
        if(SIZE[a] < SIZE[b]){
            swap(a, b);
        }
        DSU[b] = a;
        SIZE[a] += SIZE[b];
    }
}

int set_size(int a){
    a = set_find(a);
    return SIZE[a];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        make_set(i);
    }
    char ch;
    int a, b;
    for(int i=0; i<q; i++){
        cin>>ch;
        if(ch == 'Q'){
            cin>>a;
            cout<<set_size(a)<<"\n";
        }
        else{
            cin>>a>>b;
            set_union(a, b);
        }
    }
    return 0;
}
