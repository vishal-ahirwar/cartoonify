#include <cartoon.h>

int main()
{
    cart::About();

    cv::VideoCapture Cap(0);
    cv::Mat img, newimg;
    Cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    Cap.set(cv::CAP_PROP_FRAME_HEIGHT, 400);

    while (true)
    {
        Cap.read(img);
        if (img.empty())
            return -1;
        cart::cartoonifyImage(&img);
        cv::imshow("cartoonify filter", img);
        if (cv::waitKey(1) == 27)
            break;
    };

    return 0;
};
