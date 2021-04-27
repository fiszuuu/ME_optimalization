#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;



class MetalSheet
{
public:
    int x;
    int y;
    int high;
    int width;
    int quantity;
    int area ();
    void rotate();
    bool does_cross(MetalSheet& mt);
    void write(ostream & os);
    void read(istream & is);
};

//METODY MetalSheet
int MetalSheet::area() {
    return high*width;
}
void MetalSheet::rotate(){
    swap(high, width);
}
bool MetalSheet::does_cross(MetalSheet&mt)
{
    if (mt.x < x + width && mt.y < y + high)
        return true;
    return false;
}
void MetalSheet::write(ostream & os) {
    os << quantity << ';'<< high << ';' << width << endl;
}
void MetalSheet::read(istream & is){
    string s;
    getline(is, s, ';');
    quantity = atoi(s.c_str());
    getline(is , s, ';');
    high = atoi(s.c_str());
    getline (is, s, ';');
    width = atoi(s.c_str());
}

class ToOptimize
{
    vector<MetalSheet> small;
    vector<MetalSheet> big;
public:
    void read_small(istream & is);
    void write_small(ostream & os);
};

//METODY ToOptimize
void ToOptimize::read_small(istream &is) {
    string s;
    getline(is, s, ';');
    int i=0;
    while (is)
    {
        MetalSheet ms;
        ms.read(is);
        if (!is)
            return;
        small.push_back(ms);
        ++i;
    }
}
void ToOptimize::write_small(ostream &os)
{
    for(int i=0; i < small.size(); ++i)
    {
        small[i].write(os);
    }
}

//TESTY

void reading_from_file_test()
{
    ToOptimize test_tp;
    ifstream file ("data.csv");
    if (!file)
    {
        cerr << "ERROR: Opening the file didn't succeeded";
        return;
    }
    test_tp.read_small(file);
    test_tp.write_small(cout);
}
int main ()
{
    reading_from_file_test();
    return 0;
}