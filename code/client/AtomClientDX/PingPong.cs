namespace AtomClient {
	public class PingPong {
		int value_ = 0;

		public PingPong() {
		}

		public int Current {
			get { return value_; }
		}

		public int Other {
			get { return 1-value_; }
		}

		public void flip() {
			value_ = (value_ == 0) ? 1 : 0;
		}
	}
}
