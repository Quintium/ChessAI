#pragma once

#include <cstddef>
#include "Board.h"
#include "Score.h"

enum class NodeType
{
	EXACT,
	UPPER_BOUND,
	LOWER_BOUND
};

struct Entry
{
	int eval;
	int depth;
	Move move;
	NodeType nodeType;
	U64 key;
};

class TranspositionTable
{
	int size = 100000;
	Board* board = nullptr;
	std::vector<Entry> entries;
	bool failed = false;

public:
	TranspositionTable(Board* boardVar);
	void clear();
	Move getStoredMove();
	int getStoredEval(int depth, int numPly, int alpha, int beta);
	void storeEntry(int eval, int depth, Move move, NodeType nodeType, int numPly);
	int getIndex();

	bool didSearchFail();
};