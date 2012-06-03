#include "Application.h"
#include <iostream>
#include <vector>
#include "imageprocessor.h"
#include "globals.h"

Application::Application(int argc, char *argv[])
{
    cv::namedWindow("Main");
    readImages(argc, argv);
    processImages();
}

void Application::readImages(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++) {
        cv::Mat foo = cv::imread(argv[i], 0);
        m_imageFiles.push_back(foo);
    }
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
    cv::Mat falseColorImage(cv::Size(WIDTH, HEIGHT), CV_8UC3);
    ImageProcessor::merge(m_currentImageFiles, falseColorImage);

    cv::Mat thresholdImage(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    ImageProcessor::threshold(falseColorImage, thresholdImage);

    std::vector<std::vector<cv::Point> >  contours;
    cv::Mat contoursImage(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    cv::Mat thresholdCopy(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    contoursImage.copyTo(thresholdCopy);
    ImageProcessor::findContours(thresholdCopy, contours);

    contoursImage = falseColorImage.clone();
    cv::drawContours(contoursImage, contours, -1, cv::Scalar::all(WHITE));

    cv::imwrite("falseColorImage.tif", falseColorImage);
    cv::imwrite("thresholdImage.tif", thresholdImage);
    cv::imwrite("contoursImage.tif", contoursImage);
}


int main(int argc, char *argv[]) {
    Application foo (argc, argv);
    return 0;
}
