from bilibili_api import user, sync



def getAuthorInfo(uid):
    data = list()
    u = user.User(uid)
    vList = sync(u.get_videos(ps = 50))['list']['vlist']
    name = (sync(u.get_user_info())['name'])

    for each in vList:
        data.append(each['bvid'])
    return data, name

# print(sync(u.get_videos(ps = 3))['list']['vlist'])
if __name__ == '__main__':
    vList = getAuthorInfo(476704454)
    print(vList)