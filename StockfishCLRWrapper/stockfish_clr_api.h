#pragma once

#include <string>

#include "StockfishCLRWrapper.h"
#include "../Stockfish/stockfish_internal_wrapper.h"

class StockfishClrApi {
public:
	StockfishClrApi();
	StockfishInternalWrapper stockfishInternalWrapper; // TODO check style guides
private:
};

extern "C" __declspec(dllexport) void StockfishClrApi_Init();
