Systems Programming CS214 Project 1


Nihar Biradar nb769
Tyler Uhl tbu3


DESIGN OF PROGRAM:
The first step was getting an understanding of how malloc and free worked and their uses that we looked into Free utilizes this same pointer to deallocate the memory allocated by malloc to be used for other purposes Test our design of malloc with errors that would not normally be accounted for with the regular dynamic allocation. We used the same general methodology as the pseudocode given to us in recitation. The header of each chunk is two integers, the first declaring the length of the block, the second declaring whether the block is free. The malloc method walks through the heap as if it was a linked list, using the length of the current block as a pointer to the next header. It finds a block large enough to fit the allocation and then adjusts the length of the next block accordingly. Free method is a little more complicated. It walks through the blocks similarly to malloc, but checks if the next block is the pointer to be freed. If the next block is supposed to be free, and the current block is currently free, it combines the two blocks. If the current block is not free, it goes to the pointed-to block and checks if the next block is free, if it is then it combines both of those blocks. Otherwise, it just makes the pointed-to block free. It is also important to note that after error messages are printed, the program exits on EXIT_FAILURE, this is to notify the client that there was an error so they don’t continue to write code with faulty malloc/free.


TEST CASES


Case 1: In test1, the program allocates 1 byte of memory and immediately releases it 120 times. This test is designed to evaluate the performance of the memory management system when memory is allocated and immediately released.


Case 2: test2 allocates 1 byte of memory at 120 consecutive locations, then releases each allocation. This is meant to test the memory management system’s performance with consecutive memory allocations and deallocations.


Case 3: It randomly decides whether to allocate 1 byte of memory or release an allocated memory, and it does this 120 times. This is designed to test the memory management system’s performance under more complex memory allocation and deallocation scenarios.


Case 4: The main objective of test case 4 is to verify that our malloc can allocate memory in the middle of the heap when there is sufficient space. The allocated memory block in the middle should have the correct size and position within the heap. The heap should remain contiguous and free from fragmentation after deallocation. No memory leaks or issues with our malloc should be detected.


Case 5: The main objective is to determine whether our malloc can successfully fill the entire heap with allocations until no more memory is available.The heap should be filled entirely without issues and no memory leaks should be detected. Our malloc should handle allocation failures when the heap is full.


Case 6: The main objective of this test case is to determine whether malloc can detect and handle double freeing of memory, which is a common source of memory errors in C programs.


Case 7: The main objective of this test case is to create a test case that demonstrates errors when attempting to free a NULL pointer. It should remain valid since freeing a NULL pointer should have no effect.


Case 8: The main objective of this test case is to verify that our malloc library can correctly handle freeing and reallocating memory in the middle of the heap while ensuring that freed memory is properly tracked and available for reuse


Case 9: The main objective of this test case is to demonstrate how our malloc library handles freeing memory outside the allocated heap and ensures that it protects against undefined behavior and crashes in such cases.


Case 10: This test case is to handle heap overflow. We exceed the allocated memory to test how our malloc library handles excessive memory allocations.


Case 11: This checks overflowing of the heap. It tries to allocate memory when the heap is full. This does not work, on top of that it tries to free the pointer that was never properly allocated, this also produces an error like it should.