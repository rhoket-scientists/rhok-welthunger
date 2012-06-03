#include "Application.h"
#include <iostream>
#include <vector>
#include "imageprocessor.h"
#include "globals.h"

Application::Application(int argc, char *argv[])
{
    cv::namedWindow("Main");
    int minRed = 20;
    int maxBlue = 100;
    int maxGreen = 100;

    cv::createTrackbar("Minimum Red", "Main", &minRed, 255);
    cv::createTrackbar("Maximum Blue", "Main", &maxBlue, 255);
    cv::createTrackbar("Maximum Green", "Main", &maxGreen, 255);

    m_imageProcessor = ImageProcessor(minRed, maxGreen, maxBlue);
    readImages(argc, argv);

    // Create one RGB img
    m_falseColorImage = cv::Mat (cv::Size(WIDTH, HEIGHT), CV_8UC3);
    m_imageProcessor.merge(m_imageFiles, m_falseColorImage);

    processImages();
}

void Application::processImages()
{
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

void Application::readImages(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++) {
        cv::Mat foo = cv::imread(argv[i], 0);
        cv::resize(foo, foo, cv:Size(4044, 3570));
        m_imageFiles.push_back(foo);
    }
}

int main(int argc, char *argv[]) {
    Application foo (argc, argv);
    return 0;
}
