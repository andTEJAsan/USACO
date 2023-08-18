#include<bits/stdc++.h>
using namespace std;


void dfs(int node,const vector<vector<pair<int,int>>>& adj, vector<bool>& visited, int threshold,vector<int> &complabel, int label)
{
    visited[node] = true;
    complabel[node]=label;
    for(auto edge : adj[node]) {
        if(!visited[edge.first] && edge.second >= threshold) dfs(edge.first,adj,visited,threshold,complabel,label);
    }

}



bool possible(int x, vector<vector<pair<int,int>>>& adj, vector<vector<int>>& cycles, int n)
{
    vector<bool> vis(n+1,false);
    vector<int> complabel(n+1);
    int label=1;

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        dfs(i,adj,vis,x,complabel,label);
        label++;
    }

    bool poss=true;

    for(auto cy:cycles)
    {
        int val=complabel[cy.front()];
        for(auto x:cy)
        {
            if(complabel[x]!=val){
                poss = false;
                break;
            }
        }
    }
    return poss;
}
void compute_cycles_permutation(vector<int>& p, vector<vector<int>>& cycles)
{
    int n = p.size()-1;
    vector<bool> visited(n+1,false);
    for(int i = 1; i<= n; i++)
    {
        if(visited[i]) continue;
        vector<int> cycle;
        visited[i] = true;
        cycle.push_back(i);
        int at_index = p[i];
        while(at_index != i){
            visited[at_index] = true;
            cycle.push_back(at_index);
            at_index = p[at_index];
        }
        cycles.push_back(cycle);
    }
}
int main(){
    int n,k;
    //ifstream cin("wormsort.in");
    //ofstream cout("wormsort.out");
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<array<int,3>> v(n+1);
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> pos_ans;
    for(int i = 1; i<= n; i++){
    cin >> v[i][0] >> v[i][1] >> v[i][2];
    adj[v[i][0]].push_back({v[i][1],v[i][2]}); 
    adj[v[i][1]].push_back({v[i][0],v[i][2]}); 
    pos_ans.push_back(v[i][2]);
    }
    sort(pos_ans.begin(),pos_ans.end());
    vector<vector<int>> cycles;
    compute_cycles_permutation(a,cycles);
    int l = 0, r = pos_ans.size();
    while(l < r){
        int mid = l + (r-l+1)/2;
        if (possible(pos_ans[mid],adj,cycles, n)) l = mid;
        else r = mid-1;
    }
     cout << pos_ans[r] << "\n";
    return 0;
}
