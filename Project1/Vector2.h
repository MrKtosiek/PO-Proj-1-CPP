#pragma once

struct Vector2
{
	int x, y;

	Vector2 GetNeighbor(int i)
	{
		if (i == 0) return { x, y + 1 };
		if (i == 1) return { x + 1, y };
		if (i == 2) return { x, y - 1 };
		if (i == 3) return { x - 1, y };

		return *this;
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
};
