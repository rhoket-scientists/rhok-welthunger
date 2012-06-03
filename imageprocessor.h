#ifndef ImageProcessor_H
#define ImageProcessor_H
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

class ImageProcessor
{
private:
    ImageProcessor(){};

public:
    static void threshold(cv::Mat& src, cv::Mat& dst);
    static void findContours(cv::Mat& src, std::vector<std::vector<cv::Point> >&  polygons);
    static void merge(std::vector<cv::Mat>& src, cv::Mat& dst);
};

#endif // ImageProcessor_H
