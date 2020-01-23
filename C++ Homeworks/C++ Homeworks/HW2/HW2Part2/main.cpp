#include <iostream>
#include <fstream>  // library that contains file input/output functions
#include "ctime"

using namespace std;
int iterativeFib(int n){
                            // Initialize base cases:
	int previous = 1; 		// initially fib(1)
	int current = 1;  		// initially fib(2)
	int next = 1;     		// result when n is 1 or 2

    // compute next Fibonacci values when n >= 3
	for (int i = 3; i <= n; ++i){
                            // current is fib(i-1)
                            // previous is fib(i-2)
		next = current + previous; // fib(i)

		previous = current; // get ready for the
		current = next;		// next iteration
	}
	return next;
}
int main(){
	double *arr = new double [400000];
	int n;
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    ofstream fout("test.txt"); //opening an output stream for file test.txt
    for(n = 1; n <= 400000; n++){
        //Code block...
        cout << "Fibonacci for " << n << " is: "<<endl;
        cout<<iterativeFib(n)<<endl;

        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        arr[n] = duration;
        cout << "Execution took " << duration << " milliseconds." << endl;
        cout<<endl;
        //Write the data into a text file
        if(fout.is_open())
        {
        //file opened successfully so we are here
            cout << "File Opened successfully!!!. Writing data from array to file" << endl;
            fout << arr[n]<<endl; //writing ith character of array in the file
            cout << "Array data successfully saved into the file test.txt" << endl;
        }
        else{//file could not be opened
            cout << "File could not be opened." << endl;
        }
    }
	/*checking whether file could be opened or not. If file does not exist or don't have write permissions, file
    stream could not be opened.*/
    return 0;
    }
