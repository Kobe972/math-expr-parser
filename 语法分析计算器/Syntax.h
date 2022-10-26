#pragma once
#include<string>
#include<vector>
using namespace std;
struct ErrorMsg
{
	bool flag;
	string info;
};
class Syntax
{
private:
	int currentPos;
	vector<pair<string, double>> tokens;
	double E();
	double F();
	double T();
	double M();
	double (*func())(double);
	double Num();
	double match(string token);
	string lookahead();
public:
	ErrorMsg errorMsg;
	double compute(vector<pair<string, double>> _tokens);
};

