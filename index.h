#ifndef INC_01_HELLO_WORLD_INDEX_H
#define INC_01_HELLO_WORLD_INDEX_H

#include <iostream>
#include <string>
#include <vector>

struct SCoordinates {
		int x;
		int y;
};

SCoordinates matrix(std::vector<std::vector<int>> &field);

#endif //INC_01_HELLO_WORLD_INDEX_H
