'''

our desired output:

        2014 Feb 22 

Mon Teu Wed thu Fri Sat Sun
 1   2   3   4   5   6   7
 8   9   10  11  12  13  14
'''


import calendar

year = int(input("Enter year: "))
month = int(input("Enter a month: "))

date = calendar.month(year,month)

print(date)