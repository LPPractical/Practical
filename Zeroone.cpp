#include <iostream>
#include <vector>

const int MAX_N = 1e3 + 2;

int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n;  // Number of items
    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::vector<int> weights(n);
    std::vector<int> values(n);

    std::cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Item " << i + 1 << ":\n";
        std::cout << "Weight: ";
        std::cin >> weights[i];
        std::cout << "Value: ";
        std::cin >> values[i];
    }

    int capacity;
    std::cout << "Enter the knapsack capacity: ";
    std::cin >> capacity;

    int maxValue = knapsack(capacity, weights, values, n);
    std::cout << "Maximum value in the knapsack: " << maxValue << "\n";

    return 0;
}
