#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

#ifndef METALSHEET_CPP_CLASSES_H
#define METALSHEET_CPP_CLASSES_H

#endif //METALSHEET_CPP_CLASSES_H
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

class ToOptimize
{
public:
    vector<MetalSheet> small;
    vector<MetalSheet> big;
    void read_small(istream & is);
    void write_small(ostream & os);
    void read_big(istream & is);
    void write_big(ostream & os);
    static int whole_area(vector<MetalSheet> & metalsheets = small);
    vector<MetalSheet> needed_big_sheets()const;
};

//METODY ToOptimize
void ToOptimize::read_small(istream &is) {
    string s;
    getline(is, s);
    while (is)
    {
        MetalSheet ms;
        ms.read(is);
        if (!is)
            return;
        small.push_back(ms);
    }
}
void ToOptimize::write_small(ostream &os)
{
    for(auto & metalSheet : small)
    {
        metalSheet.write(os);
    }
}
void ToOptimize::read_big(istream &is)
{
    string s;
    getline(is, s);
    int i=0;
    while (is)
    {
        MetalSheet ms;
        ms.read(is);
        if (!is)
            return;
        big.push_back(ms);
        ++i;
    }
}
void ToOptimize::write_big(ostream &os)
{
    for(auto & metalSheet : big)
    {
        metalSheet.write(os);
    }
}
static int ToOptimize::whole_area(vector<MetalSheet> & metalsheets){
    int area = 0;
    for (auto metalsheet : metalsheets)
    {
        area += metalsheet.area() * metalsheet.quantity;
    }
    return area;
}
vector<MetalSheet> ToOptimize::needed_big_sheets() const {
    vector<MetalSheet> needed_big_sheets, left_small_sheets = small;

    //int *areas_of_big_sheets = static_cast<int *>(malloc(sizeof(int) * big.size()));
    int area_of_big_sheet;
    int area_of_left_smalls;
    for (int i=0; i < big.size(); ++i)
    {
        int quantity_big = 0;
        area_of_big_sheet = big[i].area();
        area_of_left_smalls = whole_area(left_small_sheets);
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
                cerr << "ERROR: Out of stock, sheet number " << i << endl;
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

