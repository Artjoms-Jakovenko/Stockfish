using System.Runtime.InteropServices;

namespace RunCppTest
{
	public static class Adderoo
	{
		[DllImport("StockfishCLRWrapper.dll")]
		public static extern int MyFunction(int a, int b);

		public static int AddNumbers(int a, int b)
		{
			return MyFunction(a, b);
		}
	}
}