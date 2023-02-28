#include "pch.h"
#include "framework.h"
#include "StockfishCLRWrapper.h"


// This is an example of an exported variable
STOCKFISHCLRWRAPPER_API int nStockfishCLRWrapper=0;

// This is an example of an exported function.
STOCKFISHCLRWRAPPER_API int fnStockfishCLRWrapper(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CStockfishCLRWrapper::CStockfishCLRWrapper()
{
    return;
}
