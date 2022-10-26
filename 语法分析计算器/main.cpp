#include<iostream>
#include"analyzer.h"
int main()
{
	string input;
	analyzer _analyzer;
	while (1)
	{
		cout << "> ";
		cin >> input;
		double result = _analyzer.compute(input);
		if (_analyzer.errorFlag)
		{
			cout << _analyzer.errorMsg << endl;
		}
		else cout << result << endl;
	}
	return 0;
}