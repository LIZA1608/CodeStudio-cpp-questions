/*https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/


#include <bits/stdc++.h> 

void prepareAdjList(unordered_map<int,set<int>>&adj,vector<pair<int, int>> &edges){
  for(int i=0;i<edges.size();i++){
       int u=edges[i].first;
      int v=edges[i].second;
      
      adj[u].insert(v);
      adj[v].insert(u);
  }  
}
void bfs(unordered_map<int,set<int>>&adj,unordered_map<int,bool>&visited,
       vector<int>&ans,int node ){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        
        for(auto i:adj[frontnode]){
            if(!visited[i]){
                q.push(i); 
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>>adj;
    vector<int>ans;
    unordered_map<int,bool>visited;
    prepareAdjList(adj,edges);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    return ans;
}
