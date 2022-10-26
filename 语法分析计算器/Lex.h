#pragma once
#include<map>
#include<vector>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
struct stateNode
{
	bool accept;
	map<char, int> jump;
	int nextIfOthers;
};
class Lex
{
public:
	int currentState = 0;
	bool errorFlag = false;
	string errorMsg;
	stateNode nodes[60];
	void makeLink(int from, char input, int to);
	void setAccept(int node, bool accept);
	int jump(int node, char input, bool& lookback);
	vector<pair<string, double>> getTokens(string input);
};

