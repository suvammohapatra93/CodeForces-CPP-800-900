#include <iostream>
#include <string>
#include <vector>

bool checkFlag(int n, int m, std::vector<std::string> &flag)
{
    // Check each row for same color
    for (int i = 0; i < n; i++)
    {
        char color = flag[i][0];
        for (int j = 1; j < m; j++)
        {
            if (flag[i][j] != color)
            {
                return false; // Found different color in same row
            }
        }
    }

    // Check adjacent rows for different colors
    for (int i = 0; i < n - 1; i++)
    {
        if (flag[i][0] == flag[i + 1][0])
        {
            return false; // Adjacent rows have same color
        }
    }

    return true; // All conditions met
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> flag(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> flag[i];
    }

    if (checkFlag(n, m, flag))
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}