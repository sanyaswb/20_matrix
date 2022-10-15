#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "index.h"

SCoordinates matrix(std::vector<std::vector<int>> &field) {
	SCoordinates res = {
			0,
			0
	};

	bool breaking = false;

	for (int i = 0; i < field.size(); i++) {
		if (breaking) {
			break;
		}

		auto row = field[i];

		for (int j = 0; j < row.size(); j++) {
			auto cell = row[j];

			if (cell == 1) {
				res.x = j;
				res.y = i;
				breaking = true;
				break;
			}
		}
	}

	return res;
}
