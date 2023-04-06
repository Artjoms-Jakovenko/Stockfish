#pragma once

#include <string>

typedef void(__stdcall* Callback)(const char*);

class StockfishInternalWrapper {
public:
	void init(std::string pathToNeuralNetwork);
	static void SubscribeOnBestMove(Callback callback);
	static void FindBestMove();
	//static void OnTest(const std::string& bestMove);
};