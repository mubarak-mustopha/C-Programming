#include <stdio.h>
#include <pthread.h>


int cokes = 2000000;
pthread_mutex_t cokes_thread = PTHREAD_MUTEX_INITIALIZER;

void* drink_lots(void *a){
    int i;

    for (i=0; i < 100000; i++) {
        pthread_mutex_lock(&cokes_thread);
        cokes = cokes - 1;
        pthread_mutex_unlock(&cokes_thread);
    }
    printf("cokes = %i\n", cokes);
    return NULL;
}

int main(){
    pthread_t threads[20];
    int t;
    printf("%i bottles of beer on the wall\n%i bottles of beer\n", cokes, cokes);

    for(t = 0;t < 20; t++){
        pthread_create(&threads[t], NULL, drink_lots, NULL);
    }

    void* result;
    for(t = 0;t < 20; t++){
        pthread_join(threads[t], &result);
    }

    printf("There are now %i bottles of beer on the wall\n", cokes);
    return 0;
}