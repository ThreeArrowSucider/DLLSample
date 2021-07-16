using System;
using System.Runtime.InteropServices;// DllImport用

namespace ConsoleApp1
{
		delegate int Wrap( int num );
		delegate void Strout( string str );
		class Program
		{
				[DllImport( @"1_Cppcli32.dll", EntryPoint = "wrap" )]
				static extern int wrap_32( int num );

				[DllImport( @"1_Cppcli64.dll", EntryPoint = "wrap" )]
				static extern int wrap_64( int num );


				[DllImport( @"1_Cppcli32.dll", EntryPoint = "strout" )]
				static extern void strout_32( string str );

				[DllImport( @"1_Cppcli64.dll", EntryPoint = "strout" )]
				static extern void strout_64( string str );


				static void Main( string[] args )
				{
						Wrap wrap;
						if( Environment.Is64BitProcess )
								wrap = wrap_64;
						else
								wrap = wrap_32;

						Console.WriteLine( wrap( 4812 /* ｼｬｲﾆ‐ */) );


						Strout strout;
						if( Environment.Is64BitProcess )
								strout = strout_64;
						else
								strout = strout_32;

						strout( "ｼｬｲﾆｰ" );


						Console.WriteLine( "何かキーを入力してください" );
						Console.ReadKey();
				}
		}
}
