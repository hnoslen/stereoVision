from os import listdir as listdir
f = open("stereo_calib.xml","w")
path = "../calibImgs/"

head ="""<?xml version="1.0"?>
<opencv_storage>
<imagelist>
"""
ending = """
</imagelist>
</opencv_storage>
"""
filelist = listdir(path)
filelist.sort()
for i in range(len(filelist)):
	filelist[i] = '"'+path+filelist[i]+'"'
body = chr(10).join(filelist)
f.write(head+body+ending)
f.close()
