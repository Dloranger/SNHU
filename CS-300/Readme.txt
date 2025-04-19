This CS-300 course involves the itterative investigation of and development of Hash Tables, Sorting Algorithms, Binary Search Trees and other linked structures.

The final project is housed in the Week 7 folder which also includes a summary document of the projects outputs including testing and enhancement features included in the overall functionality.

The goal for this final project is to create an application that can read in from a CSV file the courseID, Course Title, and prerequisites to be used in the application.  During loading, it is required that each prerequisite course must be cross checked to ensure it is a primary course included in the document.

The user interface is a simple console menu with only a couple options that can be used to show all courses with their respective prerequisites, or to search for a single course and see its respective prerequisites.

This project was originally pseudocoded to use a hashtable, but in the end, it could not be made to work with properly sorting the course listings alphanumerically.  It was decided to pivot to using a Binary Search Tree architecture which inherently has an alphanumerical sorting based on the underlying design of a BST.  This project in the end delivers all the customers requirements while also including some additional error handling to ensure ease of use by administrators and end users.

Given more time, further enhancements could be added, including searching for a course and having the prerequisite tree displayed to show all courses that must be fulfilled to be eligable to take the searched for courses.

Through the work done in the earlier exercises, it was clearly demonstrated thru the use of timers within the code, that there can be significant performance improvements by using structures that while are more complex to implement, offer drastically improved operational times.  For example, a bubble sort is very easy to implement and understand, however, it can be severely inefficient when working with very large datasets that need to be sorted.  Alternatively, using hash tables to create smaller buckets to sort or even just using more mathematically advanced sort routines can yield greatly improved results.  While all work was successfully implemented and demonstrated, I feel significantly more practice and detailed understanding will be required before I could independently these approaches without the structured guidance this course provided in the form of almost completed applications.
