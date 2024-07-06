# import pyautogui


# pyautogui.moveTo(100,300,3)
# pyautogui.doubleClick()

import pyautogui
import time

# Example: Move to (100, 100) and click after a delay
pyautogui.moveTo(100, 100, duration=1.0)
print(f"Mouse position after moveTo: {pyautogui.position()}")  # Verify mouse position
time.sleep(1)  # Delay to observe the mouse movement
pyautogui.click()  # Perform a click
