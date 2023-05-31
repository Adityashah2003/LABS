#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Item {
    int weight;
    int volume;
    int value;
};

struct PartialSolution {
    int value;
    int weight;
    int volume;
    vector<Item> items;

    bool operator < (const PartialSolution& other) const {
        // compare partial solutions by their upper bound value
        return upper_bound() < other.upper_bound();
    }

    bool is_feasible(int container_weight, int container_volume) const {
        // check if the partial solution satisfies the container constraints
        return weight <= container_weight && volume <= container_volume;
    }

    int upper_bound() const {
        // compute the upper bound value of the partial solution
        int total_value = value;
        for (const auto& item : items) {
            total_value += item.value;
        }
        return total_value;
    }
};

vector<Item> container_loading(const vector<Item>& items, int container_weight, int container_volume) {
    // initialize the heap with an empty partial solution
    priority_queue<PartialSolution> heap;
    heap.push({0, 0, 0, {}});

    // initialize the best solution
    PartialSolution best_solution;

    while (!heap.empty()) {
        // explore the best partial solution in the heap
        PartialSolution partial_solution = heap.top();
        heap.pop();

        // generate new partial solutions by branching on the remaining items
        for (int i = 0; i < items.size(); i++) {
            const auto& item = items[i];
            vector<Item> remaining_items(items.begin() + i + 1, items.end());

            // create a new partial solution by packing the item
            vector<Item> new_items = partial_solution.items;
            new_items.push_back(item);
            int new_value = partial_solution.value + item.value;
            int new_weight = partial_solution.weight + item.weight;
            int new_volume = partial_solution.volume + item.volume;
            PartialSolution new_partial_solution = {new_value, new_weight, new_volume, new_items};

            // check if the new partial solution is feasible
            if (new_partial_solution.is_feasible(container_weight, container_volume)) {
                // update the best solution if the new partial solution is better
                if (new_partial_solution.value > best_solution.value) {
                    best_solution = new_partial_solution;
                }

                // add the new partial solution to the heap
                heap.push(new_partial_solution);
            }
        }
    }

    return best_solution.items;
}

int main() {
    vector<Item> items = {
        {2, 3, 10},
        {4, 2, 12},
        {5, 7, 14},
        {6, 4, 8},
        {3, 5, 6},
        {1, 2, 4},
        {2, 1, 3},
    };

    int container_weight = 10;
    int container_volume = 15;

    vector<Item> packed_items = container_loading(items, container_weight, container_volume);

    for (const auto& item : packed_items) {
        cout << "Item: weight=" << item.weight << ", volume=" << item.volume << ", value=" << item.value << endl;
    }

    return 0;
}
