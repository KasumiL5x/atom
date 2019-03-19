using Microsoft.Xna.Framework;

namespace AtomClient {
	public class ProtoHelper {
		public static Matrix matrixFromProto( Atom.Proto.Matrix atomMatrix ) {
			Matrix ret = new Matrix();
			for( int j = 0; j < 4; ++j ) {
				for( int i = 0; i < 4; ++i ) {
					int idx = j * 4 + i;
					ret[idx] = atomMatrix.M[idx];
				}
			}
			return ret;
		}
	}
}
