from bs4 import BeautifulSoup
import requests
import pandas as pd
from datetime import datetime
import os
import time

def automated_bitcoin_pull():
    
    url = 'https://coinmarketcap.com/currencies/bitcoin/'

    page = requests.get(url)

    soup = BeautifulSoup(page.text, features='lxml')

    # Title (Bitcoin price)
    crypto_name = soup.find('span', class_ = 'sc-f70bb44c-0 jltoa').text
    fixed_crypto_name = crypto_name.replace(' price', '')
    # Current bitcoin price
    crypto_price = soup.find('span', class_ = 'sc-f70bb44c-0 jxpCgO base-text').text
    price_without_dollarSign = crypto_price.replace('$','') 
    # Current date and time
    date_time = datetime.now() 
    # Dict to store the scrapped data
    dict = {'Crypto Name': fixed_crypto_name,
             'Price': price_without_dollarSign,
               'TimeStamp': date_time}
    # Data frame
    data_frame = pd.DataFrame([dict])

    if os.path.exists(r'/Users/amit/Desktop/Crypto Web Puller/Crypto_Automated_Pull.csv'):
        data_frame.to_csv(r'/Users/amit/Desktop/Crypto Web Puller/Crypto_Automated_Pull.csv', mode = 'a', header = False, index = False)
    else:
        data_frame.to_csv(r'/Users/amit/Desktop/Crypto Web Puller/Crypto_Automated_Pull.csv', index = False)
    
    print(data_frame)
    
while True:
    automated_bitcoin_pull()
    # Scrape the price every 60 minutes
    time.sleep(3600)
