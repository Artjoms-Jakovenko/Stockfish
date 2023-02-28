// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the STOCKFISHCLRWRAPPER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// STOCKFISHCLRWRAPPER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef STOCKFISHCLRWRAPPER_EXPORTS
#define STOCKFISHCLRWRAPPER_API __declspec(dllexport)
#else
#define STOCKFISHCLRWRAPPER_API __declspec(dllimport)
#endif

// This class is exported from the dll
class STOCKFISHCLRWRAPPER_API CStockfishCLRWrapper {
public:
	CStockfishCLRWrapper(void);
	// TODO: add your methods here.
};

extern STOCKFISHCLRWRAPPER_API int nStockfishCLRWrapper;

STOCKFISHCLRWRAPPER_API int fnStockfishCLRWrapper(void);
