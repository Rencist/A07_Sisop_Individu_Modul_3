#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define PI 3.14

int main()
{
    key_t key = 1234;
    double *luas, *luas_permukaan;
    int r = 7;

    int shmid = shmget(key, sizeof(double), IPC_CREAT | 0666);
    luas = shmat(shmid, NULL, 0);

    *luas = PI * r * r;
    printf("Luas lingkaran: %f\n", *luas);

    int shmid2 = shmget(key + 1, sizeof(double), 0666);
    luas_permukaan = shmat(shmid2, NULL, 0);

    double harga = *luas_permukaan * 25;
    printf("Total harga cat: %f\n", harga);

    return 0;
}