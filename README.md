# Learning to C

After having had a miserable time in Rust, I wanted to go back to basics and 
examine the foundations of programming in a low-level programming language. As 
a result, I started this little project with the goal of going through some 
sorting algorithms and foundational data structures while at the same time 
working directly with memory.

The code here is going to be pretty crappy - by the standards I would like to 
hold myself to first and foremost, but even more so by C standards. As it is 
merely a repository for my adventures into the C language however, it doesn't 
really matter all that much so long as the code compiles, runs, and is somewhat 
readable.

## Commands (in case I forget)
**Building**: `cmake . && make`

**Debugging memory**: `cmake -S . -D CMAKE_BUILD_TYPE=Debug && make && valgrind -s --leak-check=yes --track-origins=yes ./algos`

## Checklist
 - [x] Bubble Sort
 - [x] Selection Sort
 - [x] Insertion Sort
 - [x] Linked List
 - [x] Stack
 - [ ] Queue
 - [ ] Trees
 - [ ] Hash Tables
 - [ ] Heaps
 - [ ] Graphs
 - [ ] Skip Lists
 - [ ] Bloom Filters
 - [ ] Disjoint Sets / Union-Find

