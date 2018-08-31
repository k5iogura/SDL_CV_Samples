#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <cv.h>
#include <highgui.h>

//#define FULL_SCREEN   // For FullScnreen Mode

//#define CAP_WIDTH 640
//#define CAP_HEIGHT 480
#define CAP_WIDTH 960
#define CAP_HEIGHT 720

#define FRAME_WAIT 30

#define WIN_NAME "Capture"

//============================================================

int main(int argc, char *argv[]) {
    CvCapture *capture = 0;
    IplImage *frame = 0;

    int inp_key;

    if (argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0])))
        capture = cvCreateCameraCapture(argc == 2 ? argv[1][0] - '0' : 0);

    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, CAP_WIDTH);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, CAP_HEIGHT);

#ifdef FULL_SCREEN
    cvNamedWindow(WIN_NAME, 0);
    cvSetWindowProperty(WIN_NAME, CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
#else
    cvNamedWindow(WIN_NAME, CV_WINDOW_AUTOSIZE);
#endif

    while(1)
    {
        frame = cvQueryFrame(capture);

        cvShowImage(WIN_NAME, frame);

        inp_key = cvWaitKey(FRAME_WAIT);

        if (inp_key >= 0) {
            if (inp_key == 27 || inp_key == 81 || inp_key == 113) break;
        }
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow(WIN_NAME);

    return 0;
}
