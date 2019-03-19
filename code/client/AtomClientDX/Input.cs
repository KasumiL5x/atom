
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace AtomClient {
	public class Input {
		public enum MouseButton {
			Left,
			Middle,
			Right,
			X1,
			X2
		}

		KeyboardState prevKeyState_ = new KeyboardState();
		KeyboardState currKeyState_ = new KeyboardState();
		MouseState prevMouseState_ = new MouseState();
		MouseState currMouseState_ = new MouseState();

		public Input() {
		}

		public void preUpdate() {
			currKeyState_ = Keyboard.GetState();
			currMouseState_ = Mouse.GetState();
		}

		public void postUpdate() {
			prevKeyState_ = currKeyState_;
			prevMouseState_ = currMouseState_;
		}

		/**
		 * Gets if the specified key is currently down.
		 */
		public bool isKeyDown( Keys key ) {
			return currKeyState_.IsKeyDown(key);
		}

		/**
		 * Gets if the specified key is currently up.
		 */
		public bool isKeyUp( Keys key ) {
			return currKeyState_.IsKeyUp(key);
		}

		/**
		 * Gets if the specified key was previously down.
		 */
		public bool wasKeyDown( Keys key ) {
			return prevKeyState_.IsKeyDown(key);
		}

		/**
		 * Gets if the specified key was previously up.
		 */
		public bool wasKeyUp( Keys key ) {
			return prevKeyState_.IsKeyUp(key);
		}

		/**
		 * Synonym for isKeyDown.
		 */
		public bool keyPressed( Keys key ) {
			return isKeyDown(key);
		}

		/**
		 * Gets if a key was pressed this frame but previously released.  One time press until release.
		 */
		public bool keyTapped( Keys key ) {
			return isKeyDown(key) && wasKeyUp(key);
		}

		/**
		 * Gets if the specified mouse button is currently pressed.
		 */
		public bool isButtonDown( MouseButton button ) {
			return ButtonState.Pressed == toXnaButton(button, currMouseState_);
		}

		/**
		 * Gets if the specified mouse button is currently released.
		 */
		public bool isButtonUp( MouseButton button ) {
			return ButtonState.Released == toXnaButton(button, currMouseState_);
		}

		/**
		 * Gets if the specified mouse button was previously pressed.
		 */
		public bool wasButtonDown( MouseButton button ) {
			return ButtonState.Pressed == toXnaButton(button, prevMouseState_);
		}

		/**
		 * Gets if the specified mouse button was previously released.
		 */
		public bool wasButtonUp( MouseButton button ) {
			return ButtonState.Released == toXnaButton(button, prevMouseState_);
		}

		/**
		 * Synonym for isButtonDown.
		 */
		public bool buttonPressed( MouseButton button ) {
			return isButtonDown(button);
		}

		/**
		 * Gets if a button was pressed this frame but previously released.  One time press until release.
		 */
		public bool buttonTapped( MouseButton button ) {
			return isButtonDown(button) && wasButtonUp(button);
		}

		/**
		 * Gets the current mouse X coordinate.
		 */
		public int x() {
			return currMouseState_.X;
		}

		/**
		 * Gets the current mouse Y coordinate.
		 */
		public int y() {
			return currMouseState_.Y;
		}

		/**
		 * Gets the previous mouse X coordinate.
		 */
		public int prevX() {
			return prevMouseState_.X;
		}

		/**
		 * Gets the previous mouse Y coordinate.
		 */
		public int prevY() {
			return prevMouseState_.Y;
		}

		/**
		 * Gets the current mouse scroll value.
		 */
		public int scroll() {
			return currMouseState_.ScrollWheelValue;
		}

		/**
		 * Gets the previous mouse scroll value.
		 */
		public int prevScroll() {
			return prevMouseState_.ScrollWheelValue;
		}

		/**
		 * Gets the current mouse position.
		 */
		public Point position() {
			return currMouseState_.Position;
		}

		/**
		 * Gets the previous mouse position.
		 */
		public Point prevPosition() {
			return prevMouseState_.Position;
		}

		/**
		 * Gets the mouse X delta.
		 */
		public int deltaX() {
			return x() - prevX();
		}

		/**
		 * Gets the mouse Y delta. 
		 */
		public int deltaY() {
			return y() - prevY();
		}

		/**
		 * Gets the mouse scroll delta.
		 */
		public int deltaScroll() {
			return scroll() - prevScroll();
		}

		/**
		 * Gets the mouse position delta.
		 */
		public Point deltaPosition() {
			return position() - prevPosition();
		}

		private ButtonState toXnaButton( MouseButton button, MouseState state ) {
			switch( button ) {
				case MouseButton.Left: {
					return state.LeftButton;
				}
				case MouseButton.Middle: {
					return state.MiddleButton;
				}
				case MouseButton.Right: {
					return state.RightButton;
				}
				case MouseButton.X1: {
					return state.XButton1;
				}
				case MouseButton.X2: {
					return state.XButton2;
				}
			}
			return ButtonState.Released;
		}
	}
}
