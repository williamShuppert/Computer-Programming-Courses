
// Author:		William Shuppert
// Filename:	logtable.cpp
// Description:	create a table that shows the
//				values of log10, log2, and ln.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// function returns next step size
int s(int x) {
	return x + pow(10, floor(log10(x)));
}

int main() {

	// input variable
	int nrows;

	// get input variable
	cout << fixed << setprecision(8) << "Enter how many rows to calculate: "; cin >> nrows;

	// output table headers
	cout << setw(8) << "x" << setw(14) << "log10(x)" << setw(14) << "log2(x)" << setw(14) << "ln(x)" << endl;
	cout << setfill('-') << setw(8 + 14 * 3) << "" << setfill(' ') << endl;

	// output each row
	int i = 1;
	for (int row = 1; row <= nrows; row++) {
		cout << setw(8) << i << setw(14) << log10(i) << setw(14) << log2(i) << setw(14) << log(i) << endl;
		i = s(i);
	}

}
