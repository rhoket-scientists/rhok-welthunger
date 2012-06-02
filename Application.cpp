#include "Application.h"
#include <iostream>
#include <vector>

int HEIGHT = 400;
int WIDTH = 400;

Application::Application(int argc, char *argv[])
{
    std::vector<cv::Mat> imageFiles;
    /*cv::Mat foo(cv::Size(WIDTH, HEIGHT), CV_8UC1);
    cv::resize(cv::imread(argv[1]), foo, cv::Size(WIDTH,HEIGHT));

    cv::namedWindow("Main");
    cv::imshow("Main", foo);*/

    for(int i = 1; i < argc; i++) {
        cv::Mat foo = cv::imread(argv[i]);
        std::cout << foo.rows << ',' << foo.cols << "\n";
        imageFiles.push_back(foo);
    }

    /*cv::Mat output(cv::Size(WIDTH, HEIGHT), CV_8UC3);
    output.create(imageFiles[0].size(), CV_8UC1);
*/
    //cv::namedWindow("Main");


    cv::Mat out(cv::Size(8087, 7139), CV_8UC3);

    std::cout << out.rows << ", ";
    std::cout << out.cols << std::endl;

    for(int i = 0; i < 3; i++) {
        for(int col = 0; col < imageFiles[i].cols; col++) {
            for(int row = 0; row < imageFiles[i].rows; row++) {
                out.at<cv::Vec3b>(row, col)[i] = imageFiles[i].at<short>(row, col);
            }
        }
    }

    cv::imwrite("rgb.tif", out);

    /*
    std::vector<std::vector<cv::Point> >  contours;

    int minRed = 0;
    int maxBlue, maxGreen = 255;
    const short WHITE = 255;
    const short BLACK = 0;

    cv::Mat redImg(cv::Size(4044, 3570), CV_8UC3);

    cv::Mat result(cv::Size(4044, 3570), CV_8UC1);

    cv::Vec3b pixel;
    std::cout << out.rows << ", ";
    std::cout << out.cols << std::endl;

    for(int x = 0; x < out.cols;  x++) {
        for(int y = 0; y < out.rows; y++) {
            pixel = out.at<cv::Vec3b>(y,x);
            if(pixel[2] >= minRed /*and (pixel[0] < maxBlue) and (pixel[1] < maxGreen)) {
                result.at<short>(y,x) = WHITE;
                //std::cout << (short) pixel[2] << std::endl;
            }
            else {
                result.at<short>(y,x) = BLACK;
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
    cv::imwrite("rgb.tif", out);
*/}



int main(int argc, char *argv[]) {
    Application foo (argc, argv);
    std::cin.get();
    return 0;
}
