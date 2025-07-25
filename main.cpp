#include <opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
    Mat image = imread("D:/Resources/picture/2442110227.jpg");
    imshow("蓝底证件", image);
    Mat hsv;
    cvtColor(image, hsv, COLOR_BGR2HSV);
    Mat mask;
    inRange(hsv, Scalar(80, 43, 46), Scalar(101, 255, 255), mask);
    bitwise_not(mask, mask);
    Mat redBack = Mat::zeros(image.size(), image.type());
    redBack = Scalar(40, 40, 200);
    image.copyTo(redBack, mask);
    imshow("红底证件", redBack);
    waitKey(0);
	destroyAllWindows();
    return 0;
}