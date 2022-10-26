#include "Lex.h"
#include<string>
using namespace std;

void Lex::makeLink(int from, char input, int to)
{
	if (input == 0) //jump to "others"
	{
		nodes[from].nextIfOthers = to;
	}
	else
	{
		nodes[from].jump[input] = to;
	}
}

void Lex::setAccept(int node, bool accept)
{
	nodes[node].accept = accept;
}

int Lex::jump(int node, char input, bool& lookback)
{
	map<char, int>::iterator iter = nodes[node].jump.find(input);
	if (iter == nodes[node].jump.end())
	{
		lookback = true;
		return nodes[node].nextIfOthers;
	}
	else
	{
		lookback = false;
		return nodes[node].jump[input];
	}
}

vector<pair<string, double>> Lex::getTokens(string input)
{
	vector<pair<string, double>> tokens;
	errorFlag = false;
	int firstCharPos = 0;
	currentState = 0;
	for (int p = 0; p < input.length(); p++)
	{
		bool lookback;
		currentState = jump(currentState, input[p], lookback);
		if (lookback) p--;
		if (nodes[currentState].accept)
		{
			string numStr = input.substr(firstCharPos, p - firstCharPos + 1);
			switch (currentState)
			{
			case 5: //num
				tokens.push_back(make_pair("digits", atof(numStr.c_str())));
				break;
			case 44: //e
				tokens.push_back(make_pair("e", exp(1)));
				break;
			case 46: //pi
				tokens.push_back(make_pair("pi", acos(-1)));
				break;
			case 53: //error
				errorFlag = true;
				errorMsg = "Tokenization failed at position " + to_string(p);
				return tokens;
			default:
				tokens.push_back(make_pair(numStr, firstCharPos));
				break;
			}
			firstCharPos = p + 1;
		}
	}
	tokens.push_back(make_pair("$", firstCharPos));
	return tokens;
}
