#ifndef ImageProcessor_H
#define ImageProcessor_H
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

class ImageProcessor
{
private:
    ImageProcessor(){};

public:
    static bool threshold(cv::Mat& src, cv::Mat& dst);
    static bool findContours(cv::Mat& src, std::vector<std::vector<cv::Point> >&  polygons);
    static bool merge(std::vector<cv::Mat>& src, cv::Mat& dst);
};

#endif // ImageProcessor_H
