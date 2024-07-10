'''

check if a letter is a vowel or not

'''

letter = input("Enter a letter to check if it is a Vowel or not: ")

def isAVowel(char):
    allVowels = ['a', 'e','i','o','u','A','E','I','O','U']
    if char in allVowels:
        return  True
    else:
        return False


isAVowel(letter)

if isAVowel(letter):
    print(f"Your letter '{letter}'is a vowel.")
else:
    print(f"Your letter '{letter}' is not a vowel.")