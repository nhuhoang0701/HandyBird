#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

class SkinColorDetector
{

private:
    int hLowThreshold = 0;
    int hHighThreshold = 0;
    int sLowThreshold = 0;
    int sHighThreshold = 0;
    int vLowThreshold = 0;
    int vHighThreshold = 0;

    bool calibrated = false;

    Rect skinColorSamplerRectangle1, skinColorSamplerRectangle2;

    void calculateThresholds(Mat sample1, Mat sample2);
    void performOpening(Mat binaryImage, int structuralElementShapde, Point structuralElementSize);

public:
    SkinColorDetector(void);

    void drawSkinColorSampler(Mat input);
    void calibrate(Mat input);
    Mat getSkinMask(Mat input);
};
