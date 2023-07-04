from bs4 import BeautifulSoup
import requests

# 20030505 -> cs major code

# Opening the html file. If the file
# is present in different location,
# exact location need to be mentioned
testHTML = open("test.html", "r").read()
soup = BeautifulSoup(testHTML, "html.parser")

# This snippet is for printing the structure of the html file
# print(soup.prettify())

print(soup.css.select("td[aria-describedby=grd_ScheduleMain_SUBJ_KNM]"))
