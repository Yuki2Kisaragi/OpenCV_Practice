#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int VideoCaputuring() {
    int count = 0;
    
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        
        return -1;

    }
    Mat frame;

    while (cap.read(frame))//�������[�v
    {
        //
        //�擾�����t���[���摜�ɑ΂��āC�N���[�X�P�[���ϊ���2�l���Ȃǂ̏������������ށD
        //

        imshow("image Window", frame);//�摜��\���D
        cout << "s: save image q: quit" << endl;
        const int key = waitKey(5000);
        if (key == 'q'/*113*/)//q�{�^���������ꂽ�Ƃ�
        {
            break;//while���[�v���甲����D
        }
        else if (key == 's'/*115*/)//s�������ꂽ�Ƃ�
        {
            //�t���[���摜��ۑ�����D
            while (1) {
                count++;
                string img_name ="img"+to_string(count)+".png";
                imwrite(img_name, frame);

            }

        }
    }
    destroyAllWindows();
    return 0;
}


