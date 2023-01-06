#pragma once

#include <optional>
#include <cmath>
#include <unordered_map>
#include "Board.h"
#include "TranspositionTable.h"
#include "PieceSquareTables.h"


class Evaluation
{
	// Parameters passed to engine
	std::unordered_map<std::string, double>& params;

	// Board variable
	Board& board;

	// transposition table
	TranspositionTable& tt;

	// values of pieces
	std::map<int, int> pieceValues;

	// values for squares of pieces
	PieceSquareTables pieceSquareTables;

	// pawn shield bitboards for each color and wing
	std::array<std::array<U64, 2>, 2> pawnShieldBBs;
	std::array<U64, 64> nearKingSquares;

	// bitboards for files
	std::array<U64, 8> fileBBs;

	// array of all ray directions
	std::array<int, 16> dirs = { EAST,       WEST,       NORTH,      SOUTH,
								 NORTH_EAST, SOUTH_WEST, SOUTH_EAST, NORTH_WEST };

public:
	// constructor for class
	Evaluation(Board& boardPar, TranspositionTable& ttPar, std::unordered_map<std::string, double>& paramsPar);

	// update parameters
	void updateParams();

	// move ordering function
	void orderMoves(std::vector<Move>& moves);

	// evaluation helper functions
	std::array<int, 2> countMaterial(std::array<PieceList, 12>& pieceLists);
	double getOpeningWeight();
	double getEndgameWeight(std::array<int, 2> material);

	// part evaluation functions
	int countPieceSquareEval(std::array<PieceList, 12>& pieceLists, int color, double endgameWeight);
	int countMopUpEval(std::array<PieceList, 12>& pieceLists, int materialEval, double endgameWeight);
	int countKnightPawnPenalty(std::array<PieceList, 12>& pieceLists, int color);
	int countBadBishopPenalty(std::array<PieceList, 12>& pieceLists, std::array<U64, 12>& piecesBB, int color);
	int countBishopPairReward(std::array<PieceList, 12>& pieceLists, int color);
	int countRookOpenFileReward(std::array<U64, 12>& piecesBB, int color);
	int countDoubledPawnPenalty(std::array<U64, 12>& piecesBB, int color);
	int countIsolatedPawnPenalty(std::array<U64, 12>& piecesBB, int color);
	int countPassedPawnReward(std::array<U64, 12>& piecesBB, int color);
	int countBackwardPawnPenalty(std::array<U64, 12>& piecesBB, int color);
	int countPawnShieldEval(std::array<PieceList, 12>& pieceLists, std::array<U64, 12>& piecesBB, int color, double openingWeight, double endgameWeight);
	int countPawnStormEval(std::array<PieceList, 12>& pieceLists, std::array<U64, 12>& piecesBB, int color, double endgameWeight);

	// main evaluation function
	int evaluate();
};