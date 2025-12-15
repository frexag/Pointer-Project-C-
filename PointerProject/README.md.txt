# Pointer-Project-C-

## Alex Griggs CISC 192

# Part D
```
1.  A pointer to stack memory points to an object stored on the stack; it gets automatically cleaned when the function ends and is akin to being told an address that you only need to remember until you find the house. A heap pointer points to an object on the heap, which needs to be created and destroyed; it is like using a phonebook to find an address, but you have to throw it away when you're done, or else it takes too much space. A smart pointer also points to heap memory but it automatically is deleted when you're done, kind of like calling an operator who handles all of the dirty work of actually looking through the phone book and throwing it away for you.
2. At the end of Part B before return 0; in main() I used delete[] tasks; . This frees the array on the heap. If I didn't, the memory would stay allocated causing a memory leak that wastes resources and would cause issues in a long program, system, or server.
3. In part A the stack memory owns the object, and the pointer just shows where to find it. In part B, the heap memory is owned by the program, but the raw pointer has to actually manage it and delete it manually. In part C, the heap memory is owned by the unique_ptr, which manages and deletes the memory for you.
4. I believe the smart pointer is the safest for complex data sets and the pointer to stack memory is the safest for simple data. This is because for complex data the smart pointer is able to manage and delete the memory for you, avoiding memory leaks and keeping the program from being wasteful. The pointer to stack memory is good because it can tell the program where to find the data, without copying it or putting it in a position where it can be changed and there is no risk of forgetting to free the memory.
```