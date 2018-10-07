#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap;
    cap.open(0);

    if(!cap.isOpened())
    return 0;
    int key;
    const char* path;
    path="/home/zhz937966670/Qt5.5.1/Document/Camera_1/savePicture.jpg";
    Mat frame;
    while(1)
    {
        cap>>frame;
        if(frame.empty())
            break;
        imshow("video", frame);
        key=waitKey(20);
        if(key==83||key==115)
        {
           imwrite(path,frame);
           cout<<"Successfully save the photo!"<<endl;
        }
        else if(key>0&&key!=83&&key!=115)
        {
            break;
        }
    }
    cap.release();
    destroyAllWindows();
    return 0;
}

