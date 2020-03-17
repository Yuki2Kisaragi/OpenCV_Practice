#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

int RealTimeObjectDitection()
{
	cv::VideoCapture video(0); //カメラの起動
    // args =0 =PC内蔵カメラ
	// args =1 =USBカメラ

	if (!video.isOpened()) { //エラー処理

		std::cout << "video.error" << std::endl;
		return -1;
	}

	cv::Mat frame; //フレーム格納用

	cv::CascadeClassifier cascade; //カスケード分類機格納用

	cascade.load("C:/opencv4.0.0/sources/data/haarcascades_cuda/haarcascade_frontalface_default.xml");
	//正面の顔検知 カスケードファイルの読み込み

	std::vector<cv::Rect> contour; //矩形格納用

	while (video.read(frame)) { //ループ

		cascade.detectMultiScale(frame, contour, 1.1, 5, 0, cv::Size(15, 15)); //対象の検出

		for (int i = 0; i < contour.size(); i++) { //検出個数分繰り返し
			cv::rectangle(frame, cv::Point(contour[i].x, contour[i].y), cv::Point(contour[i].x + contour[i].width, contour[i].y + contour[i].height), cv::Scalar(0, 0, 0), 1); //矩形の可視化
		}

		cv::imshow("frame", frame); //表示

		int key = cv::waitKey(1);

		if (key == 'q') {

			cv::destroyWindow("frame");
			break;
		}
	}

	return 0;
}