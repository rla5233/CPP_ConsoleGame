#pragma once

// 설명 : 좌표 클래스
class Point
{
public:
	static const Point Left;
	static const Point Right;
	static const Point Up;
	static const Point Down;
	static const Point Zero;

public:
	int X = 0;
	int Y = 0;

	void operator=(const Point& _Other)
	{
		X = _Other.X;
		Y = _Other.Y;
	}

	bool operator==(const Point& _Other)
	{
		return X == _Other.X && Y == _Other.Y;
	}
	
	bool operator!=(const Point& _Other)
	{
		return X != _Other.X || Y == _Other.Y;
	}

	void operator+=(const Point& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
	}
	
};

