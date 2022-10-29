//
// file: eulers_number_approximation.cpp
// type: C++ (source file)
// date: 29_OCTOBER_2022
// author: Karlina Ray Beringer (@karbytes)
// license: PUBLIC_DOMAIN
// description: The command line application which is generated by the C++ source code in this file generates an approximation of the the mathematical constant named e (i.e. Euler’s Number).
//

/* preprocessing directives */
#include <iostream> // command line input and output
#include <fstream> // file input and output
#define MAXIMUM_N 1000 // constant which represents maximum N value

/* function prototypes */
int compute_factorial_of_N_using_iteration(int N);
long double e(int N, std::ostream & output);

/**
 * Compute N factorial using an iterative algorithm.
 * 
 * If N is a natural number, then N! is the product of exactly one instance 
 * of each unique natural number which is less than or equal to N. 
 * N! := N * (N - 1) * (N - 2) * (N - 3) * ... * 3 * 2 * 1. 
 * 
 * If N is zero, then N! is one.
 * 0! := 1.
 */
int compute_factorial_of_N_using_iteration(int N)
{
	// Declare an int type variable (i.e. a variable for storing integer values) named i. 
	// Set the intial value which is stored in i to zero.
	// Declare an int type variable (i.e. a variable for storing integer values) named F. 
	// Set the intial value which is stored in i to zero.
	int i = 0, F = 0; 

	// If N is larger than zero and if N is no larger than MAXIMUM_N, set i to N. 
	// Otherwise, set i to 0.
	i = ((N > 0) && (N <= MAXIMUM_N)) ? N : 0; 

	// If N is larger than zero, set F to N.
	// Otherwise, set F to 1.
	F = (N > 0) ? N : 1; 

	// While i is larger than zero:
	while (i > 0) 
	{
		// If i is larger than 1, multiply F by (i - 1).
		if (i > 1) F *= i - 1; 

		// Decrement i by 1.
		i -= 1; 
	}

	// Return the value stored in F (i.e. factorial N (i.e. N!)).
	return F;
}

/**
 * Generate an approximation of the the mathematical constant named e (i.e. Euler’s Number).
 * 
 * The value returned by this function is a floating-point number value.
 */
long double e(int N, std::ostream & output)
{
	// Declare a long double type variable (i.e. a variable for storing floating-point number values) named A. 
	// Set the intial value which is stored in A to zero.
	long double A = 0.0;

	// Declare an int type variable (i.e. a variable for storing integer values) named i. 
	// Set the intial value which is stored in i to zero.
	int i = 0;

	// Declare a pointer to an long double type variable named T.
	long double * T;

	// If N is smaller than zero or if N is larger than MAXIMUM_N, set N to one. 
	N = ((N < 0) || (N > MAXIMUM_N)) ? 1 : N;

	// Allocate N contiguous long double sized chunks of memory to an array for storing N floating-point values.
	// Store the memory address of the first element of that array in T.
	T = new long double [N];

	// Print "memory_address_of(T) := {memory_address_of(T)}." to the output stream.
	output << "\n\nmemory_address_of(T) := " << &T << ".\n";

	// Print "T := {T}." to the output stream.
	output << "\n\nT := " << T << ".\n";

	// For each integer value represented by i starting at 0 and ending at N in and in ascending order: 
	// print the memory address of the ith element of the long double type array represented by T to the output stream.
	for (i = 0; i < N; i += 1) 
	{
		// Print "T[{i}] := {memory_address_of(T[i])}." to the output stream.
		output << "\nT[" << i << "] := " << &T[i] << ".";
	}

	// Print a newline character to the output stream.
	output << '\n';

	// For each integer value represented by i starting at 0 and ending at N in and in ascending order:
	// set value of the ith element of the int type array represented by T to (N - i) and
	// print the data value which is stored in the ith element of the array to the output stream.
	for (i = 0; i < N; i += 1) 
	{
		// Store the result of the arithmetic expression (N - i) in T[i].
		T[i] = N - i;

		// Print "T[{i}] := {T[i]}." to the output stream.
		output << "\nT[" << i << "] := " << T[i] << " = N - " << i << " = " << N << " - " << i << ".";
	}

	// For each integer value represented by i starting at 0 and ending at N in and in ascending order:
	// set value of the ith element of the int type array represented by T to (N - i)! and
	// print the data value which is stored in the ith element of the array to the output stream.
	for (i = 0; i < N; i += 1) 
	{
		// Store (N - i)! in T[i].
		T[i] = compute_factorial_of_N_using_iteration(T[i]);

		// Print "T[{i}] := {T[i]}." to the output stream.
		output << "\nT[" << i << "] := " << T[i];
	}

	// De-allocate memory which was assigned to the array named T.
	delete [] T;

	// Return the value which is stored in A.
	return A;
}

/* program entry point */
int main()
{
	// Declare a file output stream object named file.
	std::ofstream file;

	// Declare an int type variable (i.e. a variable for storing integer values) named N. 
	// Set the intial value which is stored in N to one.
	int N = 1;

    // Set the number of digits of floating-point numbers which are printed to the command line terminal to 100 digits.
    std::cout.precision(100);

    // Set the number of digits of floating-point numbers which are printed to the file output stream to 100 digits.
    file.precision(100);

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

	// Print "Enter a natural number which is no larger than {MAXIMUM_N}: " to the command line terminal.
	std::cout << "\n\nEnter a natural number which is no larger than " << MAXIMUM_N << ": ";

	// Scan the command line terminal for the most recent keyboard input value.
	std::cin >> N;

	// Print "Enter a natural number which is no larger than {MAXIMUM_N}: " to the command line terminal.
	std::cout << "\n\nEnter a natural number which is no larger than " << MAXIMUM_N << ": ";

	// Print "Enter a natural number which is no larger than {MAXIMUM_N}: " to the file output stream.
	file << "\n\nEnter a natural number which is no larger than " << MAXIMUM_N << ": ";

	// Print {N} to the command line terminal.
	std::cout << N;

	// Print {N} to the file output stream.
	file << N;

	// If N is smaller than zero or if N is larger than MAXIMUM_N, set N to one.
	N = ((N < 0) || (N > MAXIMUM_N)) ? 1 : N;

	// Print "N := {N}." to the command line terminal.
	std::cout << "\n\nN := " << N << ".";

	// Print "N := {N}." to the file output stream.
	file << "\n\nN := " << N << ".";

	// Print "memory_address_of(N) := {memory_address_of(N)}." to the command line terminal.
	std::cout << "\n\nmemory_address_of(N) := " << &N << ".";

	// Print "memory_address_of(N):= {N}." to the file output stream.
	file << "\n\nmemory_address_of(N) := " << &N << ".";

	// Print "e(N) := {e(N)}." to the command line terminal.
	std::cout << "\n\ne(N) := " << e(N, std::cout) << ".";

	// Print "e(N) := {e(N)}." to the file output stream.
	file << "\n\ne(N) := " << e(N, file) << ".";

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