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


/*Return type and the parameter type is important here do follow*/
void *thread_func(void *param){
  thread_param_t *my_param =(thread_param_t *)param;
  printf("my value=%d ",my_param->value);
  printf("MSG from MAIN= %s ",my_param->msg_from_main);
  while (1) {
    /* looping*/
  }
}

int main(int argc, char const *argv[]) {
  pthread_t thread1,thread2,thread3,thread4,thread5;
  
  thread_param_t *parm_t1;
  thread_param_t parm_t2 = {.value=2,.msg_from_main="You are Thread 2 \n "};

  parm_t1 = (thread_param_t *)malloc( sizeof(struct threads_parameter));
  parm_t1->value=1;
  strcpy(parm_t1->msg_from_main,"You are thread 1 \n ");

  pthread_attr_t thread1_attr,thread2_attr;
 
  pthread_attr_init(&thread1_attr);
  pthread_attr_init(&thread2_attr);
  
  pthread_create(&thread1,&thread1_attr,thread_func,(void *)parm_t1);
  pthread_create(&thread2, &thread2_attr , thread_func ,(void *)&parm_t2);
  void *retval;
  
  pthread_join(thread1,&retval);
  pthread_join(thread2,&retval);
  
  printf("\n all threads have exited \n");

  return 0;
}       
