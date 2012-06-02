#include "imageprocessor.h"
#include "globals.h"

//ImageProcessor::ImageProcessor()
//{}

bool ImageProcessor::merge(std::vector<cv::Mat>& src, cv::Mat& dst)
{
    cv::merge(src, dst);
    return true;
}

bool ImageProcessor::threshold(cv::Mat& src, cv::Mat& dst)
{
    cv::Vec3b pixel;
    for(int x = 0; x < WIDTH;  x++) {
        for(int y = 0; y < HEIGHT; y++) {
            //pixel = out.at<cv::Vec3b>(y,x);
            pixel = src.at<cv::Vec3b>(y,x);
            if( (pixel[2] >= minRed) and (pixel[0] < maxBlue) and (pixel[1] < maxGreen)) {
                dst.at<unsigned char>(y,x) = WHITE;
            } else {
                dst.at<unsigned char>(y,x) = BLACK;
            }
        }
    }
    return true;
}

bool ImageProcessor::contours(cv::Mat& src, std::vector<std::vector<cv::Point> >&  polygons)
{
    cv::Point offset = cv::Point();
    cv::findContours(src, polygons,
                     CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE,
                     offset);
}
