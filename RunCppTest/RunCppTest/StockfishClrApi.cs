using System.Runtime.InteropServices;

namespace RunCppTest
{
	public static class StockfishClrApi
	{
		//public StockfishClrApi() 
		//{
		//	StockfishClrApi_Init("test");
		//}
		[DllImport("StockfishCLRWrapper.dll")]
		public static extern void StockfishClrApi_Init();

		[DllImport("StockfishCLRWrapper.dll")]
		public static extern void StockfishClrApi_FindBestMove();

		[UnmanagedFunctionPointer(CallingConvention.StdCall, CharSet = CharSet.Ansi)]
		public delegate void StringCallback(string str);

		[DllImport("StockfishCLRWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void StockfishClrApi_Subscribe_OnBestMove(IntPtr callbackPtr);

		public static void runT()
		{
			StockfishClrApi_Init();
		
			//Action<string> action = (str) => {
			//	Console.WriteLine("HAHAHAHAHHAHAHAHA");
			//	Console.WriteLine(str);
			//};

			//StringCallback callback = new StringCallback(action.Invoke);
			//IntPtr callbackPtr = Marshal.GetFunctionPointerForDelegate(callback);

			//StockfishClrApi_Subscribe_OnBestMove(callbackPtr);

			//StockfishClrApi_FindBestMove();
			//StockfishClrApi_GetBestMove("sausage");
			//StockfishClrApi_Init();
		}

		public static string BestMove = "TESTNG";

		public async static Task<string> GetBestMove() 
		{
			Action<string> action = (str) => {
				Console.WriteLine("HAHAHAHAHHAHAHAHA");
				Console.WriteLine(str);
				BestMove = str;
			};

			StringCallback callback = new StringCallback(action.Invoke);
			IntPtr callbackPtr = Marshal.GetFunctionPointerForDelegate(callback);
			StockfishClrApi_Subscribe_OnBestMove(callbackPtr);

			StockfishClrApi_FindBestMove();

			await Task.Delay(1000);
			return BestMove;
		}

		//public static int Test(int a) 
		//{
		//	return a+2;
		//}
	}
}
