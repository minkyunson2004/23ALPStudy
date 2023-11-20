#include <iostream>
#include <vector>
using namespace std;

//전위순회
void front(vector<int> & lc, vector<int> & rc, int node)
{
    if(node == -1)
    {
        
    }
    else
    {
        cout << (char) (node + 65);
        front(lc, rc, lc[node]);
        front(lc, rc, rc[node]);
    }
}
//중위순회
void middle(vector<int> & lc, vector<int> & rc, int node)
{
    if(node == -1)
    {
        
    }
    else
    {
        middle(lc, rc, lc[node]);
        cout << (char) (node + 65);
        middle(lc, rc, rc[node]);
    }
}
//후위순회
void back(vector<int> & lc, vector<int> & rc, int node)
{
    if(node == -1)
    {
        
    }
    else
    {
        back(lc, rc, lc[node]);
        back(lc, rc, rc[node]);
        cout << (char) (node + 65);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //트리 저장
    int n;
    cin >> n;
    
    vector<int> lc(n);
    vector<int> rc(n);
    
    for(int i = 0; i < n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        
        if(b == '.')
        {
            lc[a - 65] = -1;
        }
        else
        {
            lc[a - 65] = b - 65;
        }
        
        if(c == '.')
        {
            rc[a - 65] = -1;
        }
        else
        {
            rc[a - 65] = c - 65;
        }
    }
    //전위순회
    front(lc, rc, 0);
    cout << '\n';
    //중위순회
    middle(lc, rc, 0);
    cout << '\n';
    //후위순회
    back(lc, rc, 0);
    cout << '\n';
}
