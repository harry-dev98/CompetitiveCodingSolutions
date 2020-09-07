#include<bits/stdc++.h>
using namespace std;

#define p(s) cout<<s<<" "

int partition(int arr[], int s, int e){
    int sort_helper=s-1;
    int swap_helper;
    int pivot = arr[e];
    for(int itr=s; itr<e; itr++){     
        if(arr[itr]<=pivot){
            sort_helper++;
            swap_helper = arr[itr];
            arr[itr] = arr[sort_helper];
            arr[sort_helper] = swap_helper;
        }
    }
    sort_helper++;
    arr[e] = arr[sort_helper]; 
    arr[sort_helper] = pivot;
    return sort_helper;
}

void quickSort(int arr[], int s, int e){
    if(s<e){
        int par = partition(arr, s, e);
        quickSort(arr, s, par-1);
        quickSort(arr,par+1, e);
        return;
    }
    return;    
}

int main(){
    int arr[] = {34,2,14,23,65,12,9,13,45,1};
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    quickSort(arr, 0, 9);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
