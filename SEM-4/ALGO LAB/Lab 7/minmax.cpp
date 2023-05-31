#include <iostream>
#include <climits>

using namespace std;

void find_min_and_max(int arr[], int start, int end, int &min_val, int &max_val){
    if (start == end){ // Base case: only one element in the subarray
        if (max_val < arr[start])
            max_val = arr[start];
        if (min_val > arr[end])
            min_val = arr[end];
        return;
    }
    if (end - start == 1){ // Base case: two elements in the subarray
        if (arr[start] < arr[end]){
            if (min_val > arr[start])
                min_val = arr[start];
            if (max_val < arr[end])
                    max_val = arr[end];
        }
        else {  //start==end
            if (max_val < arr[start])
                max_val = arr[start];
            if (min_val > arr[end])
                min_val = arr[end];
            
        }
        return;
    }
    int mid = (start + end) / 2;

    find_min_and_max(arr, start, mid, min_val, max_val);
    find_min_and_max(arr, mid + 1, end, min_val, max_val);
}
int main(){
    int arr[] = { 77, 2, 9, 3, 1, 6, 7, 8, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int max_val = INT_MIN, min_val = INT_MAX;

    find_min_and_max(arr, 0, arr_size - 1, min_val, max_val);

    cout << "The minimum value in the array is " << min_val << endl;
    cout << "The maximum value in the array is " << max_val << endl;

    return 0;
}
