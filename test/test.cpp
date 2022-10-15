#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string boolString(bool value) {
	return value ? "true" : "false";
}

struct Option {
		SCoordinates toBe;
		vector<vector<int>> field;
};

Option options[] = {
		{
				{3, 2},
				{
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 1, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0}
				}
		},
		{
				{0, 4},
				{
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{1, 0, 0, 0, 0}
				}
		},
		{
				{3, 0},
				{
						{0, 0, 0, 1, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0}
				}
		}
};

void printGreen(const string& test, const string& result) {
	cout << termcolor::green << "TEST " << test << " PASSED! RESULT: " << result << "" << endl;
}

void printRed(const string& test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << test << " FAILED! EXPECTED: " << expected << " INSTEAD OF " << result << "!" << endl;
}

void test() {
	cout << endl;

	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		SCoordinates result = matrix(option.field);

		string testStr = "{\n";

		for (int j = 0; j < option.field.size(); j++) {
			testStr += "  {";
			for (int k = 0; k < option.field[j].size(); k++) {
				testStr += to_string(option.field[j][k]);

				if (k != option.field[j].size() - 1) {
					testStr += ", ";
				}
			}
			testStr += "}\n";
		}

		testStr += "}";

		if (
			result.x == option.toBe.x &&
			result.y == option.toBe.y
		) {
			printGreen(testStr, to_string(result.x) + ", " + to_string(result.y));
		} else {
			printRed(testStr, to_string(option.toBe.x) + ", " + to_string(option.toBe.y), to_string(result.x) + ", " + to_string(result.y));
		}

		if (i < optionsLength - 1) {
			cout << endl;
		}
	}
}