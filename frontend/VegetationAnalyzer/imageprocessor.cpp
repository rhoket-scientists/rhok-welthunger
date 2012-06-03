#include "imageprocessor.h"
#include "globals.h"

ImageProcessor::ImageProcessor(/*unsigned char minRed, unsigned char maxGreen, unsigned char maxBlue*/)
{
    m_minRed = (unsigned char)20;
    m_maxBlue = (unsigned char)100;
    m_maxGreen = (unsigned char)100;
}

void ImageProcessor::merge(std::vector<cv::Mat>& src, cv::Mat& dst)
{
    cv::merge(src, dst);
}

int ImageProcessor::threshold(cv::Mat& src, cv::Mat& dst)
{
    cv::Vec3b pixel;
    int c = 0;
    for(int x = 0; x < WIDTH;  x++) {
        for(int y = 0; y < HEIGHT; y++) {
            pixel = src.at<cv::Vec3b>(y,x);
            if( (pixel[2] >= m_minRed) and (pixel[0] < m_maxBlue) and (pixel[1] < m_maxGreen)) {
                dst.at<unsigned char>(y,x) = BLACK;
                c++;
            } else {
                dst.at<unsigned char>(y,x) = WHITE;
            }
        }
    }
}

int ImageProcessor::calculateBorder(cv::Mat& src)
{
    cv::Vec3b pixel;
    int c = 0;
    for(int x = 0; x < WIDTH;  x++) {
        for(int y = 0; y < HEIGHT; y++) {
            pixel = src.at<cv::Vec3b>(y,x);
            if( (!pixel[2]) and (!pixel[0]) and (!pixel[1])) 
                c++;
        }
    }
}

/*
void ImageProcessor::findContours(cv::Mat src, std::vector<std::vector<cv::Point> >&  polygons)
{
    //! Danger: This method modifies the input image

    cv::Point offset = cv::Point();
    cv::findContours(src, polygons,
            CV_RETR_TREE, CV_CHAIN_APPROX_NONE,
                     offset);
}*/
