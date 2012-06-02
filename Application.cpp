#include "Application.h"
#include <iostream>
#include <vector>
#include "imageprocessor.h"
#include "globals.h"

Application::Application(int argc, char *argv[])
{

    /*cv::Mat foo(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    cv::resize(cv::imread(argv[1]), foo, cv::Size(WIDTH,HEIGHT));
    cv::namedWindow("Main");
    cv::imshow("Main", foo);*/
    /*cv::Mat output(cv::Size(WIDTH, HEIGHT), CV_8UC3);
    output.create(imageFiles[0].size(), CV_8UC1);*/
    //cv::namedWindow("Main");

    std::vector<cv::Mat> imageFiles;
    for(int i = 1; i < argc; i++) {
        cv::Mat foo = cv::imread(argv[i], 0);
        imageFiles.push_back(foo);
    }

    cv::Mat falseColorImage(cv::Size(WIDTH, HEIGHT), CV_8UC3);
    ImageProcessor::merge(imageFiles, falseColorImage);

    //std::cout << out.rows << ", ";
    //std::cout << out.cols << std::endl;

    // ImageProcessor
    //cv::imwrite("rgb.tif", out);

    cv::Mat thresholdImage(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    ImageProcessor::threshold(falseColorImage, thresholdImage);

    //cv::threshold(result, redImg, 10, 255, cv::THRESH_TOZERO_INV);
    //cv::threshold(result,result, 0, , CV_THRESH_TOZERO);
    //std::cout << result;

    std::vector<std::vector<cv::Point> >  contours;
    cv::Mat contoursImage(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    ImageProcessor::findContours(thresholdImage,contours);

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
