#include <pthread.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

pthread_mutex_t lock;
int sum = 0;
#define maxThread  4
#define arraySize 10000
int arr[arraySize];

void *threadSum(void* arg){
    int tid,start,end,local_sum=0;
    tid = *(int*)arg;

    start = tid*(arraySize/maxThread);
    end = (tid+1)*(arraySize/maxThread);

    for(int i=start;i<end;i++){
        local_sum+=arr[i];
    }

    pthread_mutex_lock(&lock);
    sum+=local_sum;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    int i,seq_sum=0;

    srand(time(NULL));
    for(i=0;i<arraySize;i++){
        arr[i] = rand()%100;
    }

    clock_t tStart = clock();
    for(i=0;i<arraySize;i++){
        seq_sum+=arr[i];
    }
    cout<<"seq_sum: "<<seq_sum<<endl;
    cout<<"Time taken by sequential sum: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

    int tid[maxThread];
    pthread_t threads[maxThread];

    sum=0;
    tStart=  clock();
    for(i=0;i<maxThread;i++){
        tid[i] = i;
        pthread_create(&threads[i],NULL,threadSum,(void*)&tid[i]);
    }
    for(i=0;i<maxThread;i++){
        pthread_join(threads[i],NULL);
    }
    cout<<"parallel_sum: "<<sum<<endl;
    cout<<"Time taken by parallel sum: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
    return 0;
}
