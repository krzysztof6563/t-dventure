#pragma once 
#include <iostream>
#include <stdexcept>


class AbstractRenderer {
    public:
        virtual int printText(std::string text, int x, int y) = 0;
        virtual int updateWindow() = 0;
};