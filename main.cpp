#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <fstream>
#include "chakma_ocr.h"


int main()
{
    cv:: Mat ip, st;
    cv::vector<cv::vector<cv::Point> > inp, rst, sorted_inp, sorted_rst;
    iii::acquire_image("in.png", ip);
    iii::acquire_image("1.png", st);
    iii::Image input_image(ip), standard_image(st);
    std::vector<std::vector<char> > list;
    input_image.binarize();
    std::cout<<"after first Binary"<<std::endl;
    standard_image.binarize();
    //view::show_image(input_image.get_binarized_image());
    //view::show_image(standard_image.get_binarized_image());
    input_image.get_contours(inp);
    std::cout<<"Main:"<<inp.size()<<std::endl;
    standard_image.get_contours(rst);
    std::cout<<"Main:"<<rst.size()<<std::endl;
    cont::contours_processor input(inp), rossetta(rst);
    std::cout<<"after the processor declarations"<<std::endl;
    input.get_sorted_contours(sorted_inp);
    rossetta.get_sorted_contours(sorted_rst);
    std::cout<<"after the processor declarations"<<std::endl;
    cmp::creat_char_list(list);
    std::cout<<"after the processor declarations"<<std::endl;
    cmp::mtch_cnt(sorted_inp, sorted_rst, list);

    return 0;


}
