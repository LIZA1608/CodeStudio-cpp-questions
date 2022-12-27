
/*https://www.codingninjas.com/codestudio/problems/kth-largest-element_796007?leftPanelTab=0*/

#include <bits/stdc++.h> 
 int findKthLargest(vector<int>& nums, int k) {

priority_queue<int,vector<int>,greater<int>>pq;
     int n=nums.size()-1;
     for(int i=0;i<k;i++){
         pq.push(nums[i]);
     }
     for(int i=k;i<=n;i++){
         if(nums[i]>pq.top()){
             pq.pop();
            pq.push(nums[i]);
         }
     }
     int ans=pq.top();
     return ans;
}
