#ifndef CONTOUR_H_INCLUDED
#define CONTOUR_H_INCLUDED

#include <cv.h>
#include <highgui.h>
#include <iostream>

//extern cv::vector<cv::vector<cv::Point> > processable_contours, sorted_contours;

namespace cont
{
    class contours_processor
    {
        public:
            contours_processor(cv::vector<cv::vector<cv::Point> > contours);
            virtual ~contours_processor();
            void get_sorted_contours(cv::vector<cv::vector<cv::Point> > &returned_sorted_contours);
        private:
             cv::vector<cv::vector<cv::Point> > processable_contours;

    };

    void save_contours_as_image(cv::vector<cv::vector<cv::Point> > cont2im, const char *filepath);
    double get_avg_dist(cv::vector<cv::vector<cv::Point> > contours);
}


#endif // CONTOUR_H_INCLUDED
