#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <unistd.h>

FILE *file;
char str[69];

void *firstThread(void *arg) {
    file = fopen("angka.txt", "w");
    if (file == NULL) {
        perror("Gagal membuka file.\n");
        return NULL;
    }
    for(int i = 0; i < 1000000; i++){
        if (i % 10 == 0 && i != 0) {
            fprintf(file, "\n");
        }
        fprintf(file, "%d  |  ", i + 1);
    }

    fclose(file);
    return NULL;
}

void *secondThread(void *arg) {
    system("mkdir latihan");
    for(int i = 0; i < 1000; i++){
        sprintf(str, "mkdir latihan/%d", i + 1);
        system(str);
        sprintf(str, "cp angka.txt latihan/%d", i + 1);
        system(str);
    }

    return NULL;
}

int main() {
    pthread_t tid[2];

    pthread_create(&(tid[0]), NULL, &firstThread, NULL);
    pthread_create(&(tid[1]), NULL, &secondThread, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}