This Project contains 3 classes, SIMS, Student and StudentDB.

main function will only trigger the SIMS class.

---------------------
-      Student       -
---------------------
Student class manage one student.
It does-
1)It stores data of one student --name, id, age, department, tel--.
2)It checks if the data are in correct format.
3)It converts data to 64 bytes data block.
4)It converts 64 bytes data block to desired data.

---------------------
-    Student DB    -
---------------------
StudentDB class manage list of students.
It does-
1)It stores data to file.
2)It restores data from file.
3)It manages list of students, in vector<Students*> form.
3-1)Adding Student into StudentDB
3-2)Sorting Its list
3-3)Finding elements which does matches conditions, and making new StudentDB class.
4)It prints the data to user.

---------------------
-        SIMS        -
---------------------
SIMS is an abbreviation of  Student Information Management System.
It does-
1)It gets input from data and ask to type again, if data are not in desired format.
2)It manages StudentDB.
It does works like some kind of a main function.
