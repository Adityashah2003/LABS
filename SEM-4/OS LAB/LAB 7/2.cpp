#include <pthread.h>
#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std;
/*db is a binary semaphore used to ensure exclusive access to the shared resource 
, while mtx is a counting semaphore used to coordinate the access of multiple readers 
to the shared resource. readcount keeps track of the number of active readers.*/
sem_t db, mtx;
int readcount = 0;

void *writer(void *a){
    int arg = static_cast<int>(reinterpret_cast<long>(a));

    sem_wait(&db);
    cout << "W - Writer " << arg << " is operating" << endl;
    cout << "W - Writer " << arg << " done" << endl;
    sem_post(&db);
}

void *reader(void *a){
    int arg = static_cast<int>(reinterpret_cast<long>(a));

    sem_wait(&mtx);
    readcount++;
    if(readcount == 1)
        sem_wait(&db);
    sem_post(&mtx);
    cout << "R - Reader " << arg << " is operating" << endl;

    sem_wait(&mtx);
    readcount--;
    if (readcount == 0)
        sem_post(&db);
    cout << "R - Reader " << arg << " done" << endl;
    sem_post(&mtx);
}

int main(){
    int r, w;
    cout << "Enter the number of readers and writers: ";
    cin >> r >> w;

    pthread_t readers[r], writers[w];
    sem_init(&mtx, 0, 1);
    sem_init(&db, 0, 1);

    int i=0;
    while(i<r||i<w){
        if(i<r)
            pthread_create(&readers[i], 0, reader,(void *)(long)(i+1));
        if(i<w)
            pthread_create(&writers[i], 0, writer,(void *)(long)(i+1));
        i++;
    }

    i=0;
    while(i<r || i<w){
        if(i<r)
            pthread_join(readers[i], 0);
        if(i<w)
            pthread_join(writers[i], 0);
        i++;
    }
    sem_destroy(&mtx);
    sem_destroy(&db);
    return 0;
}
