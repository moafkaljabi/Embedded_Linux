import pyautogui
import time

print("Press Ctrl-C to quit.")
try:
    while True:
        # Get the current position of the mouse cursor
        x, y = pyautogui.position()

        # Print the current position
        print(f"Mouse position: ({x}, {y})", end="\r")

        # Add a short delay to avoid flooding the console with too many messages
        time.sleep(0.1)
except KeyboardInterrupt:
    print("\nDone.")

