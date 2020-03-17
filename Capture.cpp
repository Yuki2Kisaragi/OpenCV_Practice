#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;
using namespace std;

void CaptureImg() {


   // 画像の読み込み
   cv::Mat image;
   image = cv::imread("C:\\opencv\\sources\\samples\\c\\baboon.jpg",1);
   //表示ウィンドウの作成
   cv::namedWindow("WindowImage", 1);
   //画像の表示
   cv::imshow("WindowImage", image);
   cv::waitKey(0);
   //画像の保存
   cv::imwrite("show.jpg", image);
   //表示ウィンドウの作成
   cv::destroyWindow("WindowImage");
     

}

void ColorChange() {
    Mat image;
    Mat dst;
    //Mat image_arrange(Size(100, 100), CV_8U, Scalar::all(0));
    
    image = imread("C:\\opencv\\sources\\samples\\c\\baboon.jpg");
    //image_arrange = imread("C:\\opencv\\sources\\samples\\c\\baboon.jpg",0);
    
    //imshow("image", image);
    cout << "元画像" << endl;
    imshow("image", image);
    waitKey(0);
    
    cout << "RGB -> GRAY" << endl;
    cvtColor(image, dst, COLOR_RGB2GRAY);
    imshow("image", dst);
    waitKey(0);

    cout << "RGB -> HSV" << endl;
    cvtColor(image, dst, COLOR_RGB2HSV);
    imshow("image", dst);
    waitKey(0);
   
  
}



