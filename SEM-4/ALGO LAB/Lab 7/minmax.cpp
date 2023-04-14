#include <iostream>
#include <climits>

using namespace std;

void find_min_and_max(int arr[], int start, int end, int &minv, int &maxv){
    if (start == end){ // Base case: only one element in the subarray
        if (maxv < arr[start])
            maxv = arr[start];
        if (minv > arr[end])
            minv = arr[end];
        return;
    }
    if (end - start == 1){ // Base case: two elements in the subarray
        if (arr[start] < arr[end]){
            if (minv > arr[start])
                minv = arr[start];
            if (maxv < arr[end])
                    maxv = arr[end];
        }
        else {  //start==end
            if (maxv < arr[start])
                maxv = arr[start];
            if (minv > arr[end])
                minv = arr[end];   
        }
        return;
    }
    int mid = (start + end) / 2;

    find_min_and_max(arr, start, mid, minv, maxv);
    find_min_and_max(arr, mid + 1, end, minv, maxv);
}
int main(){
    int arr[] = { 77, 2, 9, 3, 1, 6, 7, 8, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int maxv = INT_MIN, minv = INT_MAX;

    find_min_and_max(arr, 0, arr_size - 1, minv, maxv);

    cout << "The minimum value in the array is " << minv << endl;
    cout << "The maximum value in the array is " << maxv << endl;

    return 0;
}
