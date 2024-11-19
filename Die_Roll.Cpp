

#include <iostream>
using namespace std;

// Function to find GCD for fraction reduction
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int y, w;
    cin >> y >> w;

    // Find the highest roll between Yakko and Wakko
    int max_points = max(y, w);

    // Calculate favorable outcomes (possibilities for Dot to win)
    // Dot needs to roll >= max_points to win
    int favorable = 6 - max_points + 1;

    // Total possible outcomes (sides of die)
    int total = 6;

    // If no favorable outcomes possible
    if (favorable <= 0)
    {
        cout << "0/1" << endl;
        return 0;
    }

    // Find GCD to reduce the fraction
    int divisor = gcd(favorable, total);

    // Output reduced fraction
    cout << favorable / divisor << "/" << total / divisor << endl;

    return 0;
}