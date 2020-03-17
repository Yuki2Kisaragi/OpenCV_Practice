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

    while (cap.read(frame))//無限ループ
    {
        //
        //取得したフレーム画像に対して，クレースケール変換や2値化などの処理を書き込む．
        //

        imshow("image Window", frame);//画像を表示．
        cout << "s: save image q: quit" << endl;
        const int key = waitKey(5000);
        if (key == 'q'/*113*/)//qボタンが押されたとき
        {
            break;//whileループから抜ける．
        }
        else if (key == 's'/*115*/)//sが押されたとき
        {
            //フレーム画像を保存する．
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


