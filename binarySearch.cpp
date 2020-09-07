#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int key, int s, int e){
    if(s<=e){
        int mid = (s+e)/2;
        int index1, index2;
        if(arr[mid] == key){
            return true;
        }
        return binarySearch(arr, key, mid+1, e) || binarySearch(arr, key, s, mid-1);
    }
    return false;
}

int main(){
    int arr[] = {1, 2, 9, 12, 13, 14, 23, 34, 45, 65};
    if(binarySearch(arr, 65, 0, 9)){
        cout<<"true\n";
    }
    else{
        cout<<"False\n";
    }
    return 0;
}