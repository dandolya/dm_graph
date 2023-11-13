#include <iostream>
#include <vector>
#include <set>

int n;
std::vector<int> result;

void func (std::vector<std::set<int>> list, bool isPlus)
{
    int flag = -1;
    for (int i = 0; i < list.size(); i++)
    {
        if (!list[i].empty())
        {
            flag = i;
            break ;
        }
    }
    if (flag == -1)
    {
        if (isPlus)
        {
            result[n - list.size()]++;
        }
        else
        {
            result[n - list.size()]--;
        }
    }
    else
    {
        std::vector<std::set<int>> list1(list.size(), std::set<int>());
        std::vector<std::set<int>> list2(list.size() - 1, std::set<int>());
        int flag2 = *list[flag].begin();
        for (int i = 0; i < list.size(); i++)
        {
            for (int j : list[i])
            {
                if (!(i == flag && j == flag2 || i == flag2 && j == flag))
                {
                    list1[i].insert(j);
                }
            }
        }
        if (flag > flag2)
        {
            std::swap(flag, flag2);
        }

        for (int i = 0; i < list1.size(); i++)
        {
            for (int j : list1[i])
            {
                int a = i;
                int b = j;
                if (a >= flag2)
                {
                    a--;
                }
                if (b >= flag2)
                {
                    b--;
                }
                if (i == flag2)
                {
                    a = flag;
                }
                if (j == flag2)
                {
                    b = flag;
                }
                if (a == flag)
                {
                    if (list2[a].find(b) != list2[a].end())
                    {
                        continue ;
                    }
                }
                list2[a].insert(b);
            }
        }
        func(list1, isPlus);
        func(list2, !isPlus);
    }
}

int main()
{
    int m, a, b;
    std::cin >> n >> m;
    result.resize(n, 0);
    std::vector<std::set<int>> list(n, std::set<int>());
    for (int i = 1; i <= m; i++)
    {
        std::cin >> a >> b;
        list[a - 1].insert(b - 1);
        list[b - 1].insert(a - 1);
    }
    func(list, true);
    std::cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << 0;
    return 0;
}
