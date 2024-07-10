
my_numbers = [2,4,55,4,66,77,13,4]

def isFour(nums):
    numberOfFours = 0 
    for i in nums:
        if i == 4:
            numberOfFours = numberOfFours +1 
    return numberOfFours

print(isFour(my_numbers))