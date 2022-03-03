
#include "armordetection.h"

ArmorDetection::ArmorDetection() = default;

ArmorDetection::ArmorDetection(Mat & input) 
{
	frame = input;
}

void ArmorDetection::setInputImage(Mat input) 
{
	frame = input;
	currentCenter.x = 0;
	currentCenter.y = 0;
}

//图像预处理
void ArmorDetection::Pretreatment()
{
	Mat input;
	Point p, center;
	vector<vector<Point>> contours;
	vector<Vec4i> hireachy;
	vector<Rect> boundRect(contours.size());
	Point2f vertex[4];
	cvtColor(frame, hsv, COLOR_BGR2GRAY);
	threshold(hsv, mask, 200, 255, THRESH_BINARY);

	dilate(mask, mask, kernel2, Point(-1, -1), 1);//膨胀
	//轮廓增强
	Canny(mask, mask, 3, 9, 3);
	findContours(mask, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	//筛选，去除一部分矩形

	minRects.clear();

	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect minRect = minAreaRect(contours[i]);
		minRect.points(vertex);


		if (((minRect.size.width > 50) && (minRect.size.height< 20))|| ((minRect.size.height > 50)&&( minRect.size.width < 20)))
		{
			
			
				for (int l = 0; l < 4; l++)
				{
					line(frame, vertex[l], vertex[(l + 1) % 4], Scalar(255, 0, 0), 2);

				}
				
		
		}
		minRects.push_back(minRect);
	}
}

void ArmorDetection::GetArmorCenter() 
{
	//遍历所有矩形，两两组合
	RotatedRect leftRect, rightRect;

	if (minRects.size() < 2)
	{
		while (1)
		{
			Pretreatment();
			if (minRects.size() >= 2)
			{
				break;
			}
		}
	}



	for (int i = 0; i < minRects.size(); i++)
	{
		for (int j = i + 1; j < minRects.size(); j++) 
		{
			leftRect = minRects[i];
			rightRect = minRects[j];

			//判断
			if ((leftRect.size.width * leftRect.size.height < 2000) && (rightRect.size.width * rightRect.size.height < 2000))
			{
				if ((leftRect.size.width * leftRect.size.height > 300) && (rightRect.size.width * rightRect.size.height > 300))
				{
					if (abs(leftRect.center.x - rightRect.center.x) < 200)
					{
						if (abs(leftRect.center.y - rightRect.center.y) < 40)
						{
							if (abs(leftRect.angle - rightRect.angle) < 30)
							{
								if (abs(leftRect.size.width * leftRect.size.height - rightRect.size.width * rightRect.size.height) < 300)
								{
									
										currentCenter.x = (leftRect.center.x + rightRect.center.x) / 2;
										currentCenter.y = (leftRect.center.y + rightRect.center.y) / 2;
									
								}
							}
						}
					}
				}
			}

			
			
		}


	}

	line(frame, Point(currentCenter.x - 10, currentCenter.y - 10),
		Point(currentCenter.x + 10, currentCenter.y + 10), Scalar(255, 255, 0), 5);
	line(frame, Point(currentCenter.x + 10, currentCenter.y - 10),
		Point(currentCenter.x - 10, currentCenter.y + 10), Scalar(255, 255, 0), 5);
	circle(frame, currentCenter, 7.5, Scalar(0, 0, 255), 5);
	imshow("frame", frame);
		
}



