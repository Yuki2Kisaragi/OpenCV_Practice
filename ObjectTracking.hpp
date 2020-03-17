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
		
		// 1�t���[������荞��
		// cap ���� frame ��
		cap >> frame;				
		
		size_h = frame.rows;
		size_w = frame.cols;

		// �摜�����̂Ƃ��A�������[�v�𔲂���
		if (frame.empty()) {
			break;
		}

		// �E�B���h�E�ɉ摜��\������
		cv::imshow("�Đ���", frame );
		
		
		cout << "fps   =" << fps << endl;
		cout << "height=" << size_h << endl;
		cout << "width =" << size_w << endl;
		

		// 33ms�҂�
		// * �����ɃL�[���͂̑҂����Ԃ��w��ł���B�i�~���b�P�ʁj
		// * ������ 0 �܂��͉��������Ȃ��ꍇ�A�L�[���͂�����܂ő҂�������
		
		key = cv::waitKey(int(33)); //int cast 1000/15 =30fps

		if (key) {
			break;
		}
	
			
	}
	cap.release();

	return 0;
}
