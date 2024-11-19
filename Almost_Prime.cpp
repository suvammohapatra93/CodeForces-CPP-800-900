#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Step 1: Use Sieve of Eratosthenes to find all primes up to n
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Step 2: Count distinct prime divisors for each number
    vector<int> prime_divisor_count(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i; j <= n; j += i) {
                prime_divisor_count[j]++;
            }
        }
    }

    // Step 3: Count numbers with exactly two prime divisors
    int almost_prime_count = 0;
    for (int i = 2; i <= n; ++i) {
        if (prime_divisor_count[i] == 2) {
            almost_prime_count++;
        }
    }

    // Output the result
    cout << almost_prime_count << endl;

    return 0;
}
