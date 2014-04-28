#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<signal.h>

#define num_producer 3 
#define num_consumer 3   //由于题目要求生产者和消费者各有两个以上，故此处均定为3个
#define BUFFER_SIZE 20  //定义缓冲区的大小，按题目要求为20
int NUM=1;	//题目要求放入/取出的数据项按增序设定为1-20，因此定义此全局变量
int buffer[BUFFER_SIZE]; 
int nextp=0,nextc=0;
sem_t empty,full,mutex;

//主函数
int main()
{
    int i;
    signal(SIGALRM,handler);
    sem_init(&empty,0,BUFFER_SIZE); 
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);
    for(i=0;i<BUFFER_SIZE;i++) 
        buffer[i]=0;
    for(i=0;i<num_producer;i++) 
        pthread_create(&threads_p[i],NULL,(void*)producer_thread,(void*)(i+1));
    for(i=0;i<num_consumer;i++) 
        pthread_create(&threads_c[i],NULL,(void*)consumer_thread,(void *)(i+1));	
    for(i=0;i<num_producer;i++) 
        pthread_join(threads_p[i],NULL);
    for(i=0;i<num_consumer;i++) 
        pthread_join(threads_c[i],NULL);
    sem_destroy(&empty);  
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}
//消费者代码
void *consumer_thread(void *tid)
{
    int i;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);	
    while(1)
    {
        sem_wait(&full);
        srand((int)time(NULL)*(int)tid);
        sem_wait(&mutex);
        printf("Consumer:%d\tPointer:%d\t\n",(int)tid,nextc);
        buffer[nextc]=0;
        nextc=(nextc+1)%20;	
        printf("buffer:");
        for(i=0;i<BUFFER_SIZE;i++)
        {   
            printf("%3d",buffer[i]);
        }
        printf("\n");
        sem_post(&mutex);
        sem_post(&empty); 
        srand((int)time(NULL)*(int)tid);
        sleep(1);   
    }
    return ((void*)0);
}
//生产者代码
void *producer_thread(void *tid)
{
    int i;
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);	
    while(1)
    {
        sem_wait(&empty);
        srand((int)time(NULL)*(int)tid);
        sleep(1); 
        while((nextp+1)%20==nextc);
        sem_wait(&mutex);
        if(NUM>20) NUM=1;//如果大于20，NUM重新为1
        buffer[nextp]=(NUM++);
        nextp=(nextp+1)%20;
        if(nextp==0)
        {   
            printf("Producer:%d\tPointer:19\t\n",(int)tid);
        }
        else
        {
            printf("Producer:%d\tPointer:%d\t\n",(int)tid,nextp-1);
        }
        printf("buffer:");
        for(i=0;i<BUFFER_SIZE;i++)
        {
        printf("%3d",buffer[i]);
        }
        printf("\n");
        sem_post(&mutex);
        sem_post(&full); 
        srand((int)time(NULL)*(int)tid);
    }
    return ((void*)0);
}
