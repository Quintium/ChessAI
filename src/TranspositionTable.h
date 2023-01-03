#pragma once

#include <cstddef>
#include <optional>
#include "Board.h"
#include "Score.h"

// different node types of entry
enum NodeType
{
	EXACT_NODE, // PV nodes
	UPPER_BOUND_NODE,
	LOWER_BOUND_NODE
};

// an entry into the transposition table
struct Entry
{
	// order of fields matters because of bit field functionality
	U64 key : 64; // 64 bit key
	int eval : 32; // normal integer
	unsigned int depth : 8; // 255 - max depth
	unsigned int from : 6; // 64 squares
	unsigned int to : 6; // 64 squares
	unsigned int promotion : 4; // 13 pieces, 1 gets added to piece so empty pieces are 0
	unsigned int nodeType : 2; // 3 node types
	unsigned int valid : 1; // boolean whether entry is valid or empty entry generated from the start (which would have valid set to zero because of zero-initialization)
};

// class for the transposition table
class TranspositionTable
{
	// maximum size of entry list and entry list
	int size = 5000000;
	std::vector<Entry> entries;

	// board variable
	Board& board;

public:
	// constructor and clear table
	TranspositionTable(Board& boardPar);
	void clear();

	// store an entry for current position
	void storeEntry(int eval, int depth, Move move, int nodeType, int numPly);

	// get stored move and eval for current board position
	std::optional<Move> getStoredMove(Board& board, bool exact);
	std::optional<int> getStoredEval(int depth, int numPly, int alpha, int beta);

	// get current index in table
	int getIndex();
};