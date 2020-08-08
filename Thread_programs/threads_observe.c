/* threads_observe.c creates a five threads.
** These threads does nothing just looping in a while.
** Hence we can the use ps,Top and other utilities to observer the behavior of
** the threads by changing its attributes.
** AUTHOR : Rishap Singh
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct threads_parameter
{
  int value;
  char msg_from_main[128];
}thread_param_t;

/*Global data */
pthread_t thread1,thread2,thread3,thread4,thread5;

/*Return type and the parameter type is important here do follow
**To make the thread loop forever
*/
void *thread_func_loop(void *param){
  thread_param_t *my_param =(thread_param_t *)param;
  printf("my value=%d ",my_param->value);
  printf("MSG from MAIN= %s ",my_param->msg_from_main);
  while (1) {
    /* looping*/
  }
}

/*Return type and the parameter type is important here do follow
**To make the thread create another thread and pass local parameters
**to created thread and exit itself to see the effect.
*/
void *thread_creater(void * param){

  printf("\n I am Mother creating 2 thread");
 
  
  thread_param_t *parm_t3;
  thread_param_t parm_t4 = {
    .value=4,
    .msg_from_main="\n You are Thread 4 A child of Thread2\n"
    };

  parm_t3 = (thread_param_t *)malloc( sizeof(struct threads_parameter));
  parm_t3->value=3; 
  strcpy(parm_t3->msg_from_main,"\n You are Thread 3 A child of Thread2\n");

  pthread_attr_t thread3_attr,thread4_attr;
 
  pthread_attr_init(&thread3_attr);
  pthread_attr_init(&thread4_attr);
  
  pthread_create(&thread3,&thread3_attr,thread_func_loop,(void *)parm_t3);
  pthread_create(&thread4, &thread4_attr , thread_func_loop ,(void *)&parm_t4);
 
  printf("\n Mother is going to sleep \n");
}

int main(int argc, char const *argv[]) {

  thread_param_t *parm_t1;
  thread_param_t parm_t2 = {.value=2,.msg_from_main="You are Thread 2 \n "};

  parm_t1 = (thread_param_t *)malloc( sizeof(struct threads_parameter));
  parm_t1->value=1; 
  strcpy(parm_t1->msg_from_main,"You are thread 1 \n ");

  pthread_attr_t thread1_attr,thread2_attr;
 
  pthread_attr_init(&thread1_attr);
  pthread_attr_init(&thread2_attr);
  
  pthread_create(&thread1,&thread1_attr,thread_func_loop,(void *)parm_t1);
  pthread_create(&thread2, &thread2_attr , thread_creater ,(void *)&parm_t2);
  void *retval;
  
  pthread_join(thread1,&retval);
  pthread_join(thread2,&retval);
  
  printf("\n all threads have exited \n");

  return 0;
}       
