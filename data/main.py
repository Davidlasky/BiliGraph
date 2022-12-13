import getAuthorInfo
import getVideoInfo
import asyncio
import pandas as pd
import numpy as np
import csv
import queue

def main():
    

    with open("test.csv", "w", newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['BVID', 'View', 'Like','Coin', "Authors"])

    with open("authorData.csv", "w", newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['UID', 'Nick Name', 'Average View','Average Like','Average Coin'])
    
    sources = []
    # authorreference = []
    videoreference = []
    
    with open("authors.csv", "r") as csvfile:
        reader = csv.reader(csvfile)
        for line in reader:
            sources.append(line[0])


    while len(sources) != 0:
        line = sources.pop()
        vList, nickname, stats = getAuthorInfo.getAuthorInfo(line)
        views = list()
        likes = list()
        coins = list()
        for each in vList:
            view, like, coin, authors = asyncio.get_event_loop().run_until_complete(getVideoInfo.getVideoInfo(each))
            views.append(view)
            likes.append(like)
            coins.append(coin)
            
            # if len(authors) != 0:
            #     for author in authors:
            #         if author not in authorreference:
            #             sources.append(author)
            #             authorreference.append(author)

            if each not in videoreference:
                videoreference.append(each)
                if len(authors) > 1:
                    with open("test.csv", "a", newline='') as csvfile:
                        writer = csv.writer(csvfile)
                        writer.writerow([each, view, like, coin, authors])
        

        with open("authorData.csv", "a", newline='') as csvfile:
                writer = csv.writer(csvfile)
                writer.writerow([line, nickname, np.mean(views), np.mean(likes), np.mean(coins)])
    
    # vInfo = pd.DataFrame({'BVID':vList, 'View':views, 'like':likes,
    # 'Coin':coins, "Authors":authorsL})
    # vInfo.to_csv("test.csv", index = False, sep = ',')

def authorFusion():
    sources = []
    authorreference = []

    with open("authors.csv", "r") as csvfile:
        reader = csv.reader(csvfile)
        for line in reader:
            sources.append(line[0])
            authorreference.append(line[0])



    while len(sources) != 0:
        line = sources.pop()
        vList, nickname, stats = getAuthorInfo.getAuthorInfo(line)
        if stats < 100000:
            continue
        with open("authors.csv", "a", newline='') as csvfile:
                            writer = csv.writer(csvfile)
                            writer.writerow([line])
        for each in vList:
            view, like, coin, authors = asyncio.get_event_loop().run_until_complete(getVideoInfo.getVideoInfo(each))
            print(authors, authorreference)
            if len(authors) != 0:
                for author in authors:
                    authorId = str(author)
                    if authorId not in authorreference:
                        sources.append(authorId)
                        authorreference.append(authorId)


if __name__ == '__main__':
    authorFusion()
    #main()
