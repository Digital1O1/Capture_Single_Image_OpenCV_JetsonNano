#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture video(0);

    if (!video.isOpened()) {
        std::cout << "Error opening webcam stream" << std::endl;
        return -1;
    }

    cv::Mat frame;
    video >> frame;

    if (frame.empty()) {
        std::cout << "No frame captured from the webcam" << std::endl;
        return -1;
    }

    cv::imshow("Frame", frame);
    cv::imwrite("output_frame.jpg", frame);

    // Press any key to exit out program
    cv::waitKey(0);

    video.release();
    cv::destroyAllWindows();

    return 0;
}