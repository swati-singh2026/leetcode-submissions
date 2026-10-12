// Single-Threaded CPU — DSA Notes

## Pattern

Sorting + Min Heap + Simulation

## Problem

Given tasks with [enqueueTime, processingTime], return the order in which the CPU processes them.

Rules:

CPU processes one task at a time.
Choose the available task with the shortest processing time.
If processing times are equal, choose the smaller original index.
If no task is available, move time to the next task's arrival.

## Recognition Clue

Scheduling tasks based on arrival time.
Choose the minimum processing time among available tasks.
Need efficient minimum selection → Min Heap.

## Algorithm

Store each task's arrival time, processing time, and original index.
Sort tasks by arrival time.
Initialize currentTime = 0 and a min heap of (processingTime, index).
Add all tasks whose arrival time is <= currentTime to the heap.
If the heap is empty, jump currentTime to the next task's arrival time.
Remove the task with the smallest processing time (then smallest index).
Add its index to the answer and update currentTime.
Repeat until all tasks are processed.
Return the answer.

## Pseudocode

Sort tasks by arrival time
Initialize minHeap, ans
currentTime = 0
i = 0

While tasks remain OR heap is not empty:

    If heap is empty:
        currentTime = max(currentTime, next arrival time)

    While next task has arrived:
        Push (processingTime, originalIndex) into heap
        i++

    Remove task with smallest processingTime and index
    Add its index to ans
    currentTime += processingTime

Return ans

## Complexity

Time: O(n log n) — Sorting and heap operations.
Space: O(n) — Sorted tasks, heap, and answer array.

## Mistake / Learning

❌ Don't select the shortest task from all tasks.
✅ Select the shortest task among currently available tasks.
❌ Don't forget the tie-breaker.
✅ Equal processing times → smaller original index first.
❌ Don't keep time unchanged when the heap is empty.
✅ Jump to the next arrival time.
✅ Use long long for currentTime because processing times can be large.

## 1-Minute Interview Explanation 🎤

“This problem can be solved using sorting, a min heap, and simulation.

First, I sort the tasks by their enqueue time and store their original indices. I use a min heap to select the available task with the smallest processing time. If two tasks have the same processing time, the smaller index is selected.

Whenever the CPU becomes free, I add all tasks that have arrived to the heap. If the heap is empty, I move the current time to the next task's arrival time. Then I process the selected task and update the current time.

The time complexity is O(n log n), and the space complexity is O(n).”

## Revision Trick (30 sec)

Sort by Arrival Time
↓
Add Available Tasks to Min Heap
↓
Choose Minimum Processing Time
↓
Update Current Time
↓
Repeat → Return Order
