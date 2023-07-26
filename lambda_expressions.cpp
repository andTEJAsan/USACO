// C++ program to illustrate the above
// concept
#include <iostream>
using namespace std;

// Driver Code
int main()
{
	int x = 0, a = 5, b = 4;

	// In the below lambda expression,
	// everything is captured by value,
	// and only x by reference
	main()::<lambda()> fun = [=, &x]() {

		// If one tries to manipulate
		// the value of a read only
		// variable, then it causes
		// a compilation error.
		x++;

		// c is a new variable under
		// the fun expression which
		// sums up a and b
		int c = a + b;

		cout << "sum of the read only "
			<< "variables is : " << c
			<< "\n";

		return x;
	};

	cout << "The value of x is " << fun();

	return 0;
}
