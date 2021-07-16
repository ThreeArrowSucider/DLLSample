using System;
using System.Runtime.InteropServices;// DllImport用

namespace ConsoleApp1
{
		delegate int Wrap( int num );
		class Program
		{
				[DllImport( @"1_Cppcli32.dll", EntryPoint = "wrap" )]
				static extern int wrap_32( int num );

				[DllImport( @"1_Cppcli64.dll", EntryPoint = "wrap" )]
				static extern int wrap_64( int num );

				static void Main( string[] args )
				{
						Wrap wrap;
						if( Environment.Is64BitProcess )
								wrap = wrap_64;
						else
								wrap = wrap_32;

						Console.WriteLine( wrap( 4812 /* ｼｬｲﾆ‐☆彡 */) );
				}
		}
}
