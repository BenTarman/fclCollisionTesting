# fclCollisionTesting

testing fcl collision library (https://github.com/flexible-collision-library/fcl)

parallel collision calling on fcl objects.

This test just makes two fcl objects and calls the 'collide' function in separate threads

which results in a race condition. A similar problem exists for ContinuousCollide.





Makefile INSTRUCTIONS

'make drd' runs valgrind drd

'make helgrind' runs valgrind helgrind

'make run' runs program without valgrind

'make clean' cleans binary










