#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

int sharedData = 1;
int readerCount = 0;

sem_t mutex;
sem_t rwMutex;

void *reader(void *readerId)
{
    int id = *(int *)readerId;
    while (1)
    {
        sem_wait(&mutex);
        readerCount++;
        if (readerCount == 1)
        {
            sem_wait(&rwMutex);
        }
        sem_post(&mutex);

        printf("Reader %d read shared data: %d\n", id, sharedData);

        sem_wait(&mutex);
        readerCount--;
        if (readerCount == 0)
        {
            sem_post(&rwMutex);
        }
        sem_post(&mutex);

        usleep(rand() % 1000000);
    }
}

void *writer(void *writerId)
{
    int id = *(int *)writerId;
    while (1)
    {
        sem_wait(&rwMutex);

        sharedData++;
        printf("Writer %d wrote shared data: %d\n", id, sharedData);

        sem_post(&rwMutex);

        usleep(rand() % 1000000);
    }
}

int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&rwMutex, 0, 1);

    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    int readerIds[NUM_READERS];
    int writerIds[NUM_WRITERS];

    for (int i = 0; i < NUM_READERS; i++)
    {
        readerIds[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, (void *)&readerIds[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++)
    {
        writerIds[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, (void *)&writerIds[i]);
    }

    for (int i = 0; i < NUM_READERS; i++)
    {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++)
    {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&rwMutex);

    return 0;
}
