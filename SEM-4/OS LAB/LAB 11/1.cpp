#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<deque>
using namespace std;

// Function to calculate total head movement
int calculateHeadMovement(const deque<int>& queue, int start)
{
    int headMovement = 0;
    int previous = start;

    for (int i = 0; i < queue.size(); i++)
    {
        headMovement += abs(previous - queue[i]);
        previous = queue[i];
    }

    return headMovement;
}

// Function to implement SSTF disk scheduling algorithm
void sstf(const deque<int>& requests, int start)
{
    deque<int> queue(requests);
    deque<int> order;
    int current = start;

    while (!queue.empty())
    {
        // Find the request with the minimum distance from the current head position
        auto it = min_element(queue.begin(), queue.end(), [=](int a, int b)
        {
            return abs(current - a) < abs(current - b);
        });

        int next = *it;
        order.push_back(next);
        queue.erase(it);

        current = next;
    }

    // Print the order in which requests are serviced and the total head movement
    cout << "Order of request service: ";
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    cout << endl;

    cout << "Total head movement: " << calculateHeadMovement(order, start) << endl;
}

// Function to implement SCAN disk scheduling algorithm
void scan(const deque<int>& requests, int start, int size)
{
    deque<int> queue(requests);
    deque<int> order;
    int current = start;
    bool direction = true; // true for upward direction, false for downward direction

    // Sort the requests and insert the boundary points
    if (direction)
        queue.push_back(size - 1);
    else
        queue.push_back(0);

    sort(queue.begin(), queue.end());

    // Find the position of the current head in the sorted queue
    auto it = lower_bound(queue.begin(), queue.end(), current);

    // Handle the requests in the upward direction
    while (it != queue.end())
    {
        int next = *it;
        order.push_back(next);
        it++;

        if (it == queue.end())
        {
            // If we have reached the end of the queue, change direction and add the last request
            direction = false;
            queue.push_front(0);
            it = queue.begin();
        }

        if (next == size - 1)
            break;
    }

    // Handle the requests in the downward direction
    if (!direction)
        queue.push_front(0);
    else
        queue.push_front(size - 1);

    sort(queue.begin(), queue.end(), greater<int>());

    it = lower_bound(queue.begin(), queue.end(), current, greater<int>());
    while (it != queue.end())
    {
        int next = *it;
        order.push_back(next);
        it++;

        if (it == queue.end())
            break;
    }

    // Print the order in which requests are serviced and the total head movement
    cout << "Order of request service: ";
    for (int i = 0; i < order.size(); i++)
        cout << order[i] << " ";
    cout << endl;

    cout << "Total head movement: " << calculateHeadMovement(order, start) << endl;
}

void cscan(vector<int>& requests, int start, int end) {
    int curr_pos = start;
    int n = requests.size();
    int index = 0;
    int total_distance = 0;

    // Sort the requests in ascending order
    sort(requests.begin(), requests.end());

    // Find the position of the current request
    while (index < n && requests[index] < curr_pos) {
        index++;
    }

    // Move the disk head to the end of the disk
    total_distance += abs(curr_pos - end);
    curr_pos = end;

    // Move the disk head to the beginning of the disk
    total_distance += abs(curr_pos - requests[0]);
    curr_pos = 0;

    // Scan the disk from beginning to end
    for (int i = index; i < n; i++) {
        total_distance += abs(curr_pos - requests[i]);
        curr_pos = requests[i];
    }

    // Move the disk head to the end of the disk
    total_distance += abs(curr_pos - end);
    curr_pos = end;

    cout << "Total distance: " << total_distance << endl;
}

// Function to simulate C-LOOK algorithm
void clook(vector<int>& requests, int start, int end) {
    int curr_pos = start;
    int n = requests.size();
    int index = 0;
    int total_distance = 0;

    // Sort the requests in ascending order
    sort(requests.begin(), requests.end());

    // Find the position of the current request
    while (index < n && requests[index] < curr_pos) {
        index++;
    }

    // Scan the disk from the current position to the end
    for (int i = index; i < n; i++) {
        total_distance += abs(curr_pos - requests[i]);
        curr_pos = requests[i];
    }

    // Move the disk head to the beginning of the disk
    total_distance += abs(curr_pos - requests[index - 1]);
    curr_pos = 0;

    // Scan the disk from the beginning to the position of the last request
    for (int i = index - 1; i >= 0; i--) {
        total_distance += abs(curr_pos - requests[i]);
        curr_pos = requests[i];
    }

    cout << "Total distance: " << total_distance << endl;
}

// Main function
int main() {
    int start = 50; // Starting position of the disk head
    int end = 199; // Ending position of the disk head
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67}; // Request queue

    int choice;
    do {
        cout << "Select disk scheduling algorithm:" << endl;
        cout << "1. C-SCAN" << endl;
        cout << "2. C-LOOK" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cscan(requests, start, end);
                break;
            case 2:
                clook(requests, start, end);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
               
        }
    }
}