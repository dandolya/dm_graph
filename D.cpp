#include <iostream>
#include <vector>
#include <deque>
 
std::vector<std::vector<int>> matrix;
std::vector<int> mark;
int n;
std::vector<int> path;
 
void dfs(int v)
{
    mark[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] == 1 && mark[i] == 0)
        {
            dfs(i);
        }
    }
    path.push_back(v);
}
 
int main()
{
    std::cin >> n;
    matrix.resize(n, std::vector<int>(n, 0));
    for (int i = 1; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s.at(j) == '0')
            {
                matrix[j][i] = 1;
                matrix[i][j] = 0;
            }
            else
            {
                matrix[i][j] = 1;
                matrix[j][i] = 0;
            }
        }
    }
    mark.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mark[j] = 0;
        }
        path.resize(0);
        dfs(i);
        if (path.size() == n)
        {
            if (matrix[path[0]][path[n - 1]])
            {
                break;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << path[i] + 1 << " ";
    }
    std::cout << "\n";
}
