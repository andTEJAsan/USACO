#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

void compute_stable_matching(vector<vector<int>>& bpref , vector<vector<int>>& gpref , vector<int>& g_b)
{

    int n = bpref.size();
    vector<vector<int>> ith_girls_jthboys_rank(n,vector<int>(n,0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ith_girls_jthboys_rank[i][gpref[i][j]] = j;
        }
    }
    g_b.clear();
    g_b.resize(n);
    for(int& x : g_b) x = 0;
    vector<bool> b_matched(n,false);
    vector<bool> g_matched(n,false);
    vector<int> g_candidate(n);
    int unmatched = n;
    int i = 0;
    while(unmatched > 0)
    {
        if(b_matched[i]){
            i = (i+1)%n;
            continue;
        }
        int girl = bpref[i][g_candidate[i]];
        if (!g_matched[girl])
        {
            g_matched[girl] = true;
            b_matched[i] = true;
            g_b[girl] = i;
            unmatched--;
        }
        else if (ith_girls_jthboys_rank[girl][i] < ith_girls_jthboys_rank[girl][g_b[girl]])
        {
            b_matched[i] = true;
            b_matched[g_b[girl]] = false;
            g_b[girl] = i;
            (g_candidate[g_b[girl]])++;
        }
        else
        {
            (g_candidate[i])++;
        }
        i = (i+1)%n;
        
    }
}

int main(){

    vector<vector<int>> bpref = {
        {1,0,2},
        {1,0,2},
        {2,1,0}
    };
    vector<vector<int>> gpref = {
        {2,1,0},
        {1,0,2},
        {0,1,2}
    };
    vector<vector<int>> ith_boys_jth_pref(3);
    vector<int> g_b;
    compute_stable_matching(bpref,gpref,g_b);
    for(auto x : g_b) cout << x << " ";


    return 0;
}