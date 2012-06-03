#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class Application
{
	public:
		Application(int argc, char *argv[]);


    protected:
        std::vector<cv::Mat> m_imageFiles;
	std::vector<cv::Mat> m_currentImageFiles;

        void readImages(int argc, char *argv[]);
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
