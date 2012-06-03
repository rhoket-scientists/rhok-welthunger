#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "imageprocessor.h"
#include <QString>
#include <QList>
#include <list>
#include "globals.h"

class Application
{
public:
    Application();

    protected:
        std::vector<cv::Mat> m_imageFiles;
	std::vector<cv::Mat> m_currentImageFiles;
        ImageProcessor* m_imageProcessor;
        cv::Mat m_falseColorImage;
        void loop();

    public:
        void readImages(QList<QString> v);
        void processImages();
	void topographic_textures();
	void atmospheric_penetration();
	void agricultural_studies();
	void color_contrast();
	void atmospheric_particles();
	void land_water_boundaries();
	void healthy_vegetaion();
	void natural_like_rendition();
	void natural_color();
	void false_color();
};
