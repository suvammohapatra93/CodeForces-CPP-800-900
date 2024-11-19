#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; // number of matchboxes burglar can carry
    int m;       // number of containers
    cin >> n >> m;

    // Vector to store pairs of (matches per box, number of boxes)
    vector<pair<int, int>> containers;

    // Read input
    for (int i = 0; i < m; i++)
    {
        int boxes, matches;
        cin >> boxes >> matches;
        containers.push_back({matches, boxes});
    }

    // Sort containers by matches per box in descending order
    sort(containers.begin(), containers.end(), greater<pair<int, int>>());

    long long total_matches = 0;
    long long boxes_taken = 0;

    // Take boxes from containers with highest matches per box first
    for (const auto &container : containers)
    {
        int matches_per_box = container.first;
        int available_boxes = container.second;

        // Calculate how many boxes we can take from this container
        long long boxes_to_take = min(n - boxes_taken, (long long)available_boxes);

        if (boxes_to_take <= 0)
            break;

        // Add matches from these boxes to total
        total_matches += boxes_to_take * matches_per_box;
        boxes_taken += boxes_to_take;

        if (boxes_taken == n)
            break;
    }

    cout << total_matches << endl;

    return 0;
}