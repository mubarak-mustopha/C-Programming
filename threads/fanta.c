#include <stdio.h>
#include <pthread.h>

int fantas = 1000000;
pthread_mutex_t fantas_thread = PTHREAD_MUTEX_INITIALIZER;

void * drink_lots(void *a){
    int i;
    pthread_mutex_lock(&fantas_thread);
    for (i=0;i<100000;i++){
        fantas -= 1;
    }
    pthread_mutex_unlock(&fantas_thread);
    printf("There %i fantas left\n", fantas);
    return NULL;
}

int main(){

    pthread_t threads[10];
    int i;
    for ( i=0; i<10; i++){
        pthread_create(&threads[i], NULL, drink_lots,NULL);
    }

    void *result;
    for ( i=0; i<10; i++){
        pthread_join(threads[i], &result);
    }
    return 0;
}