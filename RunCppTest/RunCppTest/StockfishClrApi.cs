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

		public static void runT()
		{
			StockfishClrApi_Init();
		}
	}
}
