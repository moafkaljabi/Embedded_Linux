
import pyautogui
import time

# Give you some time to switch to the correct window
time.sleep(3)

# Move the mouse to the position where the text editor icon is and click it
# Note: Adjust the coordinates (x, y) to match the position on your screen
pyautogui.moveTo(100, 200, duration=1)  # Move to (100, 200) over 1 second
pyautogui.click()

# Wait for the text editor to open
time.sleep(2)

# Type some text
pyautogui.typewrite("Hello, World!", interval=0.1)  # Type with a short interval between each character

# Press 'Enter' key
pyautogui.press('enter')

# Type more text
pyautogui.typewrite("This is an automated message.", interval=0.1)

# Save the file using 'Ctrl+S' shortcut
pyautogui.hotkey('ctrl', 's')

# Wait a bit
time.sleep(1)

# Type the filename
pyautogui.typewrite("automated_message.txt", interval=0.1)

# Press 'Enter' to save
pyautogui.press('enter')
