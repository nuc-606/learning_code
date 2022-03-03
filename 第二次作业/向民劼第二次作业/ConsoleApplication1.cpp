#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "armordetection.h"

using namespace cv;
using namespace std;

ArmorDetection* armor = new ArmorDetection();
Point2f center;

int main()
{
	
	Mat frame;

		VideoCapture capture("C:\\Users\\17970\\Desktop\\23456789.avi");

		namedWindow("frame", WINDOW_AUTOSIZE);

		while (capture.read(frame))//读取当前帧
		{
			armor->setInputImage(frame);
			armor->Pretreatment();
			armor->GetArmorCenter();

			char c = waitKey(10);
			if (c == 27) //"Esc"
			{
				break;
			}
		}
		capture.release();//释放视频内存
		waitKey(0);
		return 0;
	
}
