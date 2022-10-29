//
// file: eulers_number_approximation.cpp
// type: C++ (source file)
// date: 28_OCTOBER_2022
// author: Karlina Ray Beringer (@karbytes)
// license: PUBLIC_DOMAIN
// description: The command line application which is generated by the C++ source code in this file generates an approximation of the the mathematical constant named e (i.e. Euler’s Number) by adding (1/N) to (1/(N – 1)) to (1/(N – 2)) to … (1/(N – (N – 1)) such that N is a natural number.
//

/* preprocessing directives */
#include <iostream> // command line input and output
#include <fstream> // file input and output
#define MAXIMUM_N 1000 // constant which represents maximum N value

/* function prototypes */
int e(int N, std::ostream & output);

/**
 * Generate an approximation of the the mathematical constant named e (i.e. Euler’s Number) 
 * by adding (1/N) to (1/(N – 1)) to (1/(N – 2)) to … (1/(N – (N – 1)) such that N is a natural number.
 */
int e(int N)
{
	// Declare an int type variable (i.e. a variable for storing integer values) named A. 
	// Set the intial value which is stored in A to zero.
	// Declare an int type variable (i.e. a variable for storing integer values) named _N. 
	// Set the intial value which is stored in _N to zero.
	// Declare an int type variable (i.e. a variable for storing integer values) named i. 
	// Set the intial value which is stored in i to zero.
	int A = 0, _N = 0, i = 0;

	// If N is smaller than zero or if N is larger than MAXIMUM_N, set _N to zero.
	// Otherwise, set _N to zero (and set N to _N).
	_N = ((N < 0) || (N > MAXIMUM_N)) ? 0 : N;
	N = _N;

	while (i <= N) 
	{

		// Subtract one from the value which is stored in _N.
		_N -= 1; 

		// Add one to the value which is stored in i.
		i += 1; 
	}

	// Return the value which A represents.
	return A;
}

/* program entry point */
int main()
{
	// Declare a file output stream object named file.
	std::ofstream file;

	// Declare an int type variable (i.e. a variable for storing integer values) named N. 
	// Set the intial value which is stored in N to zero.
	int N = 0;

	/**
	 * If the file named eulers_number_approximation_output.txt does not already exist inside of the same 
	 * file directory as does the file named eulers_number_approximation.cpp, 
	 * create a new file named eulers_number_approximation_output.txt.
	 * 
	 * Open the plain-text file named eulers_number_approximation_output.txt 
	 * and set that file to be overwritten with program data.
	 */
	file.open("eulers_number_approximation_output.txt");

	// Print an opening message to the command line terminal.
	std::cout << "\n\n--------------------------------";
	std::cout << "\nSTART OF PROGRAM";
	std::cout << "\n--------------------------------";

	// Print an opening message to the file output stream.
	file << "--------------------------------";
	file << "\nSTART OF PROGRAM";
	file << "\n--------------------------------";

	// Print "Enter a nonnegative integer which is no larger than {MAXIMUM_N}: " to the command line terminal.
	std::cout << "\n\nEnter a nonnegative integer which is no larger than " << MAXIMUM_N << ": ";

	// Scan the command line terminal for the most recent keyboard input value.
	std::cin >> N;

	// Print "Enter a nonnegative integer which is no larger than {MAXIMUM_N}: " to the command line terminal.
	std::cout << "\n\nEnter a nonnegative integer which is no larger than " << MAXIMUM_N << ": ";

	// Print "Enter a nonnegative integer which is no larger than {MAXIMUM_N}: " to the file output stream.
	file << "\n\nEnter a nonnegative integer which is no larger than " << MAXIMUM_N << ": ";

	// Print "The value which was entered to store inside of the int type variable named N is {N}." to the command line terminal.
	std::cout << "\nThe value which was entered to store inside of the int type variable named N is " << N << ".";

	// Print "The value which was entered to store inside of the int type variable named N is {N}." to the file output stream.
	file << "\n\nThe value which was entered to store inside of the int type variable named N is " << N << ".";

	// If N is smaller than zero or if N is larger than MAXIMUM_N, set N to zero.
	N = ((N < 0) || (N > MAXIMUM_N)) ? 0 : N;

	// Print "N := {N}." to the command line terminal.
	std::cout << "\n\nN := " << N << ".";

	// Print "N := {N}." to the file output stream.
	file << "\n\nN := " << N << ".";

	// Print "memory_address_of(N) := {N}." to the command line terminal.
	std::cout << "\n\nmemory_address_of(N) := " << &N << ".";

	// Print "memory_address_of(N):= {N}." to the file output stream.
	file << "\n\nmemory_address_of(N) := " << &N << ".";

	// Print "e(N) := {e(N)}." to the command line terminal.
	std::cout << "\n\ne(N) := " << e(N) << ".";

	// Print "e(N) := {e(N)}." to the file output stream.
	file << "\n\ne(N) := " << e(N) << ".";

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