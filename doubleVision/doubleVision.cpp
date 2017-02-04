#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>

using namespace cv;

int main( int argc, const char** argv )
{
  VideoCapture capture0(0);
  VideoCapture capture1(1);

  Mat frame0;
  Mat frame1;

  //-- 2. Read the video stream
  if((!capture0.isOpened())||(!capture1.isOpened()))
  {
    printf("Capture failed to open\n");
    return -1;
  } else {
    while(true){
      capture0.grab();
      capture1.grab();
      capture0.retrieve(frame0);
      capture1.retrieve(frame1);
      //-- 3. Apply the classifier to the frame
      if((!frame0.empty())||(!frame0.empty())){
        //-- Show what you got
        imshow("Frame0", frame0);
        imshow("Frame1", frame1);
      } else {
        printf(" --(!) No captured frame -- Break!");
        break;
      }
      int c = waitKey(1);
      if((char)c == 'c') { break; }
    }
  }
  return 0;
}
