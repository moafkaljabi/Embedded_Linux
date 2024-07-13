# 1. Extension (20,310)
# 2. Search bar(127,144)
# 3. Clang extension(187,277)
# 4. install (626,252)

# image name: VSCodeExtensionSearchBar.png
# Path: /home/moafk/Documents/Embedded_Linux/python/pyautogui/images/VSCodeExtensionSearchBar.png
# Relative path: python/pyautogui/images/VSCodeExtensionSearchBar.png
import pyautogui
import time

img_path = '/home/moafk/Documents/Embedded_Linux/python/pyautogui/images/VSCodeExtensionSearchBar.png'

def installEx(x,y,t=0):
    
    time.sleep(2)
    pyautogui.moveTo(x,y)
    time.sleep(t)
    pyautogui.click()



installEx(20,310,2)

location = pyautogui.locateOnScreen(img_path)

center_x, center_y = pyautogui.center(location)

pyautogui.click(center_x,center_y)

time.sleep(3)

pyautogui.write("clang")


# 3. Clang extension(187,277)
installEx(187,277)