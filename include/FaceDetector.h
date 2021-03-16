#ifndef __FACEDETECTOR_H__
#define __FACEDETECTOR_H__

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class FaceDetector
{
public:
	FaceDetector(void);
	void removeFaces(Mat input, Mat output);
};

#endif // __FACEDETECTOR_H__
