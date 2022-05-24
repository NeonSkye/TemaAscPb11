#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *function1();
void *function2();

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int rez = 0;
int a, b, c, d;
int sum, mul, divd;

int main()
{

    int rc1, rc2;
    printf("Introduceti valorile:\n");
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("c=");
    scanf("%d",&c);
    printf("d=");
    scanf("%d",&d);
    pthread_t thread1, thread2;

    if((rc1=pthread_create(&thread1,NULL,&function1,NULL)))
    {
        printf("Eroare thread! %d\n",rc1);
    }
        if((rc2=pthread_create(&thread2,NULL,&function2,NULL)))
    {
        printf("Eroare thread! %d\n",rc2);
    }

    pthread_join(thread1,NULL);

    pthread_join(thread2,NULL);

    printf("(%d+%d+%d)/(%d*%d)=%d\n",a,b,c,b,d,divd);
    printf("Sfarsit program!\n");

    exit(EXIT_SUCCESS);
}

void *function1()
{
        pthread_mutex_lock(&mutex1);
        sum = a+b+c;
        pthread_mutex_unlock(&mutex1);
        sleep(1);

}

void *function2()
{

    pthread_mutex_lock(&mutex1);
    mul = b*d;
    divd = sum/mul;
    pthread_mutex_unlock(&mutex1);
        sleep(1);

}
