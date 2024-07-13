import time
import pyautogui

def open_vscode():
    # Open Visual Studio Code
    pyautogui.press('winleft')
    pyautogui.write('Visual Studio Code')
    pyautogui.press('enter')

def install_clang_extension():
    time.sleep(5)  # Wait for VS Code to open

    # Open extensions view
    pyautogui.hotkey('ctrl', 'shift', 'x')

    time.sleep(2)  # Wait for the extensions view to open

    # Search for Clang extension
    pyautogui.write('C/C++')
    pyautogui.press('enter')

    time.sleep(2)  # Wait for the search results to appear

    # Select the C/C++ extension from Microsoft
    pyautogui.press('tab', presses=3, interval=0.2)  # Adjust based on your VS Code theme and layout
    pyautogui.press('enter')

    time.sleep(2)  # Wait for the extension page to open

    # Install the extension
    pyautogui.press('tab', presses=5, interval=0.2)  # Adjust based on your VS Code theme and layout
    pyautogui.press('enter')

if __name__ == "__main__":
    open_vscode()
    install_clang_extension()

                    