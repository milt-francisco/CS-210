# Project 3

Initially, an Inventory class is created, and an input file is read. The input file’s contents are distributed to a map in the Inventory class. Additionally, a backup file, “frequency.dat”, is created from the map’s contents. 
This happens behind the scenes with no user interaction. As shown below, the “frequency.dat” file is excluded from the build, 
because it is created at the beginning of the program upon calling the “inventory.saveData” member function. 
##
![image](https://github.com/milt-francisco/Cplusplus-program/assets/121690557/a5459306-9dc8-46a9-b848-9d4444ac5c68)
##
Upon entering the program, the user is displayed a main menu with options to select from. 
The first menu option allows the user to search for a specific item or word; in this case “Spinach”, and displays the amount of the specific item, as shown below. 
##
![image](https://github.com/milt-francisco/Cplusplus-program/assets/121690557/888a1e1f-45c6-42f1-a5da-65047b8fe7a7)
##
The second menu option displays every item (represented by a word) paired with the number of times that item appears in the input file.
##
![image](https://github.com/milt-francisco/Cplusplus-program/assets/121690557/27e87753-0cff-43bd-96cb-b03849dc9319)
##
The third menu option displays the frequency information for all of the items in the form of a histogram. The number of asterisks displayed equal the frequency it was read from the input file.
##
![image](https://github.com/milt-francisco/Cplusplus-program/assets/121690557/c089898d-a827-4edd-a7bb-9433a52dd925)
##
The fourth, and final, menu option allows the user to exit the program and displays “Exiting program.”, as shown below.
##
![image](https://github.com/milt-francisco/Cplusplus-program/assets/121690557/63e8e9ae-d063-420c-b131-4eab048bc061)
## 
Finally, user input validation is accomplished using a “do-while” loop and a “switch” statement, located in the mainMenu helper function (main.cpp). 
If a user does not input a value between 1 and 4, the switch statement’s default case is taken, which clears the input stream, and resets back to the main menu, 
but now with a message to indicate the correct usage of the program.
##
![image](https://github.com/milt-francisco/Cplusplus-program/assets/121690557/b2be875f-f802-4d03-ad46-5d4adde2b28c)
## 
After every correct user selection, the system is “paused” to allow the user to absorb the information that is displayed. 
This is accomplished in Visual C++ by utilizing the <cstdlib> and the phrase, system(“CLS”), which clears the Windows console. 
This allows the user experience to be uncluttered and free of previous selections.
Additionally, the program follows industry standard best practices and utilizes try-catch blocks to catch exceptions thrown in the case of an error in potentially problematic areas of the program.
