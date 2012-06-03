#include "Application.h"
#include <iostream>
#include <vector>
#include "imageprocessor.h"
#include "globals.h"
#include <QString>

Application::Application()
{
    int minRed = 20;
    int maxBlue = 100;
    int maxGreen = 100;

    /*
    cv::createTrackbar("Minimum Red", "Main", &minRed, 255);
    cv::createTrackbar("Maximum Blue", "Main", &maxBlue, 255);
    cv::createTrackbar("Maximum Green", "Main", &maxGreen, 255);
    */

    m_imageProcessor = ImageProcessor(minRed, maxGreen, maxBlue);
    //readImages(argc, argv);

    m_falseColorImage = cv::Mat (cv::Size(WIDTH, HEIGHT), CV_8UC3);
}

void Application::false_color(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[1]);
	m_currentImageFiles.push_back(m_imageFiles[2]);
	m_currentImageFiles.push_back(m_imageFiles[3]);
	processImages();
}

void Application::natural_color(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[0]);
	m_currentImageFiles.push_back(m_imageFiles[1]);
	m_currentImageFiles.push_back(m_imageFiles[2]);
	processImages();
}

void Application::natural_like_rendition(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[1]);
	m_currentImageFiles.push_back(m_imageFiles[3]);
	m_currentImageFiles.push_back(m_imageFiles[6]);
	processImages();
}

void Application::healthy_vegetaion(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[0]);
	m_currentImageFiles.push_back(m_imageFiles[4]);
	m_currentImageFiles.push_back(m_imageFiles[3]);
	processImages();
}

void Application::land_water_boundaries(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[2]);
	m_currentImageFiles.push_back(m_imageFiles[4]);
	m_currentImageFiles.push_back(m_imageFiles[3]);
	processImages();
}

void Application::atmospheric_particles(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[2]);
	m_currentImageFiles.push_back(m_imageFiles[4]);
	m_currentImageFiles.push_back(m_imageFiles[6]);
	processImages();
}

void Application::color_contrast(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[2]);
	m_currentImageFiles.push_back(m_imageFiles[3]);
	m_currentImageFiles.push_back(m_imageFiles[4]);
	processImages();
}

void Application::agricultural_studies(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[0]);
	m_currentImageFiles.push_back(m_imageFiles[3]);
	m_currentImageFiles.push_back(m_imageFiles[4]);
	processImages();
}

void Application::atmospheric_penetration(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[3]);
	m_currentImageFiles.push_back(m_imageFiles[4]);
	m_currentImageFiles.push_back(m_imageFiles[6]);
	processImages();
}

void Application::topographic_textures(){
	m_currentImageFiles.clear();
	m_currentImageFiles.push_back(m_imageFiles[0]);
	m_currentImageFiles.push_back(m_imageFiles[2]);
	m_currentImageFiles.push_back(m_imageFiles[4]);
	processImages();
}

void Application::processImages()
{
    
        // Create one RGB img
    cv::Mat falseColorImage(cv::Size(WIDTH, HEIGHT), CV_8UC3);
    ImageProcessor::merge(m_currentImageFiles, falseColorImage);

    borderPixels = calculateBorder(m_falseColorImage);
    std::cout << borderPixels << "\n";

    cv::Mat thresholdImage(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    std::cout <<  m_imageProcessor.threshold(m_falseColorImage, thresholdImage) << "\n";

    std::vector<std::vector<cv::Point> >  contours;
    cv::Mat contoursImage(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    cv::Mat thresholdCopy(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    //contoursImage.copyTo(thresholdCopy);
    //m_imageProcessor.findContours(thresholdCopy, contours);

    //contoursImage = m_falseColorImage.clone();
    //cv::drawContours(contoursImage, contours, -1, cv::Scalar(0, 255, 0));

    cv::imwrite("falseColorImage.tif", m_falseColorImage);
    cv::imwrite("thresholdImage.tif", thresholdImage);
    //cv::imwrite("contoursImage.tif", contoursImage);
}

void Application::readImages(std::list<QString> v)
{
    m_imageFiles.clear();

    for(int i = 0; i < v.size(); i++) {
        cv::Mat foo = cv::imread(v[i].toStdString(), 0);
        cv::resize(foo, foo, cv:Size(4044, 3570));
        m_imageFiles.push_back(foo);
    }

    m_imageProcessor.merge(m_imageFiles, m_falseColorImage);
}

/*int main(int argc, char *argv[]) {
    Application foo (argc, argv);
    return 0;
}*/
