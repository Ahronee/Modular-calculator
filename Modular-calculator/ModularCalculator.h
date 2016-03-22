#ifndef MODULARCALCULATOR_H
#define MODULARCALCULATOR_H

#include <string>
#include <vector>
#include <cmath>

using std::string;
using std::vector;

class CalculatorOperation {
public:
	virtual bool supportsOperation(string) = 0;
	virtual int requiredParameters() = 0;
	virtual double calcResult(double, vector<string>) = 0;
};

class Add : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "add" || s == "+"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr + stod(params.front()); }
};

class Sub : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "sub" || s == "-"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr - stod(params.front()); }
};

class Mult : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "mul" || s == "*"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr * stod(params.front()); }
};

class Div : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "div" || s == "/"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr / stod(params.front()); }
};

class Sqrt : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return s == "sqrt"; }
	int requiredParameters() { return 0; }
	double calcResult(double curr, vector<string> params) { return sqrt(curr); }
};

class Pow : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "pow" || s == "^"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return pow(curr, stod(params.front())); }
};

#endif