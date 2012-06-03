#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "imageprocessor.h"

class Application
{
public:
    Application();
    //Application(int argc, char *argv[]);


    protected:
        std::vector<cv::Mat> m_imageFiles;
        ImageProcessor m_imageProcessor;
        cv::Mat m_falseColorImage;

        void readImages(std::list<std::string> v);
        void processImages();
        void loop();
};
