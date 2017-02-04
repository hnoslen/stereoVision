import numpy as np
import cv2
from matplotlib import pyplot as plt

cam0 = cv2.VideoCapture(1)
cam1 = cv2.VideoCapture(0)

plt.show()

while True:
    s0, im0 = cam0.read() # captures image
    s1, im1 = cam1.read()

    gray_image0 = cv2.cvtColor(im0, cv2.COLOR_BGR2GRAY)
    gray_image1 = cv2.cvtColor(im1, cv2.COLOR_BGR2GRAY)

    stereo = cv2.StereoBM_create(numDisparities=16, blockSize=15)
    disparity = stereo.compute(gray_image0,gray_image1)
    plt.imshow(disparity,'gray')
    plt.draw()
    plt.pause(0.001)
