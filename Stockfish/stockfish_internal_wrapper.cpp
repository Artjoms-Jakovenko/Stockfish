#include "stockfish_internal_wrapper.h"

#include "../Stockfish/src/bitboard.h"
#include "../Stockfish/src/endgame.h"
#include "../Stockfish/src/psqt.h"
#include "../Stockfish/src/syzygy/tbprobe.h"
#include "../Stockfish/src/thread.h"
#include "../Stockfish/src/tt.h"
#include "../Stockfish/src/uci.h"

#include "../Stockfish/src/search.cpp" /// TODO move it elsewhere

#include <iostream>

using namespace Stockfish;

void StockfishInternalWrapper::init(std::string pathToNeuralNetwork)
{
	std::cout << engine_info() << std::endl;

	int argc = 1;
	char* argv[] = { "C:\\Users\\artjo\\source\\repos\\Stockfish\\Stockfish\\x64\\Release\\" }; // TODO pass as a parameter

	CommandLine::init(argc, argv);
	UCI::init(Options);
	Tune::init();
	PSQT::init();
	Bitboards::init();
	Position::init();
	Bitbases::init();
	Endgames::init();
	//Threads.set(size_t(Options["Threads"]));
	//Search::clear(); // After threads are up
	Eval::NNUE::init();

	//UCI::loop(argc, argv);

	//Threads.set(0);
}

void StockfishInternalWrapper::SubscribeOnBestMove(Callback callback) {
	eventHandler.subscribe(callback);
}

void StockfishInternalWrapper::FindBestMove() {

	Threads.set(size_t(Options["Threads"]));
	Search::clear(); // After threads are up
	UCI::go_wrapper();
	Threads.set(0);
}