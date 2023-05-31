#include <iostream>
#include <vector>

using namespace std;

vector<pair<string, pair<float, float>>> best_items;  // The items packed in the container with their weight and value
float best_value = 0;  // The total value of the items packed in the container

void backtrack(vector<pair<string, pair<float, float>>> current_items, float current_weight, float current_value, vector<pair<string, pair<float, float>>> remaining_items, float container_capacity) {
    // Check if the current combination is feasible and update the best combination if necessary
    if (current_weight <= container_capacity && current_value > best_value) {
        best_items = current_items;
        best_value = current_value;
    }

    // Explore all possible combinations of items
    for (int i = 0; i < remaining_items.size(); i++) {
        pair<string, pair<float, float>> item = remaining_items[i];
        vector<pair<string, pair<float, float>>> new_items = current_items;
        new_items.push_back(item);
        float new_weight = current_weight + item.second.first;
        float new_value = current_value + item.second.second;
        vector<pair<string, pair<float, float>>> new_remaining_items(remaining_items.begin() + i + 1, remaining_items.end());
        backtrack(new_items, new_weight, new_value, new_remaining_items, container_capacity);
    }
}

int main() {
    vector<pair<string, pair<float, float>>> items = {{"item1", {10, 20}}, {"item2", {5, 10}}, {"item3", {15, 30}}, {"item4", {5, 10}}, {"item5", {10, 20}}};
    float container_capacity = 30;
    backtrack({}, 0, 0, items, container_capacity);
    cout << "Best items: ";
    for (pair<string, pair<float, float>> item : best_items) {
        cout << item.first << " ";
    }
    cout << endl;
    cout << "Best value: " << best_value << endl;
    return 0;
}
