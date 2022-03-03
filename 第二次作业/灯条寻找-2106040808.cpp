#include"head_opencv.h"



//读取视频/按键控制

void quickdemo::video_open(Mat& pic)
{
	VideoCapture vid01("C:/Users/嘉言8255/Desktop/1234567.mp4");
	Mat frame;
	while (true)
	{
		vid01.read(frame);
		if (frame.empty())
		{
			break;
		}
		all_change(frame);
		//imshow("vid01",gray);
		int c = waitKey(50);
		if (c == 27)//esc按键退出视频
		{
			break;
		}
	}
	vid01.release();
}

//划线（仅4个点）

void quickdemo::drawall(vector<RotatedRect>rec, Mat& pic)
{
	for (int i = 0; i < rec.size(); i++)
	{
		Point2f p[4];
		rec[i].points(p);
		line(pic,p[0],p[1],Scalar(0,0,255),1,8,0);
		line(pic, p[1], p[2], Scalar(0, 0, 255), 1, 8, 0);
		line(pic, p[2], p[3], Scalar(0, 0, 255), 1, 8, 0);
		line(pic, p[3], p[0], Scalar(0, 0, 255), 1, 8, 0);
	}
	imshow("all_of_end",pic);
}

//寻找特定轮廓

void quickdemo::all_change(Mat& pic)
{	
	int th = 100;
	//二值化_01
	Mat gray;
	cvtColor(pic, gray, COLOR_BGR2GRAY);
	Mat erzhi_01;
	threshold(gray,erzhi_01,th,255, THRESH_OTSU);

	vector<Mat>pic_channel;
	split(pic, pic_channel);

	Mat split_pic;
	subtract(pic_channel[0], pic_channel[2], split_pic);

	Mat erzhi;
	
	threshold(split_pic, erzhi, th, 255, THRESH_OTSU);

	Mat peng_pic;
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	dilate(erzhi, peng_pic, element);

	Mat max_color = erzhi_01 & peng_pic;
	dilate(max_color,max_color,element);

	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	findContours(max_color.clone(),contours,hierarchy, RETR_EXTERNAL,CHAIN_APPROX_SIMPLE,Point());

	vector< RotatedRect>armors;
	vector<RotatedRect>armor_rects;
	RotatedRect armor_rect;
	

	Mat drawinging = Mat::zeros(pic.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		drawContours(drawinging, contours, i, Scalar(255,0,0));
	}
	imshow("lunkuotu", drawinging); 

	vector<RotatedRect>light_infos;

	for (const auto& contours_s : contours)
	{
		float contour_area = contourArea(contours_s);

		//这里筛选是为了不让局部栈溢出
		if (contours_s.size() <= 100 &&(contour_area > 1000 && contour_area < 3000))//嗯？算是简陋的筛选？而且也没有矫正长宽和角度之类的
		{
			RotatedRect light_rec = fitEllipse(contours_s);

			if (light_rec.angle < 20 || light_rec.angle>150)//限定角度 随便找的数据
			{
				cout << light_rec.angle << "   ";
				light_infos.push_back(light_rec);
			}
			
		}	
		cout << endl;
	}
	if (light_infos.size() <= 1)
	{
		cout << "something error" << endl;
	}
	//按灯条中心x从小到大排序
	sort(light_infos.begin(), light_infos.end(), [](const RotatedRect& ld1, const RotatedRect& ld2)
		{
			return ld1.center.x < ld2.center.x;
		});

	for (int i = 0; i < light_infos.size(); i++)
	{
		for (int j = i + 1; j < light_infos.size(); j++)
		{
			const RotatedRect& left = light_infos[i];//左灯条
			const RotatedRect& right = light_infos[j];//右灯条

			float heightDiff = abs(left.size.height-right.size.height);
			float widthDiff = abs(left.size.width - right.size.width);

			armor_rect.center.x = (left.center.x + right.center.x) / 2;
			armor_rect.center.y = (left.center.y+right.center.y)/2;
			armor_rect.angle = (left.angle+right.angle)/2;
			
			armor_rect.size.height = (left.size.height+right.size.height)/2;
			armor_rect.size.width = sqrt((left.center.x-right.center.x)* (left.center.x - right.center.x)+
				(left.center.y-right.center.y)* (left.center.y - right.center.y));

			double nL = armor_rect.size.height;
			double nW = armor_rect.size.width;
			if (nL < nW)
			{
				armor_rect.size.height = nL;
				armor_rect.size.width = nW;
			}
			else
			{
				armor_rect.size.height = nW;
				armor_rect.size.width = nL;
			}

			for (int i = 0; i < armors.size(); i++)
			{
				Rect roiRect = armors[i].boundingRect();
				//Mat roiImg = src(roiRect);
			}
			armor_rects.emplace_back(armor_rect);
			armors.push_back(armor_rect);

			if (armor_rects.empty())
			{
				cout << "something wrong!" << endl;
			}
			//cout << left.size.height << "  " << right.size.height << "   " << heightDiff << "   " << widthDiff << "   ";
		}
		//cout << endl;
	}
	drawall(armors,pic);	
}

