#pragma once
#include <map>
#include <iostream>

// IDs for all pieces
enum Piece_IDs
{
	EMPTY = -1,
	WHITE = 0,
	BLACK = 1,
	KING = 0,
	QUEEN = 2,
	BISHOP = 4,
	KNIGHT = 6,
	ROOK = 8,
	PAWN = 10
};

// map for converting chars to ids
const std::map<char, int> charIDs = {
	{ 'k', KING + BLACK },
	{ 'q', QUEEN + BLACK },
	{ 'b', BISHOP + BLACK },
	{ 'n', KNIGHT + BLACK },
	{ 'r', ROOK + BLACK },
	{ 'p', PAWN + BLACK },
	{ 'K', KING + WHITE },
	{ 'Q', QUEEN + WHITE },
	{ 'B', BISHOP + WHITE },
	{ 'N', KNIGHT + WHITE },
	{ 'R', ROOK + WHITE },
	{ 'P', PAWN + WHITE }
};

// map for converting chars to ids
const std::map<int, char> IDchars = {
	{ KING + BLACK, 'k' },
	{ QUEEN + BLACK, 'q' },
	{ BISHOP + BLACK, 'b' },
	{ KNIGHT + BLACK, 'n' },
	{ ROOK + BLACK, 'r' },
	{ PAWN + BLACK, 'p' },
	{ KING + WHITE, 'K' },
	{ QUEEN + WHITE, 'Q' },
	{ BISHOP + WHITE, 'B' },
	{ KNIGHT + WHITE, 'N' },
	{ ROOK + WHITE, 'R' },
	{ PAWN + WHITE, 'P' }
};

// map for converting piece ids to value
const std::map<int, int> pieceToValue = {
	{QUEEN, 900},
	{BISHOP, 330},
	{KNIGHT, 320},
	{ROOK, 500},
	{PAWN, 100},
	{KING, 0},
	{EMPTY, 0}
};

// class for functions regarding pieces
class Piece {
public:
	// convert a piece char to int
	static int charToInt(char c)
	{
		return charIDs.at(c);
	}

	// convert an int to piece char
	static char intToChar(int n)
	{
		return IDchars.at(n);
	}

	// return the color of piece
	static int colorOf(int piece)
	{
		return piece % 2;
	}

	// return the type (knight, pawn...) of piece
	static int typeOf(int piece)
	{
		return piece / 2 * 2;
	}

	// convert piece to value
	static int valueOf(int piece)
	{
		return pieceToValue.at(typeOf(piece));
	}
};