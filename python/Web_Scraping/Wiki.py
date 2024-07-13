from bs4 import BeautifulSoup
import requests

# URL of the Wikipedia page
url = "https://en.wikipedia.org/wiki/List_of_largest_companies_in_the_United_States_by_revenue"

# Fetch the page
try:
    page = requests.get(url)
    page.raise_for_status()  # Check if the request was successful
except requests.exceptions.RequestException as e:
    print(f"Error fetching the URL: {e}")
    exit(1)

# Parse the page content
soup = BeautifulSoup(page.text, 'html.parser')

# Find the first table in the page
# myTable = soup.find('table', class_ = "wikitable sortable jquery-tablesorter")
myTable = soup.findAll('th')
# Check if the table was found
if myTable:
    print(myTable)
else:
    print("Table not found")
