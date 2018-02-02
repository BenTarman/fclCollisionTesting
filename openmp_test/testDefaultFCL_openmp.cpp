#include <iostream>
#include <fcl/shape/geometric_shapes.h>
#include <fcl/collision.h>
#include <fcl/continuous_collision.h>
#include <fcl/ccd/motion.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 4
using namespace std;
using namespace fcl;

int main()
{
Box *s1 = new Box(2,2,2);
Box *s2 = new Box(5, 5, 5);

CollisionRequest request;
CollisionResult result;

omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for
for (unsigned int i = 0; i < 250; i++)
{
  collide(s1, Transform3f(Vec3f(0, 2, 3)), s2, Transform3f(Vec3f(2,2,2)), request, result);
}

delete s1;
delete s2;

    return 0;

}













