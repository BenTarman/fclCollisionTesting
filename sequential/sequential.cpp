#include <iostream>
#include <fcl/shape/geometric_shapes.h>
#include <fcl/collision.h>
#include <fcl/continuous_collision.h>
#include <fcl/ccd/motion.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 	4
using namespace std;
using namespace fcl;

int main()
{

	/*
    Transform3f tf0(Vec3f(1,1,1)), tf1(Vec3f(2,2,2));
    Transform3f tf;

    CollisionResult result;
    CollisionRequest request;
    Transform3f tf2 = Transform3f(Vec3f(0.416767, 0.332619, 0.552623));


    //this should result in collision of 2 boxes
    std::shared_ptr<Box> box0(new Box(0.02,0.02,0.02));
    std::shared_ptr<Box> box1(new Box(0.03,0.02,0.02));
    tf0 = Transform3f(Vec3f(0.1,0.1,0.1));
    tf1 = Transform3f(Vec3f(0.1,0.1,0.1));

    CollisionObject c0(box0, tf0);
    CollisionObject c1(box1, tf1);

      //for (unsigned int i = 0; i < 10000000; i += 1)
     // {
  	collide(&c0, &c1, request, result);
     // }
*/

	Box s1(2, 2, 2);
	Box s2(2, 2, 2);
Transform3f transform;
Transform3f identity;
CollisionRequest request;
CollisionResult result;
bool res;
res = (collide(&s1, Transform3f(Vec3f(2,2,2)), &s2, Transform3f(Vec3f(5, 5, 5)), request, result) > 0);
std::cout << "res" << res << std::endl;
    return 0;

}







