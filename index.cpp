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

	bool completed = false;

	for (int i = 0; i < field.size(); i++) {
		if (completed) {
			break;
		}
		for (int j = 0; j < field[i].size(); j++) {
			if (field[i][j] == 1) {
				res.x = j;
				res.y = i;
				completed = true;
				break;
			}
		}

	}

	return res;
}