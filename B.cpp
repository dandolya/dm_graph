#include <iostream>
#include <vector>
#include <deque>
 
std::vector<std::vector<int>> matrix;
std::deque<int> queue;
 
int main()
{
    int n;
    std::cin >> n;
    matrix.resize(n, std::vector<int>(n, 0));
    for (int i = 1; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            matrix[i][j] = s.at(j) - 48;
            matrix[j][i] = s.at(j) - 48;
        }
    }
 
    queue.resize(n);
    for (int i = 0; i < n; i++)
    {
        queue[i] = i;
    }
 
    for (int i = 0; i < n * (n - 1); i++)
    {
        if (matrix[queue[0]][queue[1]])
        {
            queue.push_back(queue[0]);
            queue.pop_front();
        }
        else
        {
            int count = 1;
            while (count < n - 1 && (matrix[queue[0]][queue[count]] == 0 || matrix[queue[1]][queue[count + 1]] == 0))
            {
                count++;
            }
            if (count == n - 1)
            {
                count = 1;
                while (count < n && matrix[queue[0]][queue[count]] == 0)
                {
                    count++;
                }
            }
            for (int j = 0; 1 + j < count - j; j++)
            {
                std::swap(queue[1 + j], queue[count - j]);
            }
            queue.push_back(queue[0]);
            queue.pop_front();
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        std::cout << queue[i] + 1 << " ";
    }
}
