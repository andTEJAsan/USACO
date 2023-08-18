#include<iostream>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
int binary_search(const vector<int>& v, int x) {
  int n = v.size();
  if (x > v[n-1] || x < v[0] ) return -1;
  // v[0] <= x <= v[n-1] 
  int l=0;
  int r = n-1;
  while(l < r){
    int mid = l + (r-l+1)/ 2;
    if(v[mid] == x) return mid;
    else if (v[mid] > x) r = mid -1;
    else l = mid + 1;
  }
  return (v[r] == x ? r : -1);
}

void GreedySchedule(vector<int>& S, vector<int>& F, vector<int>& Out){
 // S and F would get modified 
  int n = S.size();
  assert(n == F.size());
  vector<int> F_old = F;
  sort(F.begin(),F.end());
  vector<int> S_new(n);
  for(int i= 0; i < n; i++) 
  {
    S_new[binary_search(F,F_old[i])] = S[i];
  }
  Out.clear();
  Out.push_back(0);
   for(auto x: F) cout << x << " ";
   cout << endl;
   for(auto x: S_new) cout << x << " ";
   cout << endl;

  int count = 1;
  int after = F[0];
  for(int i = 1; i < n; i++){
    if(S_new[i] >= after){
    count++;
    after = F[i];
    Out.push_back(i);
    }
  }
}
void minimal_point_set_interval_cover(vector<pair<int,int>>& I , int& Out)
{
  // figure out this minimum size of set of points such that each interval has one point lying inside it.
  // I is a vector of pairs of integers representing intervals.
  // Out is the minimum size of the set of points.  
  sort(I.begin(),I.end(),[](pair<int,int> a, pair<int,int> b){return a.second < b.second;});
  int n = I.size();
  int temp_end = I[0].second;
  int temp_start = I[0].first;
  int count = 1;
  for(int i = 1; i < n; i++)
  {
    if(I[i].first >= temp_end){
      count++;
      temp_end = I[i].second;
      temp_start = I[i].first;
    }
  }

}

int main() {
  vector<int> S = {1,-1,-5,2,9};
  vector<int> F = {9, 3 , 4 , 7,10};
  vector<int> Schedule;
  GreedySchedule(S,F,Schedule);
  for(auto x: Schedule) cout << x << " ";
//  for(auto x: Schedule) cout << x << " ";
  vector<int,int
  return 0;
}
