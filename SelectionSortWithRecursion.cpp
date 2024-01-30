#include <bits/stdc++.h>
using namespace std;
void sort(int *arr,int size){
    if(size<=0){
        return;
    }
    int maxIndex=size-1;
    for(int i=size-1;i>=0;i--){
        if(arr[i]>arr[maxIndex]){
            maxIndex=i;
        }
    }
    swap(arr[size-1],arr[maxIndex]);
    
    sort(arr,size-1);
}
int main() {
    int arr[6]={2,55,1,6,4,0};
    sort(arr,6);
    
    for(auto e:arr){
        cout<<e<<endl;
    }
    

    return 0;
}