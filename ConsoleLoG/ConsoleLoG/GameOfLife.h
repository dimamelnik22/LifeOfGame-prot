#pragma once
#include "Pattern.h"

#define countGenes 9

class GameOfLife
{
public:
	GameOfLife(const int, const int);
	~GameOfLife();

	bool CellStatusNextLoop(int, int) const;
	const bool* const* GetField() const;
	bool** GetFieldCopy() const;
	void GetFieldCopy(bool**) const;
	const boolXbool GetFieldVectors() const;
	void Loop();
	void Loop(const int);
	// void Show() const;
	void SetCell(int, int, bool);
	void InsertPattern(const int, const int, const Pattern&);
	void SetBirthGene(const std::vector<bool>&);
	void SetSurviveGene(const std::vector<bool>&);
	void SetImmortalWalls(bool);
private:
	bool** fieldCopy;
	bool** field;
	bool* birth;
	bool* survive;
	int fHeight;
	int fWidth;
	bool immortalWalls = false;
	bool isAlive(int, int) const;
	bool isWall(int, int) const;

};

