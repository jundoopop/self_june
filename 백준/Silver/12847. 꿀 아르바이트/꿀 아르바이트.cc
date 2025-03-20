#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> earnings(n);
    
    for (int i = 0; i < n; i++) {
        cin >> earnings[i];
    }
    
    // Compute initial sum of first `m` days
    long long max_sum = 0, current_sum = 0;
    for (int i = 0; i < m; i++) {
        current_sum += earnings[i];
    }
    max_sum = current_sum;
    
    // Use sliding window to find the maximum earnings in `m` consecutive days
    for (int i = m; i < n; i++) {
        current_sum += earnings[i] - earnings[i - m];
        max_sum = max(max_sum, current_sum);
    }
    
    cout << max_sum << "\n";
    return 0;
}
