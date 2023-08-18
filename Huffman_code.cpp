#include<iostream>
#include<vector>
#include<cassert>
#include<queue>
using namespace std;
void build_huffman(vector<int>& freq, vector<int>& left, vector<int>& right , vector<int>& parent)
{
    int n = freq.size();
    freq.resize(2*n-1);
    left.resize(2*n-1);
    right.resize(2*n-1);
    parent.resize(2*n-1);
    auto comparePair = [](const pair<int,int>& p, const pair<int,int>& q) {
        return p.second > q.second ;
        };
    priority_queue<pair<int,int>,vector<pair<int,int>> ,decltype(comparePair) > pq(comparePair);

    for(int i = 0; i < n; i++)
    {
        pq.push({i,freq[i]});
        left[i] = -1;
        right[i] = -1;
    }
    for(int i = n; i < 2*n-1; i++)
    {
        pair<int,int> p1 = pq.top();
        pq.pop();
        pair<int,int> p2 = pq.top();
        pq.pop();
        freq[i] = p1.second + p2.second;
        pq.push({i,freq[i]});
        parent[p1.first] = parent[p2.first] =  i;
        left[i] = p1.first;
        right[i] = p2.first;
    }
    parent[2*n-2] = -1;
}
void show_tree_n(const vector<int>& freq, const vector<int>& left,
                const vector<int>& right, const vector<int>& parent, int n)
                 
    {
        if (n == -1 ) return;
        assert(n < parent.size());
        cout << freq[n] << "\n Left tree : \n";
        show_tree_n(freq,left,right,parent,left[n]);
        cout << " Right Tree : \n";
        show_tree_n(freq,left,right,parent,right[n]);
    }

int main(){
    vector<int> freq = {9,8,3,5,6};
    vector<int> left,right,parent;
    build_huffman(freq,left,right,parent);
    for(auto x : parent ) cout << x << " ";
    cout << endl;
    for(auto x : left ) cout << x << " ";
    cout << endl;
    for(auto x : right ) cout << x << " ";
    cout << endl;
    for(auto x : freq ) cout << x << " ";
    cout << endl;
    show_tree_n(freq,left,right,parent,parent.size()-1);
}