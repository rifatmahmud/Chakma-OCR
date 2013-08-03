#ifndef MATCH_H_INCLUDED
#define MATCH_H_INCLUDED

#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <vector>
#include <fstream>

namespace cmp
{


    void creat_char_list(std::vector<std::vector<char> > &out_letters);
    void mtch_cnt(cv::vector<cv::vector<cv::Point> > input, cv::vector<cv::vector<cv::Point> > rosetta, std::vector<std::vector<char> > letters);
}



#endif // MATCH_H_INCLUDED
