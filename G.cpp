#include <iostream>
#include <vector>
#include <deque>
 
std::vector<std::vector<int>> matrix;
std::vector<int> mark;
std::vector<int> color;
std::vector<int> colorNow;
int n;
int result = -1;
 
void dfs(int v)
{
    mark[v] = 1;
    for (int i = 1; i <= n; i++)
    {
        colorNow[i] = 0;
    }
    int count = 0;
    for (int u : matrix[v])
    {
        count++;
        colorNow[color[u]] = 1;
    }
    result = result > count ? result : count;
 
    for (int i = 1; i <= n; i++)
    {
        if (colorNow[i] == 0)
        {
            color[v] = i;
            break;
        }
    }
 
    for (int i = 0; i <= matrix[v].size() - 1; i++)
    {
        if (mark[matrix[v][i]] == 0)
        {
            dfs(matrix[v][i]);
        }
    }
}
 
int main()
{
    int m, a, b;
    std::cin >> n;
    std::cin >> m;
    matrix.resize(n + 1, std::vector<int>(0));
    mark.resize(n + 1, 0);
    color.resize(n + 1, 0);
    colorNow.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1);
    int countLast = -1;
    for (int i = 1; i <= n; i++)
    {
        int count = -1;
        for (int i = 1; i <= n; i++)
        {
            count = count >= color[i] ? count : color[i];
        }
        if (count <= result)
        {
            break ;
        }
    }
    std::cout << (result % 2 == 0 ? result + 1 : result) << "\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << color[i] << "\n";
 
    }
}
