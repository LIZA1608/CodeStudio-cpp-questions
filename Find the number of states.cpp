
/*https://www.codingninjas.com/codestudio/problems/find-the-number-of-states_1377943?leftPanelTab=0*/

#include <bits/stdc++.h> 
void dfs(int node,int vis[], vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj);
        }
    }
}
int findNumOfStates(vector<vector<int>>& roads, int n) {
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if (roads[i][j] == 1 && i != j) {
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
    }
    int vis[n]={0};
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i,vis,adj);
        }
    }
    return count;
}
