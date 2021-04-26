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
    int area ();
    void rotate();
    bool does_cross(MetalSheet& mt);
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

class ToOptimize
{
    vector<MetalSheet> small;
    vector<MetalSheet> big;
    int small_quantity;
public:
    void read(istream & is);
};

//METODY ToOptimize
void ToOptimize::read(istream &is) {
    string s;
    getline(is, s, ';');
    int i=0;
    while (is)
    {
        getline(is , s, ';');
        small[i].high = stoi(s);
        getline (is, s, ';');
        small[i].width = stoi(s);

    }

}
int main ()
{
    ifstream file("data.csv");
    if (!file)
    {
        cout << "ERROR";
        exit(1);
    }
    int tab[10];
    int a;
    string s, trah;
    getline(file , trah, ';');
    file >> tab[0];
    file >> tab[1];
    file >> tab[3];
    for (int i=0; i < 3; i++)
    {
        cout<<tab[i]<< " ";
    }
    //getline(file, s);
    //cout<<s<<endl;
    //a = stoi(s);
    /*int i =0;
    while (getline(file, s ,';'))
    {
        tab[i]= stoi(s);
        cout<<tab[i]<<endl;
        i++;
    }*/
    return 0;
}