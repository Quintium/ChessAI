#pragma once
#include "Board.h"
#include "TranspositionTable.h"
#include "Openings.h"
#include "Evaluation.h"

// AI class
class AI
{
	// location of assets
	std::string assetsPath;

	// board variable
	Board* board = nullptr;

	// variables for time control
	std::chrono::time_point<std::chrono::system_clock> searchStart;
	bool searchAborted = false;

	// ai limits
	double timeLimit = 0;
	const double maxTimeLimit = 100;
	const double minTimeLimit = 0.01;
	const int depthLimit = 6;

	// saving best move and eval found
	Move bestMove = Move::getInvalidMove();
	int bestEval = LOWEST_SCORE;

	// total nodes searched for debugging
	int nodes = 0;

	// transposition table and openings variable
	TranspositionTable* tt;
	std::optional<Openings> openings;

	// evaluation class
	std::optional<Evaluation> evaluation;

	// functions for negamax algorithm
	int search(int alpha, int beta, int depth, int maxDepth);
	int quiescenceSearch(int alpha, int beta);

public:
	// constructor and best move function
	AI(Board* boardVar, std::string assetsPath);
	Move getBestMove(int timeLeft = -1, int increment = 0);
};