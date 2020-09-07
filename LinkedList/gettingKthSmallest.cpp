#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef struct node{
    int data;
    node* next;
    node(int x){
        data = x;
        next = NULL;
    };
}* PTR;

PTR sortedInsert(PTR h, int x){
    if(h == NULL){
        return new node(x);
    }
    if(h->data>x){
        PTR newH = new node(x);
        newH->next = h;
        return newH;
    }
    PTR H = h;
    while(h->next != NULL){
        // cout<<"data"<<h->data<<endl;
        if(h->next->data<x){
            h = h->next;
        }
        else{
            break;
        }
    }
    PTR tmp = h->next;
    h->next = new node(x);
    h->next->next = tmp;
    return H;
}

void printKthSmallest(PTR h, int k){
    while(--k){
        // cout<<h->data<<endl;
        h = h->next;
    }
    cout<<h->data;
}

int main(){
    SPEED;
    int t; cin>>t;
    while(t--){
        int n, k, x;
        cin>>n;
        PTR h = NULL;
        for(int i=0; i<n; i++){
            cin>>x;
            h = sortedInsert(h, x);
        }
        cin>>k;
        printKthSmallest(h, k);
        cout<<"\n";
    }
}