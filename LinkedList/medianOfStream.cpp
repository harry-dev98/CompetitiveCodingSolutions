#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node* next;
    node* prev;
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    };
}* PTR;

PTR insertAndAns(PTR h, int x, int ind){
    if(h == NULL){
        h = new node(x);
        cout<<x<<"\n";
        return h;
    }
    PTR t = h, H = h;
    PTR median = h;
    while(h->next != NULL){
        cout<<"inwhile"<<h->data<<"\n";
        if(h->next->data > x){
            break;
        }
        else{
            h = h->next;
        }
    }
    PTR temp = h->next;
    h->next = new node(x);
    h->next->next = temp;
    int f=0;
    while(t != NULL){
        cout<<"inmedi"<<median->data<<"\n";
        if(t->next != NULL){
            median = median->next;
            t = t->next->next;
        }
        else{
            f=1;
            break;
        }
    }
    if(f == 1){
        cout<<(median->data+median->next->data)/2<<"\n";
    }
    else{
        cout<<median->data<<"\n";
    }
    return H;
}

int main(){
    int n, x;
    cin>>n;
    PTR Head = NULL;
    
    for(int i=0; i<n; i++){
        cin>>x;
        Head = insertAndAns(Head, x, i);
    }
}