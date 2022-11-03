#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Program:	Project 2
// Author: Justin Nunley
// Date: 9/19/2022
// Course: Mulch-Calc
// At the beginning I have all of the prototypes for the functions used in the program. Above are the standard libraries are included plus math.h
void displayWelcome (void);
double getLength (void);
double getWidth (void);
double getDepth (void);
char getMulch (void);
double computeVolume (double, double, double);
int computeBags (double, char);
void displayResults (double, double, double, double, int, double);
void displayCredits (void);

//Here starts the Main for the program
int main ()
{
	//here is where the variables will be stored/declared in Main
	int numBags;
	double length, width, depth, volume, cost;
	char mulchType;

	//Here the welcome function is called
	displayWelcome ();
	//Here the functions to get the length, width, depth, and mulchType are called and assigned to their appropriate variables.
	length = getLength ();
	width = getWidth ();
	depth = getDepth ();
	mulchType = getMulch ();
    // Here the computing functions are called and assigned to the appropriate variables
	volume = computeVolume (length, width, depth);
	numBags = computeBags (volume, mulchType);
	// The actual price per mulch is processed via a switch statement that selects the appropriate mulch type and processes it assigning it to the cost variable
	switch (mulchType)
	{
		case 'p':
			cost = numBags*3.97;
			break;
		case 'w':
			cost = numBags*3.33;
			break;
		case 'c':
			cost = numBags*3.27;
			break;
        default:
            cost = 0;
            break;
	}
	//The function to display the results is called, accepting all the stored variables from the previous functions
	displayResults (length, width, depth, volume, numBags, cost);
	//The function to display the credits with my name is called here
	displayCredits ();
}
//The function displayWelcome displays a welcome message
void displayWelcome (void)
{
	printf("Welcome to Justin's Mulch Price calculator! Lets get to mulching!\n");
}
/*The function getLength has no parameters and takes the input from the user for length,
then returns the length to main where it is assigned to the length variable in main.*/
double getLength (void)
{
	double length;
	printf("Please enter the length of the area you wish to cover with mulch in feet:");
	scanf("%lf", &length);
	return length;
}
/*The function getWidth has no parameters and takes the input from the user for width,
then returns the width to main where it is assigned to the width variable in main*/
double getWidth (void)
{
	double width;
	printf("Please enter the width of the area you wish to cover with mulch in feet:");
	scanf("%lf", &width);
	return width;
}
/*The function getDepth has no parameters and takes the input from the user for depth,
then returns the depth to main where it is assigned to the depth variable in main*/
double getDepth (void)
{
	double depth;
	printf("Please enter the depth of the area you wish to cover with mulch in feet:");
	scanf("%lf", &depth);
	return depth;
}
/*The function getMulch takes no parameters. It takes the input from the user on the mulch type based on three characters, then validates it.
If the data is incorrect it reprompts them and takes the new input.
If the data is correct it then returns the mulch type and assigns it to the mulchType variable in main.*/
char getMulch (void)
{
	char mulchType;
	printf("Please enter the type of mulch you plan to use with either p for Premium, w for Wood, or c for Cypress:\n");
	scanf(" %c", &mulchType);
	while (mulchType != 'p' && mulchType != 'w' && mulchType != 'c')
	{
        printf("That is an incorrect data type for the mulch. Please enter p form Premium, w for Wood, or c for Cypress mulch.");
		scanf(" %c", &mulchType);
	}
	return mulchType;
}
/*The function computeVolume multiplies the input parameters from the user of length (double), width(double) and depth(double).
It then returns volume, which is then assigned to the volume variable local to main.*/
double computeVolume (double length, double width, double depth)
{
	double volume;
	volume = length*width*depth;
	return volume;
}
/*The function computeBags declares doubles for the number of bags, the cubic feet in all three types of bags (p and c being the same)
After, it uses and if else decision loop to either if mulchType passed by main is w, if this is false, it moves on to the next decision
The first decision divides the volume by the wCubic variable (1.5) and uses the math.h function ceil() to round up to the nearest whole integer.
The second decision divides the volume by the otherCubic variable (2) and uses the math.h function ceil() to round up to the nearest whole integer.
After it returns the numBags value to main where it is assigned to the numBags variable in main */

int computeBags (double volume, char mulchType)
{
	double numBags;
	double wCubic = 1.5;
	double otherCubic = 2;

	if (mulchType == 'w')
	{
		numBags = volume/wCubic;

	}
	else
		{numBags = volume/otherCubic;
		}
		numBags = ceil(numBags);
	return numBags;
}
/*The function displayResults uses all the values collected in the variables in main as parameters
 (the doubles; length, width, depth, volume, and cost as well as the the int numBags.) Using the input parameters it displays the output of the program to the user..*/
void displayResults (double length, double width, double depth, double volume, int numBags, double cost)
{
	printf(" The dimensions of the mulch planter you gave were \n Length: %.4lf \n Width: %.4lf \n Depth: %.4lf \n", length, width, depth);
	printf("The expected supplies and cost of filling the planter are \n Mulch Volume: %.4lf cubic yards \n Number of Bags: %i number of bags \n Total Cost: %.2lf$ \n", volume, numBags, cost);
}
// The function displayCredits takes no input Parameters. It displays the program author's name, and has no return value.
void displayCredits (void)
{
	printf("This mulch calculator has been brought to by Justin Nunley and the character backslashn");
}

/*--Test Data--
~Test 1 input~
Length: 2 feet)
Width: 2 (feet)
Height: 2 (feet)
Mulch Type:p (Premium)
~Expected Results Test 1~
Length: 2 feet)
Width: 2 (feet)
Height: 2 (feet)
Volume: 8 (cubic feet)
Number of Bags: 4
Cost: 15.88 $
-Test 2 Input-
Length:2.667 (feet)
Width:3.2 (feet)
Height:1.875 (feet)
Mulch Type:w (Wood)
~Expected Results Test 2~
Length:2.667 (feet)
Width:3.2 (feet)
Height:1.875 (feet)
Volume:16.002
Number of Bags: 11
Cost: 36.63 $
-Test 3 input-
Length:10(feet)
Width:2.167(feet)
Height:2.334(feet)
Mulch Type:c (Cypress)
~Expected Results Test 3~
Length:10(feet)
Width:2.167(feet)
Height:2.334(feet)
Volume:50.5778
Number of Bags:26
Cost:85.02 $

~Actual Results Test 1~
The dimensions of the mulch planter you gave were
 Length: 2.0000
 Width: 2.0000
 Depth: 2.0000
The expected supplies and cost of filling the planter are
 Mulch Volume: 8.0000 cubic yards
 Number of Bags: 4 number of bags
 Total Cost: 15.88$
This mulch calculator has been brought to by Justin Nunley and the character backslashn
Process returned 0 (0x0)   execution time : 3.031 s
~Actual Results Test 2~
 The dimensions of the mulch planter you gave were
 Length: 2.6670
 Width: 3.2000
 Depth: 1.8750
The expected supplies and cost of filling the planter are
 Mulch Volume: 16.0020 cubic yards
 Number of Bags: 11 number of bags
 Total Cost: 36.63$
This mulch calculator has been brought to by Justin Nunley and the character backslashn
Process returned 0 (0x0)   execution time : 18.438 s
~Actual Results Test 3~
 The dimensions of the mulch planter you gave were
 Length: 10.0000
 Width: 2.1670
 Depth: 2.3340
The expected supplies and cost of filling the planter are
 Mulch Volume: 50.5778 cubic yards
 Number of Bags: 26 number of bags
 Total Cost: 85.02$
This mulch calculator has been brought to by Justin Nunley and the character backslashn
Process returned 0 (0x0)   execution time : 38.573 s\
*/
