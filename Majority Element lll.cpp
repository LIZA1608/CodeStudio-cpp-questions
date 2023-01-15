/*https://www.codingninjas.com/codestudio/problems/elements-occur-more-than-n-k-times_1113146?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0*/


#include <bits/stdc++.h> 
vector<int> countTheNumber(vector<int> &arr, int n, int k) {
    vector<int>ans;
    map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    map<int,int>::iterator it=mp.begin();
    for(it;it!=mp.end();it++){
        if((*it).second>=n/k){
            ans.push_back((*it).first);
        }
    }
    return ans;
}
