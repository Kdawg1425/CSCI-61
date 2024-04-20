HOMEWORK 4

=======================================================
PROBLEM 1

Created a function called BSTToMinHeap that takes in a root of a BST and 

Converts BST into a Min-Heap. I first convert the BST to a sorted linked list
and then the sorted linked list to a heap. This is done to sort it and heapify it.

Got help for GeeksforGeeks.org "In-place Convert BST into a Min-Heap"

========================================================
PROBLEM 2

The program executes 100 office hours. Gives average wait time, average question time
and average after time.

The average wait time is the cumulative time of the 100 different 60 min office hours
divided by the total number of students that attended the 100 office hours divided by
100 for the 100 office hours to get the average wait time of student in every office hour.

The average question time is the cumulative time students spent asking question with the
professor divided by the total number of students.

The average after office hour time is the total amount after time divided by 100.

Students also have a priority variable that is on a scale of 1 to 3 with 1 being the
highest priority. The number is randomly generated when a new Student is added to
the queue.
    -Students are sorted by this priority variable through the use of priority Queue
      compare operators.

After the main code output is proof that the priority queue does its job
of sorting the queue of Students by highest priority to lowest priority.
