#include "imageprocessor.h"
#include "globals.h"
#include <qdebug.h>

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


QImage ImageProcessor::IplImage2QImage(const IplImage *iplImage)
{
    //! Copy and paste from http://www.developer.nokia.com/Community/Wiki/Using_OpenCV_with_Qt
    int height = iplImage->height;
    int width = iplImage->width;

    if  (iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 3)
    {
      const uchar *qImageBuffer = (const uchar*)iplImage->imageData;
      QImage img(qImageBuffer, width, height, QImage::Format_RGB888);
      return img.rgbSwapped();
    } else if  (iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 1){
    const uchar *qImageBuffer = (const uchar*)iplImage->imageData;
    QImage img(qImageBuffer, width, height, QImage::Format_Indexed8);

    QVector<QRgb> colorTable;
    for (int i = 0; i < 256; i++){
        colorTable.push_back(qRgb(i, i, i));
    }
    img.setColorTable(colorTable);
    return img;
    }else{
      qWarning() << "Image cannot be converted.";
      return QImage();
    }
}