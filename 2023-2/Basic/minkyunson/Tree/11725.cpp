#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> points(n);
    for(int i = 0; i < n - 1; i++)
    {
        int f,s;
        cin >> f >> s;
        points[f - 1].push_back(s - 1);
        points[s - 1].push_back(f - 1);
    }
    
    vector<int> parent(n, -1);
    
    queue<int> que;
    que.push(0);
    while(1)
    {
        if(que.empty())
        {
            break;
        }
        
        int temp = que.front();
        que.pop();
        
        for(int e : points[temp])
        {
            if(parent[e] == -1)
            {
                que.push(e);
                parent[e] = temp;
            }
        }
    }
    
    for(int i = 1; i < n; i++)
    {
        cout << parent[i] + 1 << '\n';
    }
}
