import asyncio
import json
from bilibili_api import video
import pandas as pd

async def getVideoInfo(vid):
    # 实例化 Video 类
    v = video.Video(bvid=vid)
    info =  await v.get_info()
    #print(info)
    authors = list()
    if 'staff' in info:
        authorInfo = info['staff']
        for each in authorInfo:
        #print(each['mid'])
            authors.append(each['mid'])
    else:
        authorInfo = info['owner']
        authors.append(authorInfo['mid'])
    statsInfo = info['stat']
    

    
    # print(statsInfo['view'])
    # print(statsInfo['favorite'])
    # print(statsInfo['coin'])
    return statsInfo['view'], statsInfo['like'], statsInfo['coin'], authors



    # 给视频点赞

# if __name__ == '__main__':
#     view, favorite, coin, authors = asyncio.get_event_loop().run_until_complete(getVideoInfo('BV1U4411F7Mn'))
#     print(view)
#     print(favorite)
#     print(coin)
#     print(authors)
#     vInfo = pd.DataFrame({})


