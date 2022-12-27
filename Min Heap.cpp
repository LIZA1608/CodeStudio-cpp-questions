/*https://www.codingninjas.com/codestudio/problems/min-heap_4691801?leftPanelTab=0*/

#include <bits/stdc++.h> 
class Heap{
    int arr[10000];
    int size;
    public:
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void push(int val){
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    int pop(){
        if(size==0){
            return -1;
        }
        int deleteele=arr[1];
        arr[1]=arr[size];
        size--;
        
        int i=1;
        while(i<=size){
            int left=2*i;
            int right=2*i+1;
            int smallest=i;
            if(left<=size && arr[smallest]>arr[left]){
                smallest=left;
            }
            if(right<=size && arr[smallest]>arr[right]){
                smallest=right;
            }
            if(smallest==i){
                break;
            }
                swap(arr[smallest],arr[i]);
                i=smallest;
        }
            return deleteele;

    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
   vector<int>ans;
    Heap minHeap;
    for(auto i:q){
        if(i[0]==0){
            minHeap.push(i[1]);
        }
        else{
            ans.push_back(minHeap.pop());
        }
    }
    return ans;
}
