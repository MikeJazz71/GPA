/*This is a GPA calculator.  It will ask you for the total number of classes that you have taken, then provide you with a scale that 
ranges 0 - 4 and the higher numerical value equals a higher grade.  It will then ask if you recieved a plus or a minus in the class
and then either add or deduct 0.3 to the grade based on the + of - inputted.  It will then calculate your GPA by taking the accumlated 
points and dividing them by the total credits attempted.  It then outputs your total credit hours and your GPA.*/

/*Issues that I had were I set many of my varibles to the int type (such as totalHours and grade) but then I was trying to use it in the 
GPA calculation and it was truncating my double.  So I made them all doubles.  Also the plus and minus adjusment took some careful planning 
testing.  I first just subtracted the adjustment varible and it was taking the ASCII value for "-" (45) and I entered an A (4) and my 
GPA was -41.00 so that took a bit to debug.  I stole the set precision function from the smashTheBugs lesson and applied it to the 
output of the final GPA.*/

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <iomanip> //Allows to set precision in a double
#include <cmath> // Math library
using namespace std; 

int main()	{
	int totalCourses = 0, i = 0, credit = 0; //Integer Varibles
	char adjustment; //Char Varible
	double GPA = 0, totalHours = 0, accPoints = 0, grade = 0; //Doubles used for the accumlator


	cout << "Welcome to the GPA Calculator" << endl << endl; // Title in output box
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl; // Spacing
	cout << "How many courses do you have to enter? " << endl; // Asking for total number of courses
	cin >> totalCourses; // Input courses
	while (totalCourses < 1) { //Exception handling for courses. Must be positive number
		cout << "Input a number greater than zero" << endl;
		cout << "Re-Enter: ";
		cin >> totalCourses;
	}
	while (i < totalCourses) { //Takes number of courses and interates through until all the courses are accounted for
		cout << "How many credit hours did course number " << i + 1 << " have? " << endl; //Asking for Credit hours 
		cin >> credit; //Input of credit hours
		while (credit < 1 || credit > 5) { //Exception handling. Number must be between 1-5
			cout << "Input a number between 1 and 5" << endl;
			cout << "Course have credit hours between one and five credits." << endl;
			cout << "Re - Enter: ";
			cin >> credit;
		}
		cout << endl << endl;
		totalHours = totalHours + credit; 
		cout << "++++++++++++Please Use the Following Scale++++++++++++" << endl; //  Spacing 
		cout << "Enter:" << endl << "4 for A" << endl << "3 for B" << endl << "2 for C" << endl << "1 for D" << endl << "Zero for F" << endl << endl; //Shows Point value for grades to input
		cout << "What was the grade in course number " << i + 1 << "?" << endl; //Asking for grade
		cin >> grade; //Grade input
		while (grade < 0 || grade > 4) { //Exception handling. Grade must be between 0 and 4
			cout << "The grading scale ranges from a number between 4(A) and 0(F)" << endl;
			cout << "Re-Enter class grade (0-4): ";
			cin >> grade;
		}
		cout << "Was the grade a minus or a plus? If so enter - or + now or no for neither" << endl;
		cin >> adjustment;
		cin.ignore(); // Clears buffer
			
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl; //Formatting & spacing
		
		if (grade == 4) { 
			if (adjustment == '-') { //Provides for Grades Plus and Minus
				grade = 3.7;
			}
			else
				grade = 4;
			accPoints = accPoints + (credit * grade); //Multiplies credit hours by grade
		}
		else if (grade == 3) {
			if (adjustment == '+') {
				grade = 3.3;
			}
			else if (adjustment == '-') {
				grade = 2.7;
			}
			else
				grade = 3;
			accPoints = accPoints + (credit * grade);
		}
		else if (grade == 2) {
			if (adjustment == '+') {
				grade = 2.3;
			}
			else if (adjustment == '-') {
				grade = 1.7;
			}
			else
				grade = 2;

			accPoints = accPoints + (credit * grade);
		}
		else if (grade == 1) {
			if (adjustment == '+') {
				grade = 1.3;
			}
			else if (adjustment == '-') {
				grade = .7;
			}
			else
				grade = 1;
			accPoints = accPoints + (credit * grade);
		}
		else {
			accPoints = accPoints + 0;
		}
		i++; //Moves on to next class
		

		}
	GPA = accPoints / totalHours; //Accumlated Points divided by total credit hours
	cout << "Total credit hours were " << totalHours << endl; 
	cout << "Your grade point average is " << setprecision (2) << fixed << GPA << endl << endl;
	return 0;
}
