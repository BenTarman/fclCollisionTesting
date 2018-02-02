#include <iostream>
#include <fcl/shape/geometric_shapes.h>
#include <fcl/collision.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace fcl;

void* doCollision(void*);

CollisionResult result;
CollisionRequest request;

//two box objects to test
Box *s1 = new Box(2,2,2);
Box *s2 = new Box(2,2,2);

int main()
{
    pthread_t thread1, thread2, thread3, thread4;
    int retr1, retr2;

    retr1 = pthread_create(&thread1, NULL, doCollision, NULL);
    retr2 = pthread_create(&thread2, NULL, doCollision, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    delete s1;
    delete s2;

    return 0;
}

void* doCollision(void* unused)
{
    //call collide function a bunch of times (don't care about result)
    for (unsigned int i = 0; i < 25000; i++)
    	collide(s1, Transform3f(Vec3f(2,2,2)), s2, Transform3f(Vec3f(3,3,3)), request, result);
    pthread_exit(NULL);
}



