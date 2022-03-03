#include"head_opencv.h"

//ģ��ƥ��

//2106040808�ؼ���

void quickdemo::video_open02(Mat& pic)
{
	VideoCapture vid01("C:/Users/����8255/Desktop/1234567.mp4");
	Mat frame;
	while (true)
	{
		vid01.read(frame);
		if (frame.empty())
		{
			break;
		}
		video_change(frame);
		int c = waitKey(50);
		if (c == 27)//esc�����˳���Ƶ
		{
			break;
		}
	}
	vid01.release();
}

void quickdemo::video_change(Mat& pic)
{
	int th = 60;//��һ����ҵ�������60���ڶ�������10
	Mat gray;
	cvtColor(pic, gray, COLOR_BGR2GRAY);
	Mat erzhi_01;
	threshold(gray, erzhi_01, th, 255, THRESH_BINARY);

	imshow("��ֵ�����ͼ��",erzhi_01);

	

	matching_pic(erzhi_01,pic);
}


void quickdemo::matching_pic(Mat& amid,Mat&norr)
{
	Mat temp;//������ʾ���
	amid.copyTo(temp);

	Mat pics = imread("C:/Users/����8255/Desktop/3_6.png");
	Mat pic;
	cvtColor(pics, pic, COLOR_BGR2GRAY);


	int result_cols = abs(amid.cols - pic.cols + 1);
	int result_rows = abs(amid.rows - pic.rows + 1);
	Mat result = Mat(result_cols, result_rows, CV_32FC1);

	cout << amid.cols << "   " << amid.rows << "    " 
	<< pics.cols << "     " << pic.rows << endl;

	//����ģ��ƥ��
	matchTemplate(amid, pic, result, TM_SQDIFF);
	double minval, maxval;
	Point minloc, maxloc, matchloc;
	minMaxLoc(result, &minval, &maxval, &minloc, &maxloc, Mat());
	matchloc = minloc;

	double angle = -20.0;
	double scale = 0.6;
	double i = 0.0;
	Mat new_image;
	//��תͼƬ֮��ȶ�
	while (i > angle)
	{
		new_image=xuanzhuan_pic(pic, angle, scale);

		matchTemplate(amid,new_image,result,TM_CCOEFF);
		minMaxLoc(result, &minval, &maxval, &minloc, &maxloc, Mat());
		matchloc = maxloc;

		i = i - 1.0;
	}

	//���ƾ���
	rectangle(norr, Rect(matchloc, Size(200,200)), Scalar(0, 0, 255), 2, 8, 0);
	imshow("Ŀ��׷��",norr);
	imshow("һ��ͼƬ", pic);

}


Mat quickdemo::xuanzhuan_pic(Mat& amid,double angle,double scale)
{
	Mat change_pic;

	Point center = Point(amid.cols / 2, amid.rows / 2);

	Mat rot_mat(2,3,CV_32FC1);

	//double i = 0.0;

	//cout << amid.cols << "   " << amid.rows << "    " << endl;
	rot_mat = getRotationMatrix2D(center, angle, scale);
	//cout << amid.cols << "   " << amid.rows << "    "
		//<< rot_mat.cols << "   " << rot_mat.rows<<endl;
	warpAffine(amid,change_pic,rot_mat,amid.size());

	imshow("��תͼ��",change_pic);

	return change_pic;
}