import pyautogui
import time

# Wait for a few seconds to allow you to switch to the correct window
time.sleep(3)

# Coordinates of the Extensions tab (adjust according to your screen resolution)
extensions_tab_x = 14
extensions_tab_y = 303

# Move to the Extensions tab and click
pyautogui.moveTo(extensions_tab_x, extensions_tab_y, duration=1)
pyautogui.click()

# Give a small delay to ensure the click is registered
time.sleep(1)

# Locate the search bar on the screen using the screenshot
search_bar_location = pyautogui.locateOnScreen('VSCodeExtensionSearchBar.png')

if search_bar_location is not None:
    # Move the mouse to the search bar location
    pyautogui.moveTo(search_bar_location, duration=1)
    
    # Click on the search bar
    pyautogui.click()
    
    # Give a small delay to ensure the click is registered
    time.sleep(1)
    
    # Type the name of the extension
    pyautogui.typewrite('clang', interval=0.1)
    
    # Press 'Enter' to search for the extension
    pyautogui.press('enter')
    
    # Wait for search results to load
    time.sleep(2)
    
    # Optionally, click on the first search result to install
    # You may need to adjust the coordinates if the location of the search result varies
    first_result_location = pyautogui.locateOnScreen('first_result.png')
    if first_result_location is not None:
        pyautogui.moveTo(first_result_location, duration=1)
        pyautogui.click()
        time.sleep(1)
        
        # Locate and click the install button
        install_button_location = pyautogui.locateOnScreen('install_button.png')
        if install_button_location is not None:
            pyautogui.moveTo(install_button_location, duration=1)
            pyautogui.click()
        else:
            print("Could not find the install button.")
    else:
        print("Could not find the first search result.")
else:
    print("Could not find the search bar.")
