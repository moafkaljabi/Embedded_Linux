from bs4 import BeautifulSoup

with open('index.html','r') as myFile:
    content = myFile.read()
    soup = BeautifulSoup(content, 'lxml')
    print(soup.prettify())