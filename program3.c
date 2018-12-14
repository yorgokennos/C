/***********************************************
Author:	Yorgo A. Kennos
Date:	December 2, 2018
Purpose: Program converts inputed lengths and 
weights to and from Metric and US systems. 
User can choose the type of conversion through a text menu.
**************************************/

#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);
void exit_command(void);
void clear_keyboard_buffer(void);
void length_to_metric(void);
void length_to_metric_conversion(int *feet, double *inches);
void length_to_metric_output(int *meters, double *cm);
void length_to_us(void);
void length_to_us_conversion(int *meters, double *centimeters);
void length_to_us_output(int *feet, double *inches);
void weight_to_metric(void);
void weight_to_metric_conversion(int *lbs, double *ounces);
void weight_to_metric_output(int *kg, double *grams);
void weight_to_us(void);
void weight_to_us_conversion(int *kilograms, double *grams);
void weight_to_us_output(int *lbs, double *ounces);

int main(int argc, char argv[]) {
	int num;

	printf("Welcome to the weight/length converter !\n");
	do {
		printf("1. convert lengths\n");
		printf("2. convert weights\n");
		printf("0. Exit\n");
		printf("Please choose from (1, 2, 0): ");
		scanf("%d", &num);

		if (num == 1)
			convert_lengths();
		else if (num == 2)
			convert_weights();
		else
			clear_keyboard_buffer();
		printf("\n");
	} while (num != 0);

	exit_command();


	return 0;
}

/* Function: convert_lengths
*
*  function doesn't return anything, it only executes a single print statement (stub)
*
*/
void convert_lengths(void) {
	int num;

	printf("\nDo you want to convert lengths from feet/inches to meters/centimeters(1) or from meters/centimeters to feet/inches(2)");
	scanf("%d", &num);

	if (num == 1) {
		length_to_metric();
	}

	else if (num == 2) {
		length_to_us();
	}

	else if (num == 0) {
		return;
	}

	else {
		clear_keyboard_buffer();
		convert_lengths();
	}
}

/*
		length_to_metric:
		Handles reading user input and error checking
*/
void length_to_metric(void) {
	int feet;
	double inches;
	printf("Enter Feet and inches separated by a space(i.e: 5 4.4): ");
	scanf("%d %lf", &feet, &inches);

	//makes sure that input is not a char, and that negative values weren't entered

	if ((feet == 0 && inches == 0) || (feet < 0) || (inches < 0)) {
		clear_keyboard_buffer();
		printf("Error reading input, please try again\n");
		length_to_metric();
	}

	//call to conversion function
	length_to_metric_conversion(&feet, &inches);

}

/*
		length_to_metric_conversion:
		Does the conversion from Us to Metric
*/
void length_to_metric_conversion(int *feet, double *inches) {
	double temp, centimeters;
	int meters = 0;

	temp = (double) ((*feet * 12.0) + *inches); //total inches
	
	temp *= 2.54; //total height in centimeters

	while (temp > 100) { //counts the number of meters
		temp = temp - 100;
		meters++;
	}

	centimeters = temp;

	length_to_metric_output(&meters, &centimeters);
	
}

/*
		length_to_metric_output:
		Outputs the converted values
*/
void length_to_metric_output(int *meters, double *cm) {
	printf("Converted Length is: %d meters, %lf centimeters\n", *meters, *cm);
}

/*
		length_to_us:
		Reads input from the user and checks for any input error
*/
void length_to_us(void) {
	int meters;
	double centimeters;
	printf("Enter meters and centimeters separated by a space(i.e: 2 1.3): ");
	scanf("%d %lf", &meters, &centimeters);

	//makes sure that input is not a char, and that negative values weren't entered

	if ((meters == 0 && centimeters == 0) || (meters < 0) || (centimeters < 0)) {
		clear_keyboard_buffer();
		printf("Error reading input, please try again\n");
		length_to_us();
	}

	//call to conversion function
	length_to_us_conversion(&meters, &centimeters);

}

/*
		length_to_us_conversion:
		Does the conversion from Metric to US
*/
void length_to_us_conversion(int *meters, double *cm) {
	double temp, inches;
	int feet = 0;

	temp = (double)((*meters * 100) + *cm); //total centimeters

	temp *= 0.393701; //total height in inches

	while (temp >= 12) { //counts the number of feet out of the total number of inches
		temp = temp - 12;
		feet++;
	}

	inches = temp;

	length_to_us_output(&feet, &inches);
}


/*
		length_to_us_output:
		Outputs the converted values to the screen
*/
void length_to_us_output(int *feet, double *inches) {
	printf("Converted Length is: %d feet %lf inches\n", *feet, *inches);

}




/* Function: convert_weights
*
*  Prompts user to input weight, checks for input error
*
*/
void convert_weights(void) {
	int num;

	printf("\nDo you want to convert weights from pounds/ounces to kilograms/grams(1) or from kilograms/grams to pounds/ounces(2)");
	scanf("%d", &num);

	if (num == 1) {
		weight_to_metric();
	}

	else if (num == 2) {
		weight_to_us();
	}

	else if (num == 0) {
		return;
	}

	else {
		clear_keyboard_buffer();
		convert_weights();
	}
}

/*
	 weight_to_metric:
	 converts US weights to Metric weights
*/
void weight_to_metric(void) {
	int pounds;
	double ounces;
	
	printf("Please enter weight in the format Pounds and Ounces separated by a space (i.e: 195 4.58): ");
	scanf("%d %lf", &pounds, &ounces);

	while ((pounds == 0 && ounces == 0) || ((pounds < 0) || (ounces < 0))) {
		clear_keyboard_buffer();
		printf("Error reading input, please try again\n");
		weight_to_metric();
		
	}

	//call to function for unit conversion
	weight_to_metric_conversion(&pounds, &ounces);
}


/*
		weight_to_metric_conversion:
		Handles the unit conversion from US to Metric weights

*/
void weight_to_metric_conversion(int *lbs, double *ounces) {
	double temp, grams;
	int kilograms = 0;

	temp = (*lbs * 16.0) + *ounces; //weight entered in total ounces
	temp = temp / 0.035274; //total weight in grams

	while (temp >= 1000) { //counts the number of kg in total grams
		temp -= 1000;
		kilograms++;
	}

	grams = temp; //remaining grams that don't make up one kilogram

	weight_to_metric_output(&kilograms, &grams);

}
/*
		weight_to_metric_output
		outputs the converted values to the screen

*/
void weight_to_metric_output(int *kg, double *grams){
	printf("Converted weight is %d kilograms %lf grams\n", *kg, *grams);

}
void weight_to_us(void) {
	int kilograms;
	double grams;

	printf("Please enter weight in the format Kilograms and Grams separated by a space (i.e: 80 35): ");
	scanf("%d %lf", &kilograms, &grams);

	while ((kilograms == 0 && grams == 0) || ((kilograms < 0) || (grams < 0))) {
		clear_keyboard_buffer();
		printf("Error reading input, please try again\n");
		weight_to_metric();

	}

	//call to function for unit conversion
	weight_to_us_conversion(&kilograms, &grams);
}

void weight_to_us_conversion(int *kilograms, double *grams) {
	double temp, ounces;
	int pounds= 0;

	temp = (*kilograms * 1000) + *grams; //total weight entered in grams
	temp = temp *0.035273962; //total weight in ounces

	while (temp >= 16) { //counts the number of pounds in the total ounces
		temp -= 16;
		pounds++;
	}

	ounces = temp; //remaining grams that don't make up one kilogram

	weight_to_us_output(&pounds, &ounces);

}
/*
	 weight_to_us:
	 converts Metric to US weights
*/
void weight_to_us_output(int *lbs, double *ounces) {
	printf("The converted weight is %d lbs %lf oz\n", *lbs, *ounces);

}


/* Function: exit_command
*
*  function doesn't return anything, it only executes a single print statement
*
*/
void exit_command(void) {
	printf("User chose to exit. \n\n");


}
/* Function: clear_keyboard_buffer
*
*  it keeps scanning the next character until it reaches '\n'
*
*
*/
void clear_keyboard_buffer(void) {
	char ch;

	scanf("%c", &ch); //reads for a character

	while (ch != '\n') { //would work with '\0' as long as the user hits enter
		scanf("%c", &ch);
	}
}
