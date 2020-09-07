#include<bits/stdc++.h>
using namespace std;

void p(int arr[], int s, int e){
    for(int i=s; i<e+1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int findMedian(int arr[], int k){
    sort(arr, arr+k);
    return (k-1)/2;
}

int medianOfMedian(int arr[], int s, int e){
    p(arr, s, e);
    int n = e-s+1;
    for(int i=0; i<(n+4)/5; i++){
        p(arr, s, e);
        int median_index = findMedian(arr+s+5*i, min(5, n-5*i));
        swap(arr[s+5*i + median_index], arr[s+i]);
        p(arr, s, e);
    }
    int mom = findMedian(arr+s, (n+4)/5)+s;
    p(arr, s, e);
    return mom;
}

int partition(int arr[], int s, int e){
    cout<<"partition "<<endl;
    p(arr, s, e);
    int j=s-1;
    for(int i=s; i<e+1; i++){
        if(arr[i]<arr[e]){
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[++j], arr[e]);
    p(arr, s, e);
    return j;
}

int kthSmallest(int arr[],int s, int e, int k){
    cout<<"kthsmalled "<<s<<" "<<e<<" "<<k<<endl;

    int n = e - s + 1;
    p(arr, s, e);
    int pivot_ind = medianOfMedian(arr, s, e);
    swap(arr[pivot_ind], arr[e]);
    int mom_index = partition(arr, s, e);
    cout<<mom_index<<" donepartititon\n";
    p(arr, s, e);
    if(k==mom_index){
        return arr[mom_index];
    }
    else if(k>mom_index){
        return kthSmallest(arr, mom_index+1, e, k);
    }
    else{
        return kthSmallest(arr, s, mom_index, k);
    }
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15}; 
    int n = 6, k = 3;
    cout<<kthSmallest(arr, 0, n-1, k-1)<<"\n";
    return 0;
}