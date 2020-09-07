#include<bits/stdc++.h>
using namespace std;


void p(int arr[], int s, int e){
    for(int i=s; i<e+1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int partition(int arr[], int s, int e, int key){
    int j = s-1;
    int key_ind;
    for(int i=s; i<=e; i++){
        if(arr[i] == key){
            key_ind = i;
            break;
        }
    }
    cout<<key_ind<<endl;
    swap(arr[key_ind], arr[e]);cout<<"wap\n";
    p(arr, s, e);
    for(int i=s; i<=e; i++){
        if(arr[i] < key){
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[++j], arr[e]);
    p(arr, s, e);
    return j;
}

int getMedian(int arr[], int n){
    sort(arr, arr+n);
    return (n-1)/2;
}
int kthSmallest(int arr[], int s, int e, int k);

int medianOfMedians(int arr[], int s, int e){
    int j = 0;
    for(int i=s; i<=e; i+=5){
        int median_index = i+getMedian(arr+i, min(5, e-i+1));
        swap(arr[median_index], arr[s+j]);
        j++;
        p(arr, s, e);

    }
    int mom = kthSmallest(arr, s, s+j-1, s+j/2);
    p(arr, s, e);

    return mom;
}

int kthSmallest(int arr[], int s, int e, int k){
    if(e-s+1<5){
        sort(arr+s, arr+e+1);
        return arr[k];
    }
    p(arr, s, e);

    int partition_ele = medianOfMedians(arr, s, e);
    // swap(arr[partition_ele_index], arr[e]);
    p(arr, s, e);
    int partition_index = partition(arr, s, e, partition_ele);
    // p(arr, s, e);
    if(partition_index == k){
        return arr[partition_index];
    }
    else if(partition_index < k){
        return kthSmallest(arr, partition_index+1, e, k);
    }
    else{
        return kthSmallest(arr, s, partition_index-1, k);
    }

}

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int A[n];
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        cin>>k;
        cout<<kthSmallest(A, 0, n-1, k-1)<<"\n";
    }
    return 0;
}