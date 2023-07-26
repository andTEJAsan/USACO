#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int,int>> I;
    set<int> S;
    for(int i = 0 ; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        I.insert(make_pair(x,y));
        S.insert(y);
    }
    int count = 0;
    while(!S.empty())
    {
        set<int>::const_iterator min_it = S.begin();
        int e = *min_it;
        S.erase(min_it);
        auto it = I.begin();
        while(it != I.end() && it->first < e)
        {
                S.erase(it->second);
                it++;
        }
        I.erase(I.begin(),it);
        count++;
    }
    cout << count << std::endl;



    return 0;
}
