#include <pthread.h>
#include <bits/stdc++.h>
#include <semaphore.h>
using namespace std;

int buffer_size;
int *buffer;
int num_items;
sem_t full, sem_empty;
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *param) {
    int in = 0;
    for (int i = 0; i < num_items; i++) {
        sem_wait(&sem_empty); 
        //This will block the producer thread if the buffer is full

        pthread_mutex_lock(&buffer_mutex); 
        //This ensures that no other thread 
        //can access the buffer while the producer is modifying it
        
        buffer[in] = i; //insert the current item into the buffer at the position indicated by in
        
        in = (in) % buffer_size; // if it exceeds buffer_size, it is set back to 0 using the modulo operator
        
        cout << "Produced " << i << endl;
        pthread_mutex_unlock(&buffer_mutex); //allow other threads to access the buffer. 

        sem_post(&full); // This indicates to the consumer thread that there is at least one item in the buffer that can be consumed.
    }
}

void *consumer(void *param) {
    //same as prducer but with consumer thread
    int out = 0;
    for (int i = 0; i < num_items; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&buffer_mutex);
        cout << "Consumed " << buffer[out] << endl;
        out = (out) % buffer_size;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&sem_empty); // Signal sem_empty
    }
}
int main() {
    cout << "Enter the size of the buffer: ";
    cin >> buffer_size;

    cout << "Enter the number of items to produce: ";
    cin >> num_items;

    buffer = (int*)malloc(buffer_size * sizeof(int));

    pthread_t threads[2];

    sem_init(&full, 0, 0);
    sem_init(&sem_empty, 0, buffer_size);
    pthread_create(&threads[0], 0, producer, 0);
    pthread_create(&threads[1], 0, consumer, 0);
    pthread_join(threads[0], 0);
    pthread_join(threads[1], 0);
    sem_destroy(&full);
    sem_destroy(&sem_empty);

    return 0;
}
