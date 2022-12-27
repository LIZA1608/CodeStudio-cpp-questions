/*https://www.codingninjas.com/codestudio/problems/kth-smallest-element_893056?leftPanelTab=0*/

#include <bits/stdc++.h> 
int kthSmallest(vector<int> input, int k)
{
    int n=input.size()-1;
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    for(int i=k;i<=n;i++){
        if(input[i]<pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    int ans =pq.top();
    return ans;
}
