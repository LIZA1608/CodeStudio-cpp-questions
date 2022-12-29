/*https://www.codingninjas.com/codestudio/problems/merge-two-binary-max-heaps_1170049?leftPanelTab=0*/

#include <bits/stdc++.h>
void heapify(vector<int>&ans,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n &&ans[largest]<ans[left]){
        largest=left;
    }
    if(right<n && ans[largest]<ans[right]){
        largest=right;
    }
    if(largest!=i){
        swap(ans[largest],ans[i]);
        heapify(ans,n,largest);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    vector<int>ans;
    for(auto i:arr1){
        ans.push_back(i);
    }
    for(auto i:arr2){
        ans.push_back(i);
    }
    int size=ans.size();
    for(int i=size/2-1;i>=0;i--){
        heapify(ans,size,i);
    }
    return ans;
}
