#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
#ifndef METALSHEET_CPP_TESTS_H
#define METALSHEET_CPP_TESTS_H


void test_reading_from_file()
{
    ToOptimize test_tp;
    ifstream file ("small_sheets.csv");
    if (!file)
    {
        cerr << "ERROR: Opening the file didn't succeeded";
        return;
    }
    test_tp.small.read(file);
    test_tp.small.write(cout);
}
void test_whole_area()
{
    ToOptimize test_tp;
    ifstream file ("small_sheets.csv");
    if (!file)
    {
        cerr << "ERROR: Opening the file didn't succeeded";
        return;
    }
    test_tp.small.read(file);
    cout << endl << test_tp.small.whole_area() <<endl;
}
void test_needed_big_sheets()
{
    ToOptimize test_tp;
    ifstream file_small ("small_sheets.csv");
    ifstream file_big ("big_sheets.csv");
    if (!file_small || !file_big)
    {
        cerr << "ERROR: Opening the file_small didn't succeeded";
        return;
    }
    test_tp.small.read(file_small);
    test_tp.big.read(file_big);
    test_tp.small.write(cout);
    //test_tp.big.write(cout);
    VectorOfSheets to_print = test_tp.needed_big_sheets();
    for (auto & metal : to_print)
    {
        metal.write(cout);
    }
}
void test_VectorOfSheets()
{
    VectorOfSheets small;
    ifstream file ("big_sheets.csv");
    if (!file)
    {
        cerr << "ERROR: Opening the file didn't succeeded";
        return;
    }
    small.read(file);
    cout<<small.whole_area()<<endl;
    small.write(cout);
}
void test_sort()
{
    VectorOfSheets small;
    ifstream file ("small_sheets.csv");
    if (!file)
    {
        cerr << "ERROR: Opening the file didn't succeeded";
        return;
    }
    small.read(file);
    small.write(cout);
    small.sort();
    cout<<endl;
    small.write(cout);
}

#endif //METALSHEET_CPP_TESTS_H