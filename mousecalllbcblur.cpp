#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace cv;
using namespace std;
const int slider_max_rear = 100;
const int slider_max_front = 100;
int alpha_slider,fx,fy,rx,ry;
int Rear,Front;
//front=10;rear=10;
 Mat img,srcf,srcb;
uchar f0,f1,f2;
uchar r0,r1,r2;




void on_trackbar_front(int ,void*)

{
int i ,j;
int front=20+Front;

 for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
		if(img.at<Vec3b>(i,j)[0] >(f0-front) && img.at<Vec3b>(i,j)[0]<(f0+front))
			if(img.at<Vec3b>(i,j)[1] >(f1-front) && img.at<Vec3b>(i,j)[1]<(f1+front))
				if(img.at<Vec3b>(i,j)[2] >(f2-front) && img.at<Vec3b>(i,j)[2]<(f2+front))
					srcf.at<uchar>(i,j)=255;
				else
					srcf.at<uchar>(i,j)=0;
			else
				srcf.at<uchar>(i,j)=0;
		else
			srcf.at<uchar>(i,j)=0;
 
 //imshow("Sourcef",srcf);
 imshow("Source",srcf+srcb);

}

void on_trackbar_rear(int ,void*)

{
int i,j;
int rear=Rear+20;
   for(i=0;i<img.rows;i++)
	for(j=0;j<img.cols;j++)
		if(img.at<Vec3b>(i,j)[0] >(r0-rear) && img.at<Vec3b>(i,j)[0]<(r0+rear))
			if(img.at<Vec3b>(i,j)[1] >(r1-rear) && img.at<Vec3b>(i,j)[1]<(r1+rear))
				if(img.at<Vec3b>(i,j)[2] >(r2-rear) && img.at<Vec3b>(i,j)[2]<(r2+rear))
					srcb.at<uchar>(i,j)=255;
					
				//cout<<i<<j<<endl;
				else
					srcb.at<uchar>(i,j)=0;
			else
				srcb.at<uchar>(i,j)=0;
		else
			srcb.at<uchar>(i,j)=0;
 //imshow("Sourceb",srcb);
 imshow("Source",srcf+srcb);
}


void call_Front(int event,int x ,int y,int flag,void* userdata)
{
  if (event == EVENT_LBUTTONDOWN)
   {
	fx=x;fy=y;	
    f0 = img.at<Vec3b>(y, x)[0];
    f1 = img.at<Vec3b>(y, x)[1];
    f2 = img.at<Vec3b>(y, x)[2];
    printf("%d %d %d %d \n", y,x,fy,fx); 
    on_trackbar_front(0 ,NULL);
   }
 			
}

void call_Rear(int event,int x,int y,int flag,void* userdata)
{
  if (event == EVENT_LBUTTONDOWN)
   {
	rx=x;ry=y;	
    f0 = img.at<Vec3b>(y, x)[0];
    f1 = img.at<Vec3b>(y, x)[1];
    f2 = img.at<Vec3b>(y, x)[2];
    printf("%d %d %d %d \n", y,x,ry,rx);
    on_trackbar_rear(0 ,NULL);	
   }		
}




int main(int argc,char *argv[])
{
int c;

img = imread(argv[1],CV_LOAD_IMAGE_COLOR);   
srcf=Mat::zeros(img.size(), CV_8U);   
srcb=Mat::zeros(img.size(), CV_8U);  

namedWindow("Front", WINDOW_NORMAL);  
imshow("Front",img);
/*
namedWindow("Rear", 1);  
imshow("Rear",img);

createTrackbar("FrontBar","Front",&Front,slider_max_front,on_trackbar_front);
setMouseCallback("Front",call_Front,NULL);

createTrackbar("RearBar","Rear",&Rear,slider_max_rear,on_trackbar_rear);
setMouseCallback("Rear",call_Rear,NULL);

//namedWindow("Sourcef",3);
//namedWindow("Sourceb",3);
namedWindow("Source",3);

*/
 

while ((c = waitKey(3)) != 27){}

    
return 0;
}
