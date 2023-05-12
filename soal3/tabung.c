#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define PI 3.14

int main()
{
    key_t key = 1234;
    double *luas, *luas_permukaan;
    int r = 7, t = 10;

    int shmid = shmget(key, sizeof(double), 0666);
    luas = shmat(shmid, NULL, 0);

    int shmid2 = shmget(key + 1, sizeof(double), IPC_CREAT | 0666);
    luas_permukaan = shmat(shmid2, NULL, 0);

    *luas_permukaan = 2 * *luas + 2 * PI * r * t;
    printf("Luas permukaan tabung: %f\n", *luas_permukaan);

    return 0;
}