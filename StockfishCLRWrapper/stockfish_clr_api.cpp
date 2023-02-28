#include "pch.h"
#include "stockfish_clr_api.h"

#include "../Stockfish/TestRun.h"

#include <iostream>

StockfishClrApi::StockfishClrApi()
{
	this->stockfishInternalWrapper = StockfishInternalWrapper();
}

StockfishClrApi stockfishClrApi; // TODO check style guides

extern "C" __declspec(dllexport) void StockfishClrApi_Init()
{
	StockfishInternalWrapper testW = StockfishInternalWrapper();
	testW.init("test");
}