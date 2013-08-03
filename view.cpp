#include <cv.h>
#include "view.h"
#include <highgui.h>

namespace view
{

    void show_image(cv::Mat image)
    {
        cv::namedWindow(" ", 1);
        cv::imshow(" ", image);
        cv::waitKey(0);

    }

    void write_image(cv::Mat image, const char *filepath)
    {
        cv::imwrite(filepath, image);
    }

}
