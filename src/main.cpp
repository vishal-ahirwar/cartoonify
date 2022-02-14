#include<iostream>
#include<opencv2/opencv.hpp>
void CartoonifyImage(cv::Mat&,cv::Mat&);

int main()
{
    std::cerr<<"Copyright(c) V101 Inc. developer : Vishal Ahirwar. All rights reserved.\n";

    cv::VideoCapture Cap(0);
    cv::Mat img,newimg;
    Cap.set(cv::CAP_PROP_FRAME_WIDTH,640);
    Cap.set(cv::CAP_PROP_FRAME_HEIGHT,400);

    while(true)
    {
        Cap.read(img);
        if(img.empty())return -1;
        CartoonifyImage(img,newimg);
        cv::imshow("cartoonify filter",newimg);
        if(cv::waitKey(1)==27)break;

    };


    return 0;

};
void CartoonifyImage(cv::Mat& old,cv::Mat& newImage)
{
 cv::Mat gray; 
 cv::cvtColor(srcColor, gray, CV_BGR2GRAY); 
 const int MEDIAN_BLUR_FILTER_SIZE = 7; 
 cv::medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE); 
 cv::Mat edges; 
 const int LAPLACIAN_FILTER_SIZE = 5; 
 cv::Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE);
 
}