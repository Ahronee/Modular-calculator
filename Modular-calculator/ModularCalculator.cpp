#include "ModularCalculator.h"

using std::cout;
using std::endl;

int main() {
	
	string op;
	Calculator calculator;
	cout << "Welcome to the modular calculator." << endl;
	while (!cin.eof()) {
		cin >> op;
		try {
			cout << "Current value is: " << calculator.calculate(op) << endl;
		}
		catch (char const* error) {
			cout << error << " Please try again." << endl;
		}
	}

	return 0;
}