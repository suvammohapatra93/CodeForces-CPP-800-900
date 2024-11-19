
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int testCases;
    int minDiff;
    cin >> testCases >> minDiff;

    vector<int> heights(testCases);
    for (int i = 0; i < testCases; i++)
    {
        cin >> heights[i];
    }

    long long count = 0;
    for (int i = 0; i < testCases; i++)
    {
        for (int j = 0; j < testCases; j++)
        {
            if (i != j && abs(heights[i] - heights[j]) <= minDiff)
            {
                // i!=j because to consider same elemenets
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}