#include "my.h"
#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS 5
#define TCOUNT 10
#define COUNT_LIMINT 12

int count =0;
int thread_ids[3] ={0,1,2,3,4};
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void *inc_count(void *idp){
	int j,i;
	double result = 0.0;
	int *my_id=idp;
	for(i =0;i<TCOUNT;i++)
	{
		pthread_cond_signal(&count_threshold_cv);
		printf(""inc_co)

	}


}




int main(int argc,char *argv[]){
	int i,rc;
	pthread_t threads[3];
	pthread_attr_t attr;
	pthread_mutex_init(&count_mutex,NULL);
	pthread_cond_init(&count_threshold_cv,NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_create(&threads[0],&attr,inc_count,(void *)&thread_ids[0]);
	pthread_create(&threads[1],&attr,inc_count,(void *)&thread_ids[1]);
	pthread_create(&threads[2],&attr,inc_count,(void *)&thread_ids[2]);
	pthread_create(&threads[3],&attr,inc_count,(void *)&thread_ids[3]);
	pthread_create(&threads[4],&attr,inc_count,(void *)&thread_ids[4]);
	for(i=0;i<NUM_THREADS;i++)	
	{
		pthread_join(threads[i],NULL);	
	}
	printf("Main():Waited on %d threads.Done.\n",NUM_THREADS);
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	pthread_exit(NULL);





}
