# # https://api.ipify.org/?format=json
# # https://ipinfo.io/<YOUR_IP>/geo

# import subprocess

# def get_ip_address_ifconfig():
#     result = subprocess.run(['ifconfig'], capture_output=True, text=True)
#     ifconfig_output = result.stdout

#     # Parse the output for the IP address (assuming eth0 as the interface)
#     import re
#     ip_match = re.search(r'inet (\d+\.\d+\.\d+\.\d+)', ifconfig_output)
#     if ip_match:
#         return ip_match.group(1)
#     else:
#         return "Could not retrieve IP address"

# # Call the function and print the result
# ip_address = get_ip_address_ifconfig()
# print("Your IP address is:", ip_address)




# 1. Import requests.
# 2. define the function. 
#       - make the get request 
#       - check for response 
#       - create variable to store the data
#       - return the data
# 3. define variable to equal the function. 
# 4. print the variable.


import requests 

def get_info():
    response = requests.get('https://ipinfo.io/json')
    if response.status_code == 200:
       data = response.json()
       return data
    else: 
     return "Could not retreive data."
    
myInfo = get_info()

print (myInfo)