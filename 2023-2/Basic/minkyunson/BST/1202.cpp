#include <iostream>
#include <queue>
#include <set>
using namespace std;

class comp
{
public:
    bool operator()(pair<int, int> first, pair<int, int> second)
    {
        if(first.second < second.second)
            return true;
        else
            return false;
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    int w, v;
    cin >> n >> k;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> jewel;
    for(int i = 0; i < n;i++)
    {
        cin >> w >> v;
        pair<int, int> inf(w, v);
        jewel.push(inf);
    }
    
    multiset<int> weight;
    for(int i = 0; i < k; i++)
    {
        cin >> w;
        weight.insert(w);
    }
    
    long int total = 0;
    for(int i = 0; i < n; i++)
    {
        pair<int, int> top = jewel.top();
        jewel.pop();
        
        auto iter1 = weight.find(top.first);
        if(iter1 == weight.end())
        {
            auto iter2 = weight.upper_bound(top.first);
            if(iter2 == weight.end())
            {
                continue;
            }
            else
            {
                //cout << *iter2 << endl;
                total += top.second;
                weight.erase(iter2);
            }
        }
        else
        {
            //cout << *iter1 << endl;
            total += top.second;
            weight.erase(iter1);
        }
    }
    
    cout << total << endl;
}
