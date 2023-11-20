#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> result;
    
    while(1)
    {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        
        vector<vector<int>> points(n);
        for(int i = 0; i < m; i++)
        {
            int f,s;
            cin >> f >> s;
            points[f - 1].push_back(s - 1);
            points[s - 1].push_back(f - 1);
        }
        
        vector<bool> visit(n, false);
        
        queue<int> que;
        int tree_total = 0;
        
        for(int i = 0; i < n; i++)
        {
            bool is_tree = true;
            if(visit[i])
            {
                continue;
            }
            else
            {
                visit[i] = true;
                que.push(i);
                while(1)
                {
                    if(que.empty())
                    {
                        if(is_tree)
                        {
                            tree_total++;
                        }
                        break;
                    }
                    else
                    {
                        int tree = 0;
                        
                        int front = que.front();
                        que.pop();
                        
                        for(int e : points[front])
                        {
                            if(visit[e] == true)
                            {
                                tree++;
                                continue;
                            }
                            else
                            {
                                visit[e] = true;
                                que.push(e);
                            }
                        }
                        
                        if(tree > 1)
                        {
                            is_tree = false;
                        }
                    }
                }
            }
        }
        result.push_back(tree_total);
    }
    
    for(int i = 0; i < (int) result.size(); i++)
    {
        switch (result[i])
        {
            case 0:
            {
                cout << "Case " << i + 1 << ": No trees.\n";
                break;
            }
            case 1:
            {
                cout << "Case " << i + 1 << ": There is one tree.\n";
                break;
            }
            default:
            {
                cout << "Case " << i + 1 << ": A forest of " << result[i] << " trees.\n";
                break;
            }
        }
    }
}
