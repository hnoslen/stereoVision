#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main( int argc, const char** argv )
{
  VideoCapture capture0(0);
  VideoCapture capture1(1);

  Mat frame0;
  Mat frame1;
  Mat gray_image0;
  Mat gray_image1;
  int captureIndex = 0;
  bool result0;
  bool result1;

  //-- 2. Read the video stream
  if((!capture0.isOpened())||(!capture1.isOpened()))
  {
    printf("Capture failed to open\n");
    return -1;
  } else {
    while(true){
      //capture0 >> frame0;
      //capture1 >> frame1;
      // Grabbing and retriving makes timing closer together
      capture0.grab();
      capture1.grab();
      //-- 3. Apply the classifier to the frame
      result0 = capture0.retrieve(frame0);
      result1 = capture1.retrieve(frame1);
      if((!frame0.empty())||(!frame1.empty())){
        //-- Show what you got
        imshow("Frame0", frame0);
        imshow("Frame1", frame1);
      } else {
        printf(" --(!) No captured frame -- Break!");
        break;
      }
      int c = waitKey(10);
      if((char)c == 'c') { break; }
      if((char)c == 't'){
        cvtColor( frame0, gray_image0, CV_BGR2GRAY );
        cvtColor( frame1, gray_image1, CV_BGR2GRAY );
        imwrite( "../calibImgs/"+std::to_string(captureIndex)+"a.jpg", gray_image0);
        imwrite( "../calibImgs/"+std::to_string(captureIndex)+"b.jpg", gray_image1);
        captureIndex++;
      }
    }
  }
  return 0;
}
