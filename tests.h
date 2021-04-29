#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;
#ifndef METALSHEET_CPP_TESTS_H
#define METALSHEET_CPP_TESTS_H

#endif //METALSHEET_CPP_TESTS_H
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
    cout << endl << whole_area(test_tp.small) <<endl;
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
    //test_tp.write_big(cout);
    vector<MetalSheet> to_print = test_tp.needed_big_sheets();
    for (auto & metal : to_print)
    {
        metal.write(cout);
    }
}
