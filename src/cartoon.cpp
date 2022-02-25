#include <cartoon.h>
namespace cart
{
    using namespace cv;
    void cartoonifyImage(cv::Mat *srcImage)
    {
        if (srcImage->empty())
        {
            std::cerr << ERR << "srcFile is Correpted or Empty !\n";
            return;
        }
        else
        {
            // std::cerr << MESS << "Performing cartoonify Algorithm.\n ";

            cv::Mat gray;
            cv::cvtColor(*srcImage, gray, cv::COLOR_BGR2GRAY);
            const int MEDIAN_BLUR_FILTER_SIZE{7};
            cv::medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE);
            cv::Mat edges;
            const int LAPLACIAN_FILTER_SIZE{5};
            cv::Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE);

            Mat mask;
            const int EDGES_THRESHOLD = 80;
            threshold(edges, mask, EDGES_THRESHOLD, 255, THRESH_BINARY_INV);

            Size size = srcImage->size();
            Size smallSize;
            smallSize.width = size.width / 2;
            smallSize.height = size.height / 2;
            Mat smallImg = Mat(smallSize, CV_8UC3);
            resize(*srcImage, smallImg, smallSize, 0, 0, INTER_LINEAR);

            Mat tmp = Mat(smallSize, CV_8UC3);
            auto repetitions = 7; // Repetitions for strong cartoon effect.
            for (auto i = 0; i < repetitions; i++)
            {
                auto ksize = 9;        // Filter size. Has large effect on speed.
                double sigmaColor = 9; // Filter color strength.
                double sigmaSpace = 7; // Spatial strength. Affects speed.
                bilateralFilter(smallImg, tmp, ksize, sigmaColor, sigmaSpace);
                bilateralFilter(tmp, smallImg, ksize, sigmaColor, sigmaSpace);
            }

            Mat bigImg;
            resize(smallImg, bigImg, size, 0, 0, INTER_LINEAR);
            Mat dst;
            dst.setTo(0);
            bigImg.copyTo(dst, *srcImage);
        };
    };

    void About()
    {
        std::cerr << "\n.......\n[COPYRIGHT NOTICE] Copyright(c) 2022 Vishal Ahirwar. All rights reserved.\n";
        std::cerr << MESS << "OpenCV + C++ ||}\n.......\n";
    };

}