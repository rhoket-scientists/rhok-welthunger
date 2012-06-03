#ifndef ImageProcessor_H
#define ImageProcessor_H
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

class ImageProcessor
{

public:
    ImageProcessor(){};
    ImageProcessor(unsigned char minRed, unsigned char maxGreen, unsigned char maxBlue);
    void threshold(cv::Mat& src, cv::Mat& dst);
    void findContours(cv::Mat& src, std::vector<std::vector<cv::Point> >&  polygons);
    void merge(std::vector<cv::Mat>& src, cv::Mat& dst);

protected:
    unsigned char m_minRed;
    unsigned char m_maxGreen;
    unsigned char m_maxBlue;

};

#endif // ImageProcessor_H
