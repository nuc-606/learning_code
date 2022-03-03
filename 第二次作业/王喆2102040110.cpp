#include "stdio.h"
#include<iostream> 
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main()
{
    //读取视频
    VideoCapture capture;
    capture.open("d:/c++/1234567.mp4");
    //设置参数
    Mat frame, channels[3], mp,au;
    Rect boundRect;
    Point currentRect;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    int matrix[2];
    int min = 9999;
    Rect array[20];
    while (capture.read(frame)) {
        split(frame, channels);//分离通道
        threshold(channels[1], mp, 100, 255, 0);
        GaussianBlur(mp, au, Size(3,3), 0);//高斯模糊
        findContours(au, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

        int b = 0;
        //灯条
        for (int i = 0; i < contours.size(); i++) {
            boundRect = boundingRect(Mat(contours[i]));
                if (boundRect.height > 40 )//筛选条件
                {
                   array[b] = boundRect;//寻找矩阵
                    b++;
                }
          
        }
        //匹配
        for (int p = 0; p < b - 1; p++)
        {
            for (int j = p + 1; j < b; j++) {
                int value = abs(array[p].area() - array[j].area());
                if (value < min)
                {
                    min = value;matrix[0] = p;matrix[1] = j;
                }
            }
        }
        //找点
            Rect rect01 = array[matrix[0]];
            Rect rect02 = array[matrix[1]];
            if ((abs(rect01.x - rect02.x) < 200)
                && (abs(rect01.y - rect02.y) < 40))
            {
                Point point0 = Point(rect01.x + rect01.width / 2, rect01.y);
                Point point1 = Point(rect01.x + rect01.width / 2, rect01.y + rect01.height);
                Point point2 = Point(rect02.x + rect02.width / 2, rect02.y);
                Point point3 = Point(rect02.x + rect02.width / 2, rect02.y + rect02.height);
                Point p[4] = { point0,point1,point3,point2 };//链接为矩阵
                //找圆心
                currentRect.x = (rect01.x + rect02.x + rect02.width / 2 + rect01.width / 2) / 2;
                currentRect.y = (rect01.y + rect02.y + rect02.height / 2 + rect01.height / 2) / 2;
                //画矩阵，画圆心
                for (int a = 0; a < 4; a++) {
                    line(frame, p[a % 4], p[(a + 1) % 4], Scalar(125, 0, 125), 2);
                    circle(frame, currentRect, 10, Scalar(125, 125, 255), 3);
                }

            }
        imshow("frame", frame);
        waitKey(10);
 
    }
    capture.release();
    destroyAllWindows();
    return 0;
}