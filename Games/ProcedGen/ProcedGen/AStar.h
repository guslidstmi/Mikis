#pragma once
#include <vector>
#include "Tile.h"

class AStar
{
public:

	struct Node {
		int xPos;
		int yPos;
	};

	AStar();
	//std::vector<Node>& getPath(int xPosStart, int yPosStart, int xPosTarget, int yPosTarget, std::vector<Tile>& map);


private:

	int m_currPosX;
	int m_currPosY;
	int m_disTraveled;
	int m_priority;
	std::vector<Node> m_path;
};