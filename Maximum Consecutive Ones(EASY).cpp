/*https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_3843993?leftPanelTab=0*/

#include <bits/stdc++.h> 
int consecutiveOnes(vector<int>& arr){
    //Write your code here.
    int n=arr.size();
    int c=0,maxi=0;
		for(int i=0;i<n;i++){
			if(arr[i]!=0){
				c++;
				maxi=max(maxi,c);
			}
			else{
				c=0;
			}
		}
		return maxi;
}
