#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "RealTimeObjectDitection.hpp"
#include "VideoCaputure.hpp"
#include "ObjectTracking.hpp"

using namespace std;
using namespace cv;


int main(void) {

	//RealTimeObjectDitection();  //顔認識プログラム
	//VideoCaputuring();		  // 

	MovieStream(); //sample stream

	return 0;
	system("pause");

}	
	



