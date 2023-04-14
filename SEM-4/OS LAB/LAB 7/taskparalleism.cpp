#include <pthread.h>
#include <sys/wait.h>
#include <signal.h>
#include <bits/stdc++.h>
using namespace std;

void* LinearSearch(void* arg) {
    int* arr = (int*) arg;
    for (int i = 0; i < 3000; i++) {
        if (arr[i] == 50) {
            cout << "Found 50 at index " << i << endl;
            break;
        }
    }
    return NULL;
}
void* BinarySearch(void* arg) {
    int* arr = (int*) arg;
    
    int low = 0, high = 2999;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == 50) {
            cout << "Found 50 at index " << mid << endl;
            break;
        } else if (arr[mid] > 50) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return NULL;
}
int main() {
    cout<<"Inside main thread";
    int arr[3000];
    pthread_t tid_linear, tid_binary;
    clock_t start, end;
    double time_taken_linear, time_taken_binary;

    //generates random ints
    srand(time(NULL));
    for (int i = 0; i < 3000; i++) {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < 3000; i++) {
        for (int j = i + 1; j < 3000; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // for (int i = 0; i < 3000; i++) {
    //     cout << arr[i] << " ";
    // }
    pthread_create(&tid_linear, NULL, LinearSearch, (void*) arr);
    pthread_create(&tid_binary, NULL, BinarySearch, (void*) arr);

    pthread_join(tid_linear, NULL);
    pthread_join(tid_binary, NULL);

    return 0;
}


