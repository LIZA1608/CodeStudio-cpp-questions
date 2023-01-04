

/*https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_630526?leftPanelTab=0*/

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
long long maxSum=INT_MIN;
    long long currsum=0;
    for(int i=0;i<n;i++){
        currsum+=arr[i];
       
        if(currsum<0){
            currsum=0;
        }
         maxSum=max(maxSum,currsum);
    }
    return maxSum;
}
