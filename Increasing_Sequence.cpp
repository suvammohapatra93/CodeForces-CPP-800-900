#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<long long> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int moves = 0;
    // For each element starting from second element
    for (int i = 1; i < n; i++)
    {
        // If current element is not greater than previous element
        if (b[i] <= b[i - 1])
        {
            // Calculate how many times we need to add d to make it greater
            long long diff = b[i - 1] - b[i] + 1;
            long long additions = (diff + d - 1) / d; // Ceiling division

            // Add d required number of times
            b[i] += additions * d;
            moves += additions;
        }
    }

    cout << moves << endl;
    return 0;
}