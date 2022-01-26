#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


class Image
{
public:
	
	Image(int(&a)[8][8]);

	void threshold();

	friend class Rect;
private:
	
	vector<vector<int>> image2;
	int image[8][8];	 
};

Image::Image(int(&a)[8][8])
{
	memcpy(image, a, sizeof(a));
}

void Image::threshold()
{
	
}


class Rect
{
public:  
	
	Rect(Image& p):width(0), height(0),size(0),xCoord(0),yCoord(0)
	{
		int a[8] = { 0 }, b[8] = { 0 },c=0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if (p.image[i][j] == 0)
				{
					a[i]++;
					b[j]++;
				}
			}
		for (int i = 0; i < 8; i++)
		{
			if (a[i] != 0)
				height++;
			if (b[i] != 0)
				width++;
		}
		while (!c)
		{
			for(int i=0;i<8;i++)
				for (int j = 0; j < 8; j++)
				{
					if (p.image[i][j] == 0)
					{
						xCoord = i;
						yCoord = j;
						c = 1;
					}

				}
		}

		size = width * height;
	}
	
	int getWidth()
	{
		return width;
	};
	
	int getHeight();
	
	int getSize();

	float getCoord()
	{
		return xCoord;
	};


private:
	int width, height, size;
	float xCoord, yCoord;
	vector<vector<int>> image2;
};



int main()
{
	vector<vector<int>> image0= { {1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,0,0,11,1},
					{1,1,1,1,0,0,1,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1} };
	cout << image0.at(2);


	int a[8][8] = { {1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,0,0,11,1},
					{1,1,1,1,0,0,1,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1},
					{1,1,1,1,1,1,11,1} }; 
	
	Image b(a);
	Rect c(b);
	cout<<c.getWidth();
	cout << c.getCoord();
	
	return 0;

}






