using System;
using System.Runtime.InteropServices;// DllImport用

namespace ConsoleApp1
{
		delegate int Wrap( int num );
		class Program
		{
				[DllImport( "1_Cppcli32.dll", EntryPoint = "func" )]
				static extern void func( /*int num */);

				//[DllImport( @"1_Cppcli64.dll" )]
				//static extern int wrap_64( int num );

				static void Main( string[] args )
				{
						//Wrap wrap;
						//if( Environment.Is64BitProcess )
						//		wrap = wrap_64;
						//else
						//wrap = wrap_32;
						func();
						//Console.WriteLine( wrap_32( 100 ) );
				}
		}
}
