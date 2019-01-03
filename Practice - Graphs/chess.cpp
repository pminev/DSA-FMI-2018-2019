#include <iostream>
#include <queue>

const int TABLE_SIDE = 8;
const int NUMBER_OF_HORSE_MOVES = 8;

const int dx[NUMBER_OF_HORSE_MOVES] = { -2, -1, 1, 2 , 2, 1, -1, -2 };
const int dy[NUMBER_OF_HORSE_MOVES] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool isInChessTable(int x, int y) {
	return x >= 0 && y >= 0 && x < TABLE_SIDE && y < TABLE_SIDE;
}

int bfs(const std::pair<int, int>& horsePosition, const std::pair<int, int>& destination)
{
	bool taken[TABLE_SIDE][TABLE_SIDE];
	memset(taken, 0, sizeof(taken));

	const std::pair<int, int> sentinelPosition(-1, -1);

	std::queue<std::pair<int, int> > queue;
	
	taken[horsePosition.first][horsePosition.second] = true;
	queue.push(horsePosition);

	int currentLevel = 0;
	queue.push(sentinelPosition);

	while (!queue.empty()) {
		const std::pair<int, int>& currentPosition = queue.front();
		queue.pop();

		if (currentPosition == sentinelPosition) {
			++currentLevel;
			if (!queue.empty())
				queue.push(sentinelPosition);
			continue;
		}

		if (currentPosition == destination) {
			return currentLevel;
		}

		taken[currentPosition.first][currentPosition.second] = true;

		for (int i = 0; i < NUMBER_OF_HORSE_MOVES; ++i) {
			const int newPositionX = currentPosition.first + dx[i];
			const int newPositionY = currentPosition.second + dy[i];
			if (isInChessTable(newPositionX, newPositionY) && taken[newPositionX][newPositionY] == false) {
				queue.push(std::pair<int, int>(newPositionX, newPositionY));
			}
		}
	}

	return -1;
}

int main()
{
	std::pair<int, int> horsePosition;
	std::pair<int, int> destination;
	std::cin >> horsePosition.first >> horsePosition.second;
	std::cin >> destination.first >> destination.second;

	const int minNumberOfMoves = bfs(horsePosition, destination);
	if (minNumberOfMoves == -1) {
		std::cout << "Something went wrong!" << std::endl;
	} else {
		std::cout << "Result: " << minNumberOfMoves << std::endl;
	}
	
	return 0;
}