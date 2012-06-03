#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class Application
{
public:
    Application(){};
    Application(int argc, char *argv[]);


protected:
    std::vector<cv::Mat> m_mageFiles;
    void readImages(int argc, char *argv[]);
    void processImages();
};
