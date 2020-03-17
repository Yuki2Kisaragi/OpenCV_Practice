#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <opencv2/opencv.hpp>

using namespace std;

int MovieStream() {
	
	double fps = 0;
	float size_h = 0;
	float size_w = 0;
	int key = 0;

	cv::Size resize_window;
	cv::Mat resize_frame;
	cv::Mat frame;
	cv::VideoCapture cap;

	cap.open("sample.avi");

	if (!cap.isOpened()) {
		cout << "Can't' opened" << endl;
		return -1;
	}
	while(cap.isOpened()) {
		
		fps = cap.get(CAP_PROP_FPS);
		
		// 1フレームずつ取り込む
		// cap から frame へ
		cap >> frame;				
		
		size_h = frame.rows;
		size_w = frame.cols;

		// 画像から空のとき、無限ループを抜ける
		if (frame.empty()) {
			break;
		}

		// ウィンドウに画像を表示する
		cv::imshow("再生中", frame );
		
		
		cout << "fps   =" << fps << endl;
		cout << "height=" << size_h << endl;
		cout << "width =" << size_w << endl;
		

		// 33ms待つ
		// * 引数にキー入力の待ち時間を指定できる。（ミリ秒単位）
		// * 引数が 0 または何も書かない場合、キー入力があるまで待ち続ける
		
		key = cv::waitKey(int(33)); //int cast 1000/15 =30fps

		if (key) {
			break;
		}
	
			
	}
	cap.release();

	return 0;
}
