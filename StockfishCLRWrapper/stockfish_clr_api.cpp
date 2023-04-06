#include "pch.h"
#include "stockfish_clr_api.h"

#include <iostream>

StockfishClrApi::StockfishClrApi()
{
	this->stockfishInternalWrapper = StockfishInternalWrapper();
}

StockfishClrApi stockfishClrApi; // TODO check style guides

extern "C" __declspec(dllexport) void StockfishClrApi_Init()
{
	stockfishClrApi.stockfishInternalWrapper.init("test");
	//stockfishClrApi.stockfishInternalWrapper.FindBestMove();
}

extern "C" __declspec(dllexport) void StockfishClrApi_FindBestMove()
{
	stockfishClrApi.stockfishInternalWrapper.FindBestMove();
}

__declspec(dllexport) void StockfishClrApi_Subscribe_OnBestMove(Callback callback) {
	std::string str = "e2e4e66";
	stockfishClrApi.stockfishInternalWrapper.SubscribeOnBestMove(callback);
	//callback(str.c_str());
}