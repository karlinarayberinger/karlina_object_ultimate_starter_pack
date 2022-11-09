//
// file: square_root_approximation.cpp
// type: C++ (source file)
// date: 08_NOVEMBER_2022
// author: Karlina Ray Beringer (@karbytes)
// license: PUBLIC_DOMAIN
// description: The command line application which is generated by the C++ source code in this file implements the Babylonian method to compute the approximate square root of some real number.
//

/* preprocessing directives */
#include <iostream> // command line input and output
#include <fstream> // file input and output
#define MAXIMUM_N 1000 // constant which represents maximum N value
#define MINIMUM_N -1000 // constant which represents minimum N value

/* program entry point */
int main()
{
	// Declare a file output stream object named file.
	std::ofstream file;

	// Declare a double type variable (i.e. a variable for storing floatin-point number values) named N. 
	// Set the intial value which is stored in N to one.
	double N = 1.0;

	// Declare a long double type variable (i.e. a variable for storing floating-point number values) named S. 
	// Set the intial value which is stored in S to one.
	// S will represent the approximate square root of N.
	long double S = 1.0;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

	/**
	 * If the file named square_root_approximation_output.txt does not already exist inside of the same 
	 * file directory as does the file named square_root_approximation.cpp, 
	 * create a new file named square_root_approximation_output.txt.
	 * 
	 * Open the plain-text file named square_root_approximation_output.txt 
	 * and set that file to be overwritten with program data.
	 */
	file.open("square_root_approximation_output.txt");

	// Print an opening message to the command line terminal.
	std::cout << "\n\n--------------------------------";
	std::cout << "\nSTART OF PROGRAM";
	std::cout << "\n--------------------------------";

	// Print an opening message to the file output stream.
	file << "--------------------------------";
	file << "\nSTART OF PROGRAM";
	file << "\n--------------------------------";

	// Print a closing message to the command line terminal.
	std::cout << "\n\n--------------------------------";
	std::cout << "\nEND OF PROGRAM";
	std::cout << "\n--------------------------------\n\n";

	// Print a closing message to the file output stream.
	file << "\n\n--------------------------------";
	file << "\nEND OF PROGRAM";
	file << "\n--------------------------------";

	// Close the file output stream.
	file.close();

	// Exit the program.
	return 0;
}