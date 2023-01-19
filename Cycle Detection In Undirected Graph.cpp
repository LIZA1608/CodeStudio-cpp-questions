
/*https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/

#include<bits/stdc++.h>
bool isCyclic(int node,unordered_map<int,bool>&visited,
             unordered_map<int,list<int>>&adj){
    unordered_map<int,int>parent;
    parent[node]=-1;
    visited[node]=true;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        for(auto neigh:adj[front]){
            if(visited[neigh]==true &&neigh!=parent[front]){
                return true;
            }
            else if(!visited[neigh]){
                q.push(neigh);
                visited[neigh]=true;
                parent[neigh]=front;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCyclic(i,visited,adj);
            if(ans==1){
                return"Yes";
            }
        }
    }
    return "No";
}
