#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

int RealTimeObjectDitection()
{
	cv::VideoCapture video(0); //�J�����̋N��
    // args =0 =PC�����J����
	// args =1 =USB�J����

	if (!video.isOpened()) { //�G���[����

		std::cout << "video.error" << std::endl;
		return -1;
	}

	cv::Mat frame; //�t���[���i�[�p

	cv::CascadeClassifier cascade; //�J�X�P�[�h���ދ@�i�[�p

	cascade.load("C:/opencv4.0.0/sources/data/haarcascades_cuda/haarcascade_frontalface_default.xml");
	//���ʂ̊猟�m �J�X�P�[�h�t�@�C���̓ǂݍ���

	std::vector<cv::Rect> contour; //��`�i�[�p

	while (video.read(frame)) { //���[�v

		cascade.detectMultiScale(frame, contour, 1.1, 5, 0, cv::Size(15, 15)); //�Ώۂ̌��o

		for (int i = 0; i < contour.size(); i++) { //���o�����J��Ԃ�
			cv::rectangle(frame, cv::Point(contour[i].x, contour[i].y), cv::Point(contour[i].x + contour[i].width, contour[i].y + contour[i].height), cv::Scalar(0, 0, 0), 1); //��`�̉���
		}

		cv::imshow("frame", frame); //�\��

		int key = cv::waitKey(1);

		if (key == 'q') {

			cv::destroyWindow("frame");
			break;
		}
	}

	return 0;
}