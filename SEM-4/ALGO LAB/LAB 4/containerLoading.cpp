// containerloading.cpp
#include <bits/stdc++.h>

using namespace std;

int ans(int arr[], int capacity, int n){
    sort(arr, arr + n);
    int i = 0;
    int num = 0;
    while (i < n && arr[i] <= capacity){
        num++;
        capacity -= arr[i];
        i++;
        cout<<arr[i]<<" ";
    }
    return num;
}
int main()
{
    int arr[] = {100, 200, 50, 90, 150, 50, 20, 80};
    int capacity = 400;
    int n = sizeof(arr) / sizeof(arr[0]);
    int a = ans(arr, capacity, n);
    cout << a;
}