
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
// some Macros used in this program
#define ERR "\n[ERROR] --> "
#define WAR "\n[WARNING] --> "
#define MESS "\n[MESSAGE] --> "
// namespace cart == cartoonify
namespace cart
{
    void cartoonifyImage(cv::Mat *srcImage);
    void About();

    void faceDetection();
}