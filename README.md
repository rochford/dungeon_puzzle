# dungeon_puzzle
Coding test (time constrained solution) - HitPoints required to traverse a dungeon grid. 


Notes: This implementation would done in about 3 hours.
Some of that time was spent on utility functions like printing the dungeon and generating a random dungeon.

## Rules (as i remember them)
1. Knight starts in Top left corner.
2. Knight needs to travel to Princess in bottom right corner of dungeon.
3. Knight can only move RIGHT or DOWN.
4. Each square has a HitPoint value to be added or deducted from the Knight.

## Task
Calculate the minimum amount of HitPoints the Knight initially needs to reach the Princess.

## Compiling
g++ -std=c++0x dungeon.cpp

## Drawbacks

This implementation does not process all of the possible routes through the dungeon. Instead the implemention
randomly decides to go DOWN or RIGHT. If the completed route is better than any of the previous random routes
travelled then the required Knight HitPoints is updated. Several iterations of the possible routes are examined,
the amount of iterations depends on the size of the dungeon.

For large dungeon grids the amount of iterations may be too much. For dungeon grids upto about 8x8 it seems okay.

## Sample Output

$ ./a.out 1 1
 2,
Minimum Knight HitPoints to rescue princess: -2
$ ./a.out 2 2
 0, -2,
-4, -3,
Minimum Knight HitPoints to rescue princess: 5
$ ./a.out 2 2
 1, -3,
-1, -2,
Minimum Knight HitPoints to rescue princess: 2
$ ./a.out 2 2
-4, -3,
 1, -3,
Minimum Knight HitPoints to rescue princess: 6
$ ./a.out 2 2
-3,  0,
-3,  1,
Minimum Knight HitPoints to rescue princess: 2
$ ./a.out 2 2
 1, -3,
-3, -3,
Minimum Knight HitPoints to rescue princess: 5
$ ./a.out 3 3
-3,  0,  0,
-1,  0,  0,
 2, -1, -4,
Minimum Knight HitPoints to rescue princess: 7
$ ./a.out 3 3
 0, -2,  2,
 1, -2, -1,
 0, -1, -1,
Minimum Knight HitPoints to rescue princess: 1
$ ./a.out 3 3
 1, -3,  1,
 0,  0, -3,
 2,  1, -3,
Minimum Knight HitPoints to rescue princess: -1
$ ./a.out 3 3
 1, -3, -2,
-2, -2, -1,
 2, -1,  0,
Minimum Knight HitPoints to rescue princess: 0
$ ./a.out 3 3
-1, -3,  2,
 0, -4,  0,
 1, -2, -1,
Minimum Knight HitPoints to rescue princess: 3
$ ./a.out 4 4
 2,  1, -3, -3,
-2,  0, -2, -2,
-4,  1,  0, -3,
 0, -2, -2, -3,
Minimum Knight HitPoints to rescue princess: 1
$ ./a.out 4 4
-3, -2,  0,  2,
 2, -1,  2, -3,
 2, -1,  2, -3,
-4,  0,  2,  2,
Minimum Knight HitPoints to rescue princess: -6
$ ./a.out 3 2
-1, -4,
 1, -3,
-1,  1,
Minimum Knight HitPoints to rescue princess: 0
$ ./a.out 3 2
-4, -2,
-2,  1,
 0, -1,
Minimum Knight HitPoints to rescue princess: 6
$ ./a.out 3 5
-1, -1,  0,  2,  0,
 2,  0, -2, -2, -2,
 0,  1, -4,  0, -1,
Minimum Knight HitPoints to rescue princess: 3
$ ./a.out 3 5
-1, -4,  0, -3,  2,
-4,  2,  1,  2,  1,
 2,  2,  0, -2,  1,
Minimum Knight HitPoints to rescue princess: -2
$ ./a.out 3 5
-2, -1, -2,  0, -2,
 1, -4, -2, -1,  0,
-2,  1, -2, -3,  2,
Minimum Knight HitPoints to rescue princess: 4

