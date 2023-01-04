/*https://www.codingninjas.com/codestudio/problems/rotate-array_1230543?leftPanelTab=0*/

#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++ ){
        cin>>arr[i];
    }
int k;
    cin>>k;
    int res[n];
    for(int i=0;i<n;i++){
        res[i]=arr[(i+k)%n];
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
