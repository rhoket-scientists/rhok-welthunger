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
        std::cout << imageFiles[i].cols * imageFiles[i].rows << std::endl;
    }


    for(int i = 0; i < 3; i++) {
        for(int x = 0; x < imageFiles[i].rows; x++) {
            for(int y = 0; y < imageFiles[i].cols; y++) {
                out.at<cv::Vec3b>(x,y)[i] = imageFiles[i].at<short>(x,y);
            }
        }
        cv::imwrite("outImg.tif", out);
    }
}



int main(int argc, char *argv[]) {
    Application foo (argc, argv);
    //std::cin.get();
    return 0;
}
