#pragma once

// Ό³Έν :
class Tile
{
public:
	// constructor destructor
	Tile();
	~Tile();
	
	// delete Function
	Tile(const Tile& _Other) = delete;
	Tile(Tile&& _Other) noexcept = delete;
	Tile& operator=(const Tile& _Other) = delete;
	Tile& operator=(Tile&& _Other) noexcept = delete;


protected:

private:

};

