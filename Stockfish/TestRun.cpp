#include "TestRun.h"

#include "../Stockfish/src/bitboard.h"
#include "../Stockfish/src/endgame.h"
#include "../Stockfish/src/psqt.h"
#include "../Stockfish/src/syzygy/tbprobe.h"
#include "../Stockfish/src/thread.h"
#include "../Stockfish/src/tt.h"
#include "../Stockfish/src/uci.h"

#include <iostream>

using namespace Stockfish;

int SimpleClass::AddNums(int a, int b) {

	std::cout << engine_info() << std::endl;

	int argc = 1;
	char* argv[] = { "C:\\Users\\artjo\\source\\repos\\Stockfish\\x64\\Release\\" };

	CommandLine::init(argc, argv);
	UCI::init(Options);
	Tune::init();
	PSQT::init();
	Bitboards::init();
	Position::init();
	Bitbases::init();
	Endgames::init();
	Threads.set(size_t(Options["Threads"]));
	Search::clear(); // After threads are up
	Eval::NNUE::init();

	UCI::loop(argc, argv);

	Threads.set(0);
	return a + b + 1;
}