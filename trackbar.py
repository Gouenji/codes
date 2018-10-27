import cv2
import numpy as np


def nothing(*arg):
 TrackbarPos = cv2.getTrackbarPos(TrackbarName, WindowName)
 print TrackbarPos


'''
def SimpleTrackbar(Image, WindowName):

 TrackbarName = WindowName + "Trackbar"


 cv2.namedWindow(WindowName)
 cv2.createTrackbar(TrackbarName, WindowName, 0, 255, nothing)
 cv2.createTrackbar(TrackbarName+"dd", WindowName, 0, 255, nothing)

 Threshold = np.zeros(Image.shape, np.uint8)

 while True:
  TrackbarPos = cv2.getTrackbarPos(TrackbarName, WindowName)
  TrackbarPos2 = cv2.getTrackbarPos(TrackbarName+"dd", WindowName)
  print TrackbarPos,TrackbarPos2
  cv2.threshold(Image, TrackbarPos, 255, cv2.THRESH_BINARY, Threshold)
  cv2.threshold(Image, TrackbarPos2, 255, cv2.THRESH_BINARY, Threshold)
  cv2.imshow(WindowName, Threshold)
  ch = cv2.waitKey(5)
  if ch == 27:
      break

 cv2.destroyAllWindows()
 return Threshold
'''
WindowName='jki'
TrackbarName="ghh"
cv2.namedWindow(WindowName)
cv2.createTrackbar(TrackbarName, WindowName, 0, 255, nothing)

cap=cv2.VideoCapture('conq2.webm')
while(9):
    _,img=cap.read()
    cv2.imshow(WindowName,img)
    if cv2.waitKey(1) & 0xFF == 27:
        break


