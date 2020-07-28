/* threads_observe.c creates a five threads.
** These threads does nothing just looping in a while.
** Hence we can the use ps,Top and other utilities to observer the behavior of
** the threads by changing its attributes.
** AUTHOR : Rishap Singh
*/

#include <pthread.h>
#include <stdio.h>

typedef struct threads_parameter
{
  int value;
  char msg_from_main[128];
}thread_param_t;


/*Return type and the parameter type is important here do follow*/
void *thread_func(void *param){
  while (1) {
    /* looping*/
  }
}

int main(int argc, char const *argv[]) {
  pthread_t thread1,thread2,thread3,thread4,thread5;
  
  thread_param_t *parm_t1;
  thread_param_t parm_t2{.value=2,.msg_};
  
  pthread_create(&thread1,);



  return 0;
}
