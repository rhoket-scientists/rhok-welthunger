#include "imageprocessor.h"
#include "globals.h"

//ImageProcessor::ImageProcessor()
//{}

void ImageProcessor::merge(std::vector<cv::Mat>& src, cv::Mat& dst)
{
    cv::merge(src, dst);
}

void ImageProcessor::threshold(cv::Mat& src, cv::Mat& dst)
{
    cv::Vec3b pixel;
    for(int x = 0; x < WIDTH;  x++) {
        for(int y = 0; y < HEIGHT; y++) {
            pixel = src.at<cv::Vec3b>(y,x);
            if( (pixel[2] >= MIN_RED) and (pixel[0] < MAX_BLUE) and (pixel[1] < MAX_GREEN)) {
                dst.at<unsigned char>(y,x) = WHITE;
            } else {
                dst.at<unsigned char>(y,x) = BLACK;
            }
        }
    }
}

void ImageProcessor::findContours(cv::Mat& src, std::vector<std::vector<cv::Point> >&  polygons)
{
    //! Danger: This method modifies the input image

    cv::Point offset = cv::Point();
    cv::findContours(src, polygons,
                     CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE,
                     offset);
}
