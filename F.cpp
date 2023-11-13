#include <iostream>
#include <vector>
#include <set>
 
int main()
{
    int n;
    std::cin >> n;
    n -= 2;
    std::vector<int> counts(n + 2, 0);
    std::vector <int> p(n);
    std::set <int> min;
 
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        p[i]--;
        counts[p[i]]++;
    }
 
    for (int i = 0; i < (n + 2); i++)
    {
        if (counts[i] == 0)
        {
            min.insert(i);
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        std::cout << (*min.begin()) + 1 << " " << p[i] + 1 << "\n";
        counts[p[i]]--;
        min.erase(min.begin());
        if (counts[p[i]] == 0)
        {
            min.insert(p[i]);
        }
 
    }
    for (auto i : min)
    {
        std::cout << i + 1 << " ";
    }
}
