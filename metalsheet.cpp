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
    vector<MetalSheet> small;
    vector<MetalSheet> big;
public:
    void read_small(istream & is);
    void write_small(ostream & os);
    void read_big(istream & is);
    void write_big(ostream & os);
    int whole_area()const;
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
int ToOptimize::whole_area() const {
    int area = 0;
    for (auto metalsheet : small)
    {
        area += metalsheet.area() * metalsheet.quantity;
    }
    return area;
}
vector<MetalSheet> ToOptimize::needed_big_sheets() const {
    vector<MetalSheet> needed_big_sheets;
    int whole_area = this -> whole_area();
    //int *areas_of_big_sheets = static_cast<int *>(malloc(sizeof(int) * big.size()));
    int areas_of_big_sheets[10];
    for (int i=0; i < big.size(); ++i)
    {
        areas_of_big_sheets[i] = big[i].area();
    }

    for (int i=0; i < big.size(); ++i)
    {
        int quantity_big = 0;
        bool out_of_stock = true;
        while (whole_area > 0 && out_of_stock)
        {
            if (quantity_big >= big[i].quantity)
            {
                cerr << "ERROR: Out of stock, sheet number " << i << endl;
                out_of_stock = false;
                break;
            }
            quantity_big++;
            whole_area -= areas_of_big_sheets[i];
        }
        MetalSheet to_add;
        to_add.quantity = quantity_big;
        to_add.width = big[i].width;
        to_add.high = big[i].high;
        needed_big_sheets.push_back(to_add);
    }
    return needed_big_sheets;
}

//TESTY

void reading_from_file_test()
{
    ToOptimize test_tp;
    ifstream file ("small_sheets.csv");
    if (!file)
    {
        cerr << "ERROR: Opening the file didn't succeeded";
        return;
    }
    test_tp.read_small(file);
    test_tp.write_small(cout);
}
void whole_area_test()
{
    ToOptimize test_tp;
    ifstream file ("small_sheets.csv");
    if (!file)
    {
        cerr << "ERROR: Opening the file didn't succeeded";
        return;
    }
    test_tp.read_small(file);
    cout << endl <<test_tp.whole_area()<<endl;
}
void needed_big_sheets_test()
{
    ToOptimize test_tp;
    ifstream file_small ("small_sheets.csv");
    ifstream file_big ("big_sheets.csv");
    if (!file_small || !file_big)
    {
        cerr << "ERROR: Opening the file_small didn't succeeded";
        return;
    }
    test_tp.read_small(file_small);
    test_tp.read_big(file_big);
    test_tp.write_small(cout);
    test_tp.write_big(cout);
    vector<MetalSheet> to_print = test_tp.needed_big_sheets();
    for (auto & metal : to_print)
    {
        metal.write(cout);
    }
}


int main ()
{
    //reading_from_file_test();
    //whole_area_test();
    needed_big_sheets_test();
    return 0;
}