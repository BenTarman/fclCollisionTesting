#include <iostream>
#include <fcl/shape/geometric_shapes.h>
#include <fcl/collision.h>
#include <fcl/continuous_collision.h>
#include <fcl/ccd/motion.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace fcl;

void* doCollision(void*);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

struct myStruct
{
  CollisionObject co0;
  CollisionObject co1;

  myStruct() : co0(NULL), co1(NULL) {}
};

Transform3f tf0(Vec3f(1,1,1)), tf1(Vec3f(2,2,2));
Transform3f tf;

CollisionResult result;
CollisionRequest request;
Transform3f tf2 = Transform3f(Vec3f(0.416767, 0.332619, 0.552623));

int main()
{

    std::shared_ptr<Box> box0(new Box(0.02,0.02,0.02));
    std::shared_ptr<Box> box1(new Box(0.03,0.02,0.02));
    tf0 = Transform3f(Vec3f(0.1,0.1,0.1));
    tf1 = Transform3f(Vec3f(0.1,0.1,0.1));

    struct myStruct thread_args;
    thread_args.co0 = CollisionObject(box0, tf0);
    thread_args.co1 = CollisionObject(box1, tf1);

    CollisionObject co0 = thread_args.co0;
    CollisionObject co1 = thread_args.co1;

    pthread_t thread1, thread2;
    int retr1, retr2;

    retr1 = pthread_create(&thread1, NULL, doCollision, (void *)&thread_args);
    retr2 = pthread_create(&thread2, NULL, doCollision, (void *)&thread_args);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


    std::cout << "thread 1: " << retr1 << std::endl;
    std::cout << "thread 2: " << retr2 << std::endl;




}


void* doCollision(void* thread_args)
{
  struct myStruct *args = (struct myStruct*)thread_args;

  CollisionObject c0 = args->co0;
  CollisionObject c1 = args->co1;

  int answer;
  collide(&c0, &c1, request, result);

  if (!request.enable_cost && (result.isCollision()) && (result.numContacts() >= request.num_max_contacts)) {
	  answer = 1;
  }
  else
	  answer = 0;

  //pthread_mutex_lock(&mutex1);
  //pthread_mutex_unlock(&mutex1);
  pthread_exit(NULL);
}





