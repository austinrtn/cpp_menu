#pragma once
#include <string>
#include <vector>

struct Page {
    int index;
    int minIndex;
    int maxIndex;
    int size;
    std::vector<std::string> string_vect;

    Page(int size, std::vector<std::string> string_vect){
        if(size > string_vect.size()) size = string_vect.size();
        this->size = size;
        this->string_vect = string_vect;

        index = 0;
        minIndex = 0;
        if(string_vect.size() == size) maxIndex = 0;
        else maxIndex = string_vect.size() / size;
    }

    std::vector<std::string> getPage(){
        int min = index*size;
        int max = index*size + size;

        if(max > string_vect.size()) max = string_vect.size();
        return std::vector<std::string>(string_vect.begin()+min, string_vect.begin()+max);
    }
};