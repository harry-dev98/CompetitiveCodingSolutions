#include<iostream>
using namespace std;

const int N = 1000000009;
int Parent[N];
int Size[N];

void make_set(int v){
    Parent[v] = v;
    Size[v] = 0;
}

int find_set(int v){
    if(Parent[v] == v){
        return v;
    }
    return Parent[v] = find_set(Parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(Size[a] < Size[b]){
            swap(a, b);
        }
        Parent[b] = a;
        Size[a] += Size[b];
    }
}

int main(){
    
}