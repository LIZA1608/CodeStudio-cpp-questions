/*https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/

#include<bits/stdc++.h>
#include<limits.h>
#include<queue>
class node{
    public:
    int data;
    int row;
    int col;
  node(int d,int r,int c){
      data=d;
      row=r;
      col=c;
  }  
};
class comapre{
    public:
    bool operator()(node* a ,node*b){
        return a->data>b->data;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int mini=INT_MAX;
    int maxi=INT_MIN;
 priority_queue<node*,vector<node*>,comapre>minHeap;   
    for(int i=0;i<k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minHeap.push(new node(element,i,0));
    }
    int start=mini;
    int end=maxi;
    while(!minHeap.empty()){
        node* temp=minHeap.top();
            minHeap.pop();
        mini=temp->data;
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }
        if(temp->col+1<n){
            maxi=max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            break;
        }
    }
    return (end-start+1);
}
