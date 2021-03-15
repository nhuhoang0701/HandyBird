#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

#include "BackgroundRemover.h"
#include "SkinDetector.h"
#include "FaceDetector.h"
#include "FingerCount.h"

using namespace cv;
using namespace std;

int main(int, char **)
{
    VideoCapture webcam(0);

    webcam.set(CAP_PROP_SETTINGS, 1);

    if (!webcam.isOpened())
    {
        cerr << "Can't find camera! Please check your camera setting again!\n";
        return -1;
    }

    Mat frame, frameOut, handMask, foreground, fingerCountDebug;

    BackgroundRemover backgroundRemover;
    SkinColorDetector skinDetector;
    FaceDetector faceDetector;
    FingerCount fingerCount;

    while (true)
    {
        webcam >> frame;

        // Flip the frame so that the image is more intuitive to see
        flip(frame, frame, 1);
        frameOut = frame.clone();

        skinDetector.drawSkinColorSampler(frameOut);

        foreground = backgroundRemover.getForeground(frame);

        faceDetector.removeFaces(frame, foreground);
        handMask = skinDetector.getSkinMask(foreground);
        fingerCountDebug = fingerCount.findFingersCount(handMask, frameOut);

        imshow("output", frameOut);
        imshow("foreground", foreground);
        imshow("handMask", handMask);
        imshow("handDetection", fingerCountDebug);

        int key = waitKey(1);

        if (key == 113) // q
            break;
        else if (key == 98) // b
            backgroundRemover.calibrate(frame);
        else if (key == 115) // s
            skinDetector.calibrate(frame);
    }

    return 0;
}
