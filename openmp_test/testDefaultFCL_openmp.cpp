#include <iostream>
#include <fcl/shape/geometric_shapes.h>
#include <fcl/collision.h>
#include <fcl/continuous_collision.h>
#include <fcl/ccd/motion.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>



#define NUM_THREADS 	4
using namespace std;
using namespace fcl;





int main()
{
Transform3f tf0(Vec3f(1,1,1)), tf1(Vec3f(2,2,2));
Transform3f tf;

CollisionResult result;
CollisionRequest request;
Transform3f tf2 = Transform3f(Vec3f(0.416767, 0.332619, 0.552623));

    std::shared_ptr<Box> box0(new Box(0.02,0.02,0.02));
    std::shared_ptr<Box> box1(new Box(0.03,0.02,0.02));
    tf0 = Transform3f(Vec3f(0.1,0.1,0.1));
    tf1 = Transform3f(Vec3f(0.1,0.1,0.1));

    CollisionObject c0(box0, tf0);
    CollisionObject c1(box1, tf1);

    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
    {
  	collide(&c0, &c1, request, result);
    }

}







