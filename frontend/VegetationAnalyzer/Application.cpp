#include "Application.h"
#include <iostream>
#include <vector>
#include "imageprocessor.h"
#include "globals.h"

Application::Application(int argc, char *argv[])
{
    cv::namedWindow("Main");

    readImages(argv);
    processImages();
}

void Application::readImages(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++) {
        cv::Mat foo = cv::imread(argv[i], 0);
        m_imageFiles.push_back(foo);
    }
}

void Application::processImages()
{
    cv::Mat falseColorImage(cv::Size(WIDTH, HEIGHT), CV_8UC3);
    ImageProcessor::merge(m_imageFiles, falseColorImage);

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
