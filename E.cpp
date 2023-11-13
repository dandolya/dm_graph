#include <iostream>
#include <vector>
#include <set>
 
std::vector<std::vector<int>> matrix;
 
int main()
{
    int n;
    std::cin >> n;
    matrix.resize(n + 1, std::vector<int>(0));
    for (int i = 1; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    std::set<int> leaves;
    for (int i = 1; i <= n; i++)
    {
        if (matrix[i].size() == 1)
        {
            leaves.insert(i);
        }
    }
    for (int j = 0; j < n - 2; j++)
    {
                int i = *leaves.begin();
                std::cout << matrix[i][0] << " ";
                //удалить ребро matrix[i][0] - matrix
                leaves.erase(leaves.begin());
                for (int k = 0; k < matrix[matrix[i][0]].size(); k++)
                {
                    if (matrix[matrix[i][0]][k] == i)
                    {
                        auto iter = matrix[matrix[i][0]].cbegin();
                        matrix[matrix[i][0]].erase(iter + k);
                        if (matrix[matrix[i][0]].size() == 1)
                        {
                            leaves.insert(matrix[i][0]);
                        }
                        break;
                    }
                }
                matrix[i].resize(0);
 
    }
}
