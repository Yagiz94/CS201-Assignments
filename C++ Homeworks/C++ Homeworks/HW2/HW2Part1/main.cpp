#include <iostream>
#include "ctime"    //include ctime header file
#include <fstream>  // library that contains file input/output functions
using namespace std;
int fib(int n){
	// Precondition: n is a positive integer
	// Postcondition: Returns the nth Fib. number
	if ( n <= 2 )
		return 1;
	else
		return fib(n-1) + fib(n-2);
}   //Recursive Fibonacci Function
int main()
{
	double *arr4 = new double [50];
	int i;
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    ofstream fout("test4.txt"); //opening an output stream for file test.txt
    for(int i = 1; i <= 50; i++){
        //Code block...
        cout << "Fibonacci for " << i << " is: "<<endl;
        cout<<fib(i)<<endl;
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        arr4[i] = duration;
        cout << "Execution took " << duration << " milliseconds." << endl;
        cout<<endl;
        //Write the data into a text file
        if(fout.is_open())
        {
        //file opened successfully so we are here
            cout << "File Opened successfully!!!. Writing data from array to file" << endl;
            fout << arr4[i]<<endl; //writing ith character of arr4ay in the file
            cout << "array data successfully saved into the file test.txt" << endl;
        }
        else{//file could not be opened
            cout << "File could not be opened." << endl;
        }
	/*checking whether file could be opened or not. If file does not exist or don't have write permissions, file
    stream could not be opened.*/
    }
    return 0;
}

