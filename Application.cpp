#include "Application.h"
#include <iostream>
#include <vector>

Application::Application(int argc, char *argv[])
{
    std::vector<cv::Mat> imageFiles;

    for(int i = 1; i < argc; i++) {
        cv::Mat foo(cv::Size(4044, 3570), CV_8UC1);
        cv::resize(cv::imread(argv[i]), foo, foo.size());
        imageFiles.push_back(foo);
    }

    cv::Mat output;
    output.create(imageFiles[0].size(), CV_8UC1);

    //cv::namedWindow("Main");


    cv::Mat out(cv::Size(4044, 3570), CV_8UC3);

    //std::cout << out << std::endl;



    for(int i = 0; i < imageFiles.size(); i++) {
        //std::cout << imageFiles[i].cols * imageFiles[i].rows << std::endl;
    }


    for(int i = 0; i < 3; i++) {
        for(int x = 0; x < imageFiles[i].rows; x++) {
            for(int y = 0; y < imageFiles[i].cols; y++) {
                out.at<cv::Vec3b>(x,y)[i] = imageFiles[i].at<short>(x,y);
            }
        }
    }

    std::vector<std::vector<cv::Point> >  contours;

    int minRed = 0;
    int maxBlue, maxGreen = 255;
    const int WHITE = 255;
    const int BLACK = 0;

    cv::Mat redImg(4044, 3570, CV_8UC3);

    cv::Mat result(4044, 3570, CV_8UC1);

    for(int x = 0; x < out.rows; x++) {
        for(int y = 0; y < out.cols; y++) {
            cv::Vec3b pixel = out.at<cv::Vec3b>(x,y);
            if((pixel[2] >= minRed) /*and (pixel[0] < maxBlue) and (pixel[1] < maxGreen)*/) {
                result.at<short>(x, y) = WHITE;
                //std::cout << "Hi"<< std::endl;
            }
            else {
                result.at<short>(x,y) = BLACK;
            }
        }
    }

    //cv::threshold(result, redImg, 10, 255, cv::THRESH_TOZERO_INV);
    // cv::threshold(result,result, 0, , CV_THRESH_TOZERO);
    //std::cout << result;

    //cv::Point offset = cv::Point();

    // cv::findContours(redImg, contours,
    //                CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE,
    //              offset);


    //cv::Scalar colour = cv::Scalar::all(WHITE);
    //cv::drawContours(out, contours, -1, colour);

    cv::imwrite("outImg.tif", result);
    cv::imwrite("rgb.tif", out);
}



int main(int argc, char *argv[]) {
    Application foo (argc, argv);
    //std::cin.get();
    return 0;
}
