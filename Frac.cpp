#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Item {
    int weight;
    int value;
    double ratio;  // Value-to-weight ratio
};

bool compare(Item i1, Item i2) {
    return i1.ratio > i2.ratio;  // Sort items in decreasing order of value-to-weight ratio
}

double fractionalKnapsack(int capacity, std::vector<Item>& items) {
    // Calculate value-to-weight ratio for each item
    for (auto& item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }

    // Sort items based on the value-to-weight ratio in non-increasing order
    std::sort(items.begin(), items.end(), compare);

    double max_value = 0.0;
   
    for (const auto& item : items) {
        if (capacity <= 0) {
            break;
        }

        int weight_taken = std::min(capacity, item.weight);
        double fraction = static_cast<double>(weight_taken) / item.weight;

       
        max_value += fraction * item.value;
        capacity -= weight_taken;
    }

   

    return max_value;
}

int main() {
    int n;  // Number of items
    int capacity;  // Knapsack capacity

    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::vector<Item> items(n);

    std::cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Item " << i + 1 << ":\n";
        std::cout << "Weight: ";
        std::cin >> items[i].weight;
        std::cout << "Value: ";
        std::cin >> items[i].value;
    }

    std::cout << "Enter the knapsack capacity: ";
    std::cin >> capacity;

    double result = fractionalKnapsack(capacity, items);

    std::cout << "Maximum value in the knapsack: " << result << "\n";

    return 0;
}
