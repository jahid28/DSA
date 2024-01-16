#include<bits/stdc++.h>

using namespace std;
int main(){

stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(5);
s.push(5);
// s.push(10);
int size=s.size() ;
// cout<<"s is"<<size;
int n=floor(size/2);
// cout<<"n is"<<n;
int arr[n];
for (int i=size; i>n+1;i--){
    arr[i-n-2]=s.top();
    s.pop();
}
s.pop();

for(int i=0;i<n;i++){
    s.push(arr[i]);
}

// for(int i=0;i<5;i++){
//     cout<<"hi"<<arr[i]<<endl;
// }

while(s.empty()==false){
    cout<<s.top()<<endl;
    s.pop();
}



    return 0;
}