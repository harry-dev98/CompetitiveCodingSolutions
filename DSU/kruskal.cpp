#include<iostream>
#include<algorithm>
using namespace std;

int Set[1009];
int Size[1009];

struct edge{
    int v, u, w;
    bool operator<(const edge& e) const{
        return w < e.w;
    }
};

void make_set(int a){
    Set[a] = a;
    Size[a] = 1;
}

int find_set(int a){
    if(Set[a] == a){
        return a;
    }
    return Set[a] = find_set(Set[a]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(Size[a] < Size[b]){
           swap(a, b); 
        }
        Set[b] = a;
        Size[a] += Size[b];
        return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, v, e, a, b, c;
    cin>>t;
    while(t--){ 
        cin>>v>>e;
        edge Edges[e];
        for(int i=0; i<e; i++){
            cin>>a>>b>>c;
            Edges[i].v = --a;
            Edges[i].u = --b;
            Edges[i].w = c;
        }
        sort(Edges, Edges+e);
        for(int i=0; i<v; i++){
            make_set(i);
        }
        int sum = 0;
        for(int i=0; i<e; i++){
            sum += union_set(Edges[i].v, Edges[i].u)?Edges[i].w:0;
        }
        cout<<sum<<"\n";
    }
    return 0;
}