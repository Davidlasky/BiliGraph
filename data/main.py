import getAuthorInfo
import getVideoInfo
import asyncio
import pandas as pd
import numpy as np
import csv

def main():
    views = list()
    likes = list()
    coins = list()
    authorsL = list()

    with open("test.csv", "w", newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['BVID', 'View', 'Like','Coin', "Authors"])

    with open("authorData.csv", "w", newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['UID', 'Nick Name', 'Average View','Average Like','Average Coin'])
    
    sources = list()
    with open("authors.csv", "r") as csvfile:
        reader = csv.reader(csvfile)
        for line in reader:
            sources.append(line)


    for line in sources:
        vList, nickname = getAuthorInfo.getAuthorInfo(line)
        for each in vList:
            view, like, coin, authors = asyncio.get_event_loop().run_until_complete(getVideoInfo.getVideoInfo(each))
            views.append(view)
            likes.append(like)
            coins.append(coin)
            authorsL.append(authors)
            if authors.len() != 0:
                for each in authors:
                    if each not in authorsL :
                        authorsL.append(each)
            with open("test.csv", "a", newline='') as csvfile:
                writer = csv.writer(csvfile)
                writer.writerow([each, view, like, coin, authors])
        
        
        with open("authorData.csv", "a", newline='') as csvfile:
                writer = csv.writer(csvfile)
                writer.writerow([line[0], nickname, np.mean(views), np.mean(likes), np.mean(coins)])
    
    # vInfo = pd.DataFrame({'BVID':vList, 'View':views, 'like':likes,
    # 'Coin':coins, "Authors":authorsL})
    # vInfo.to_csv("test.csv", index = False, sep = ',')

    

if __name__ == '__main__':
    main()
