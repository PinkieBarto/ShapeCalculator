/*										TO-DO: N/A
Shape Calculator								
Created by PinkieBarto						
v1.0
Begun as of 13/11/2016
Completed as of 05/12/2016
*/
#include <iostream>																		//libraries
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;																//using these for validation purposes
using std::streamsize;
using std::string;

void menu();
void exitSystem();
void helpGuide();
void circleArea(double pi);
void circleCircum(double pi);															//function declarations for the demanded shapes, passing pi in order to reuse it in both circle calculations
void rectanArea();
void triangArea();
void cubVol();

int main()
{
	menu();
	return 0;
}

void menu()		///menu procedure for choosing a shape
{
	double pi = 3.14159265359;															//declaration of pi which I will be using in the circles (passed)
	string choice;																		//string used for parsing (validation)
	int errorCounter = 0;																//invisible counter in order to reset screen after 4 attempts

	cout << "==========================\n" <<
			"*****Shape calculator*****\n"
			"==========================\n\n"
			"What would you like to do? \n"
			"(1) - Area of a Circle\n"
			"(2) - Circumference of a Circle\n"
			"(3) - Area of a Rectangle\n"
			"(4) - Area of a Triangle\n"
			"(5) - Volume of a Cuboid\n\n"

			"(9) - Help guide to using this program\n"
			"(0) - Exit the program\n\n";
	cin >> choice;

	while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "9" && choice != "0")	//validation for the menu (while choice is not equal to 1-5 + 9 + 0 then retake input)
	{
		cout << "Invalid input, please enter a number of 1-6, 0 to quit or 9 for help guide\n\n";	//outputs an error message each time loop is met
		cin >> choice;																	//retakes input

		cin.clear();																	//clears the variable to allow new input 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');							//ignores/disregards the whole stream (input)
		errorCounter++;																	//adds to the error counter each time an error is entered 

		if (errorCounter==4)															//once 4 errors are entered, this is activated
		{
			system("CLS");
			menu();
		}
	}

	int choiceInt = atoi(choice.c_str());												//converts the string to an integer in order to function inside a switch case
	system("CLS");

	switch (choiceInt)																	//uses the new int converted from string to use in this switch case (switch for the different subsections of program)
	{
	case 1:
		circleArea(pi);
		break;
	case 2:
		circleCircum(pi);
		break;
	case 3:
		rectanArea();
		break;
	case 4:
		triangArea();
		break;
	case 5:
		cubVol();
		break;
	case 9:
		helpGuide();
		break;
	case 0:
		exitSystem();
		break;

	default:
		cout << "Invalid input, please enter a number of 1-5, 0 to quit or 9 for help guide\n\n";		//the program will never end up here, but if it will then congratulations to whoever accomplished this..
		menu();
		break;
	}
}

void helpGuide()	///displays the instructions to using the program
{
	string choice;																				//string used for parsing (validation)
	int errorCounter = 0;																		//invisible counter in order to reset screen after 4 attempts
	
	cout << "*==============*\n" <<
			"*  Help Guide  *\n"
			"*==============*\n\n"
			"Select a shape to view more information about it.\n"
			"(1) - Area of a Circle\n"
			"(2) - Circumference of a Circle\n"
			"(3) - Area of a Rectangle\n"
			"(4) - Area of a Triangle\n"
			"(5) - Volume of a Cuboid\n\n"

			"(0) - Return to main menu or exit the program\n";
	cin >> choice;

	while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "0")	//validation for the menu (while choice is not equal to 1-5 + 0 then retake input)
	{
		cout << "Error! please enter a number of 1-5, or 0 to exit\n\n";						//outputs an error message each time loop is met
		cin >> choice;																			//retakes input

		cin.clear();																			//clears the variable to allow new input 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');									//ignores/disregards the whole stream (input)
		errorCounter++;																			//adds to the error counter each time an error is entered 

		if (errorCounter == 4)																	//once 4 errors are entered, this is activated
		{
			system("CLS");
			helpGuide();
		}
	}

	int choiceInt = atoi(choice.c_str());														//converts the string to an integer in order to function inside a switch case
	system("CLS");

	switch (choiceInt)																			//uses the new int converted from string to use in this switch case (switch for the different subsections of program)
	{
	case 1:
		cout << "*================*\n" <<
				" Area of a circle\n"
				"*================*\n\n"
				"The program will ask you to input the radius of your circle, please make sure to only input\n"
				"numbers AND no number bigger than 500. It will then calculate the area using pi*radius*radius\n"
				"and display the answer, which will be in centimeters^2.After this, you may choose to either quit\n"
				"or return to the menu and start over.\n\n";
		break;

	case 2:
		cout << "*=========================*\n" <<
				"  Circumference of circle\n"
				"*=========================*\n\n"
				"The program will ask you to input the radius of your circle, please make sure to only input\n"
				"numbers AND no number bigger than 500. It will then calculate the circumference using pi*radius*2\n"
				"and display the answer, which will be in centimeters^2. After this, you may choose to either quit\n"
				"or return to the menu and start over.\n\n";
		break;

	case 3:
		cout << "*=====================*\n" <<
				"  Area of a Rectangle\n"
				"*=====================*\n\n"
				"The program will ask you to firstly input the height of your rectangle\n"
				"and then ask you to input the width while displaying the entered height.\n"
				"Please make sure to only input numbers AND no number bigger than 500. It\n"
				"will then calculate the rectangle using height*width and display the\n"
				"answer, which will be in centimeters^2. After this, you may choose to either\n"
				"quit or return to the menu and start over.\n\n";
		break;

	case 4:
		cout << "*=====================*\n" <<
				"  Area of a Triangle\n"
				"*=====================*\n\n"
				"The program will ask you to firstly input the base measurement of your\n"
				"triangle and then ask you to input the height while displaying the entered base.\n"
				"Please make sure to only input numbers AND no number bigger than 500. It\n"
				"will then calculate the triangle using base*height / 2 and display the\n"
				"answer, which will be in centimeters^2. After this, you may choose to either\n"
				"quit or return to the menu and start over.\n\n";
		break;

	case 5:
		cout << "*===================*\n" <<
				" Volume of a Cuboid\n"
				"*===================*\n\n"
				"The program will ask you to firstly input the length of your cuboid\n"
				"and then ask you to input width while displaying the entered length\n"
				"and finally ask you to input the height while displaying the entered\n"
				"length and width. Please make sure to only input numbers AND no numbers\n"
				"bigger than 500. It will then calculate the volume using length*width*height\n"
				"and display the answer in centimeters^3. After this, you may choose to\n"
				"either quit or return to the menu and start over.\n\n";
		break;

	case 0:
		exitSystem();
		break;

	default:
		cout << "Invalid input, please enter a number between 1-5, or 0 to quit\n\n";				//the program will never end up here, but if it will then congratulations to whoever accomplished this..			
		helpGuide();
		break;
	}
	exitSystem();
}

void circleArea(double pi)	///the area of circle function
{
	double radius = 0.0;																			//used for user input of radius			
	bool badInput;																					//used for invalid input validation

	cout << "*================*\n" <<
			" Area of a circle\n"
			"*================*\n\n";

	do																								//extreme value validation for radius
	{
		do																							//user validation for radius
		{
			cout << "Please enter the radius of your circle (numerical value not bigger than 500):\n\n";
			cin >> radius;

			badInput = cin.fail();																	//badInput is met if cin has failed
			cin.clear();																			//clears the variable to allow new input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');									//ignores/disregards the whole stream (input) or a new line
		} while (badInput);																			//runs the loop on badInput
	} while (radius<1 || radius>500);																//this checks whether extreme values have been entered, if yes then repeats the loop. 

	system("CLS");
	cout << "The area of your Circle is:\n\n" << pi*radius*radius << "cm^2" << endl << endl;		//display the calculation which is calculated using the user input, essentially the formula is PI*radius(squared) just reversed
	exitSystem();
}

void circleCircum(double pi)	///the circumference of circle function
{
	double radius = 0.0;																					//used for user input of radius			
	bool badInput;																							//used for invalid input validation

	cout << "*=========================*\n" <<
			"  Circumference of circle\n"
			"*=========================*\n\n";
	do																										//extreme value validation for radius
	{
		do																									//user validation for radius
		{
			cout << "Please enter the radius of your circle (numerical value not bigger than 500):\n\n";
			cin >> radius;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (radius<1 || radius>500);

	system("CLS");
	cout << "The circumference of your Circle is:\n\n" << pi*radius * 2 << "cm^2" << endl << endl;			//calculates the circumference using the user input, formula is 2*PI*radius but reversed and then displays it
	exitSystem();
}

void rectanArea()	///procedure for area of rectangle
{
	double rectanHeight = 0.0;																				//used for user input for height
	double rectanWidth = 0.0;																				//used for user input for width
	bool badInput;																							//used for invalid input validation

	cout << "*=====================*\n" <<
			"  Area of a Rectangle\n"
			"*=====================*\n\n";

	do																										//extreme value validation for rectanHeight
	{
		do																									//user validation for rectanHeight
		{
			cout << "Please enter the height of your rectangle (numerical value not bigger than 500):\n\n";
			cin >> rectanHeight;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (rectanHeight<1 || rectanHeight>500);
	
	system("CLS");
	cout << "Height = " << rectanHeight << endl << endl;													//displays the entered height after width has been entered, in case user forgot

	do																										//extreme value validation for rectanWidth
	{
		do																									//user validation for rectanWidth
		{
			cout << "Please enter the width of your rectangle (numerical value not bigger than 500):\n\n";
			cin >> rectanWidth;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (rectanWidth<1 || rectanWidth>500);
	system("CLS");

	cout << "The area of your Rectangle is:\n\n" << rectanHeight*rectanWidth << "cm^2" << endl << endl;		//calculates the area of rectangle using the input, formula is height*width then displays it
	exitSystem();
}

void triangArea()	///procedure for area of triangle
{
	double triangBase = 0.0;																						//used for user input for base
	double triangHeight = 0.0;																						//used for user input for height
	bool badInput;																									//used for invalid input validation

	cout << "*=====================*\n" <<
			"  Area of a Triangle\n"
			"*=====================*\n\n";

	do																												//extreme value validation for triangBase
	{
		do																											//user validation for triangBase
		{
			cout << "Please enter the base measurement of your Triangle (numerical value not bigger than 500)\n\n";
			cin >> triangBase;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (triangBase<1 || triangBase>500);
	system("CLS");

	cout << "Base = " << triangBase << endl << endl;

	do																												//extreme value validation for triangHeight
	{
		do																											//user validation for triangHeight
		{
			cout << "Please enter the height of your Triangle (numerical value not bigger than 500)\n\n";			//displays inputted base and then asks for the height
			cin >> triangHeight;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (triangHeight<1 || triangHeight>500);
	system("CLS");

	cout << "The area of your Triangle is:\n\n" << triangBase*triangHeight / 2 << "cm^2" << endl << endl;			//calculates area using user input and displays it, formula is base*height/2
	exitSystem();
}

void cubVol()	///procedure for volume of a cuboid
{
	double cubLength = 0.0;																							//used for user input for length
	double cubWidth = 0.0;																							//used for user input for width
	double cubHeight = 0.0;																							//used for user input for height
	bool badInput;																									//used for invalid input validation

	cout << "*===================*\n" <<
			" Volume of a Cuboid\n"
			"*===================*\n\n";

	do																												//extreme value validation for cubLength
	{
		do																											//user validation for cubLength
		{
			cout << "Please enter the length of your Cuboid (numerical value not bigger than 500)\n\n";
			cin >> cubLength;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (cubLength<1 || cubLength>500);
	system("CLS");

	cout << "Length = " << cubLength << endl << endl;																//displays entered cubLength and asks for cubWidth

	do																												//extreme value validation for cubWidth
	{
		do																											//user validation for cubWidth
		{
			cout << "Please enter the width of your Cuboid (numerical value not bigger than 500)\n\n";
			cin >> cubWidth;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (cubWidth<1 || cubWidth>500);
	system("CLS");

	cout << "Length = " << cubLength << endl << "Width = " << cubWidth << endl << endl;								//displays entered cubLength and cubWidth then asks for cubHeight

	do																												//extreme value validation for cubHeight
	{
		do																											//user validation for cubHeight
		{
			cout << "Please enter the height of your Cuboid: (numerical value not bigger than 500)\n\n";
			cin >> cubHeight;

			badInput = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (badInput);
	} while (cubHeight<1 || cubHeight>500);
	system("CLS");

	cout << "The volume of your Cuboid is:\n\n" << cubLength*cubWidth*cubHeight << "cm^3" << endl << endl;			//displays the calculation using user input, formula is length*width*height
	exitSystem();
}

void exitSystem()	///procedure for the exit/return system
{
	string choice;																								//string for parsing (validation)

	cout << "Press 'r' to return to the menu\nPress 'q' to quit the program\n\n";
	cin >> choice;

	while (!(choice == "r" || choice == "q" || choice == "R" || choice == "Q"))									//runs loop while choice is not equal to 'r' or 'q' (case sensitive)
	{
		cout << "Invalid input! Please enter 'r' to return OR 'q' to quit!\n\n";
		cin >> choice;

		cin.clear();																							//resets the variable for another input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');													//ingnores the whole stream or if there is a new line
	}

	if (choice == "q" || choice == "Q")																			//if choice is equal to 'q' or 'Q', do the code below (exit the program)
	{
			system("CLS");
			cout << "**************************************\n" <<
					"**************************************\n"
					"*******    T H A N K  Y O U    *******\n"
					"*******    F O R  U S I N G    *******\n"
					"******* T H I S  P R O G R A M *******\n"
					"**************************************\n"
					"**************************************\n"
					"Program will exit in 5 seconds...\n";
			_sleep(1000);																						//sleeps for 5 seconds before exiting to avoid instant closure of program
			cout << "...4\n";
			_sleep(1000);
			cout << "...3\n";
			_sleep(1000);
			cout << "...2\n";
			_sleep(1000);
			cout << "...1";
			_sleep(1000);
			exit(0);
	}
	
	else if (choice == "r" || choice == "R")																	//if choice is equal to 'r' or 'R', do the code below (return to menu)
	{
		system("CLS");
		menu();
	}
} 
