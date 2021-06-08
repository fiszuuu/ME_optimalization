#ifndef METALSHEET_CPP_CLASSES_H
#define METALSHEET_CPP_CLASSES_H


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;



class MetalSheet{
public:
    int high;
    int width;
    int quantity;
    int area ()const;
    void rotate();
    void write(ostream & os)const;
    void read(istream & is);
};
int MetalSheet::area()const{
    return high*width;
}
void MetalSheet::rotate(){
    swap(high, width);
}
void MetalSheet::write(ostream & os) const{
    os << quantity << ';'<< high << ';' << width << endl;
}
void MetalSheet::read(istream & is){
    string s;
    getline(is, s, ';');
    quantity = atoi(s.c_str());
    getline(is , s, ';');
    high = atoi(s.c_str());
    getline (is, s);
    width = atoi(s.c_str());
}

class OptimizedMetalSheet:public MetalSheet{
    int x;
    int y;
    bool does_cross(OptimizedMetalSheet & mt);
};
bool OptimizedMetalSheet::does_cross(OptimizedMetalSheet & mt)
{
    if (mt.x < x + width && mt.y < y + high)
        return true;
    return false;
}

class VectorOfSheets: public vector<MetalSheet>{
public:
    void read(istream & is);
    void write(ostream & os);
    int whole_area()const;
    void sort();
};
//METODY VectorOfMetalSheets
void VectorOfSheets::read(istream &is) {
    string s;
    getline(is, s);
    while (is)
    {
        MetalSheet ms;
        ms.read(is);
        if (!is)
            return;
        (*this).push_back(ms);
    }
}

void VectorOfSheets::write(ostream &os)
{
    for(auto & metalSheet : (*this))
    {
        metalSheet.write(os);
    }
}

int VectorOfSheets::whole_area() const {
    int area = 0;
    for (auto metalsheet :  (*this))
    {
        area += metalsheet.area() * metalsheet.quantity;
    }
    return area;
}
//by now no needed fast sort so it's bubble
void VectorOfSheets::sort()
{
    for (int i=0; i<(*this).size()-1; ++i)
    {
        for (int j=0; j<(*this).size()-1-i; ++j)
        {
            if ((*this)[j].area() < (*this)[j+1].area())
                ::swap((*this)[j], (*this)[j+1]);
        }
    }
}

class ToOptimize
{
public:
    VectorOfSheets small;
    VectorOfSheets big;
    VectorOfSheets needed_big_sheets()const;
};


VectorOfSheets ToOptimize::needed_big_sheets() const {
    VectorOfSheets left_small_sheets = small, needed_big_sheets;
    int area_of_big_sheet;
    int area_of_left_smalls;
    for (int i=0; i < big.size(); ++i)
    {
        int quantity_big = 0;
        area_of_big_sheet = big[i].area();
        area_of_left_smalls = left_small_sheets.whole_area();
        bool out_of_stock = true;
        while (area_of_left_smalls > 0 && out_of_stock)
        {
            for (MetalSheet small_sheet : small)
            {
                if (small_sheet.high > big[i].high || small_sheet.width > big[i].width)
                {
                    area_of_left_smalls -= small_sheet.area();
                    left_small_sheets.clear();
                    left_small_sheets.push_back(small_sheet);
                }
                small_sheet.rotate();
                if (small_sheet.high > big[i].high || small_sheet.width > big[i].width)
                {
                    area_of_left_smalls -= small_sheet.area();
                    left_small_sheets.clear();
                    left_small_sheets.push_back(small_sheet);
                }
            }
            if (quantity_big >= big[i].quantity)
            {
                cerr << "ERROR: Out of stock, sheet number " << i+1 << " (" << big[i].high << "x" << big[i].width << ")" << endl;
                out_of_stock = false;
                break;
            }
            quantity_big++;
            area_of_left_smalls -= area_of_big_sheet;
        }
        MetalSheet to_add;
        to_add.quantity = quantity_big;
        to_add.width = big[i].width;
        to_add.high = big[i].high;
        needed_big_sheets.push_back(to_add);
    }
    return needed_big_sheets;
}
#endif //METALSHEET_CPP_CLASSES_H