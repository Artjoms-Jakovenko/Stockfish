#include "pch.h"
#include "command_interpreter.h"
#include "../Stockfish/TestRun.h"

extern "C" __declspec(dllexport) int MyFunction(int a, int b)
{
    SimpleClass simpleClass;
    return simpleClass.AddNums(a, b);
}
