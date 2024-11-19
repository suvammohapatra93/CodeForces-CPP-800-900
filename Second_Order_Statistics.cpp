#include <iostream>
#include <set>

int main()
{
    int n;
    std::cin >> n;

    // Using set to automatically sort and remove duplicates
    std::set<int> unique_numbers;

    // Read n numbers and insert them into the set
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        unique_numbers.insert(num);
    }

    // If we have less than 2 unique numbers, there is no second order statistic
    if (unique_numbers.size() < 2)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }

    // Get iterator to beginning of set and advance it once to get second element
    auto it = unique_numbers.begin();
    ++it;

    // Print the second smallest unique number
    std::cout << *it << std::endl;

    return 0;
}