using System;

namespace AtomClient {
	public enum OutputVerbosity {
		None,
		Error,
		Info,
		All
	}

	public class Log {
		public static OutputVerbosity Verbosity {get;set;}=OutputVerbosity.All;

		public static void write( string message, OutputVerbosity verbosity ) {
			if( Verbosity == OutputVerbosity.None ) {
				return;
			}

			if( Verbosity == verbosity || Verbosity == OutputVerbosity.All ) {
				Console.WriteLine(message);
			}
		}
	}
}
