#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;
using namespace std;

void CaptureImg() {


   // �摜�̓ǂݍ���
   cv::Mat image;
   image = cv::imread("C:\\opencv\\sources\\samples\\c\\baboon.jpg",1);
   //�\���E�B���h�E�̍쐬
   cv::namedWindow("WindowImage", 1);
   //�摜�̕\��
   cv::imshow("WindowImage", image);
   cv::waitKey(0);
   //�摜�̕ۑ�
   cv::imwrite("show.jpg", image);
   //�\���E�B���h�E�̍쐬
   cv::destroyWindow("WindowImage");
     

}

void ColorChange() {
    Mat image;
    Mat dst;
    //Mat image_arrange(Size(100, 100), CV_8U, Scalar::all(0));
    
    image = imread("C:\\opencv\\sources\\samples\\c\\baboon.jpg");
    //image_arrange = imread("C:\\opencv\\sources\\samples\\c\\baboon.jpg",0);
    
    //imshow("image", image);
    cout << "���摜" << endl;
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



