
# 1. Extension (20,310)
# 2. Search bar(127,144)
# 3. Clang extension(187,277)
# 4. install (626,252)


import pyautogui
import time



def installEx(x,y,t=0):
    
    time.sleep(2)
    pyautogui.moveTo(x,y)
    time.sleep(t)
    pyautogui.click()



# 1. Extension (20,310)
installEx(20,310,3)
# 2. Search bar(127,144)
installEx(127,144,3)
# 3. Clang extension(187,277)
installEx(187,277,3)
# 4. install (626,252)
installEx(626,252)
