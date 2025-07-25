#include<bits/stdc++.h>
using namespace std;

int primsAlgo(vector<vector<int>> adj[],int V,vector<int>& vis){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int sum=0;

    while(!pq.empty()){
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();

        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            int adjNode=it[0];
            int adjW=it[1];
            if(!vis[adjNode]){
                pq.push({adjW,adjNode});
            }
        }

    }

    return sum;
}

int main(){
    int V=5;
    vector<vector<int>> edges={{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    vector<vector<int>> adj[V];

    vector<int> vis(V,0);

    for(auto it:edges){
        vector<int> tmp(2);
        tmp[0]=it[1];
        tmp[1]=it[2];

        adj[it[0]].push_back(tmp);

        tmp[0]=it[0];
        tmp[1]=it[2];

        adj[it[1]].push_back(tmp);
    }

    int value=primsAlgo(adj,V,vis);

    cout<<value<<endl;
    return 0;

}