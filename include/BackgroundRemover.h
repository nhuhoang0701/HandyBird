#ifndef __BACKGROUNDREMOVER_H__
#define __BACKGROUNDREMOVER_H__

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class BackgroundRemover
{
public:
	BackgroundRemover(void);
	void calibrate(Mat input);
	Mat getForeground(Mat input);

private:
	Mat background;
	bool calibrated = false;

	Mat getForegroundMask(Mat input);
	void removeBackground(Mat input, Mat background);
};

#endif // __BACKGROUNDREMOVER_H__
