#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;


ofstream mergeArraysFromBin2Txt(ifstream* ifs, ifstream* ifs_1)
{
	double num = 0;
	std::vector<double> first;
	std::vector<double> second;

	while (ifs->read((char*)&num, sizeof(double)))
	{
		first.push_back(num);
	}
	while (ifs_1->read((char*)&num, sizeof(double)))
	{
		second.push_back(num);
	}
	ofstream wf("end.txt");
	int i = 0;
	int j = 0;
	std::vector<double> end;
	while (i < first.size() && j < second.size()) {
		if (first[i] <= second[j]) {
			end.push_back(first[i]);
			++i;
		}
		else {
			end.push_back(second[j]);
			++j;
		}
	}

	while (i < first.size()) {
		end.push_back(first[i]);
		++i;
	}

	while (j < second.size()) {
		end.push_back(second[j]);
		++j;
	}
	for (int i = 0; i < end.size(); i++)
	{
		wf << end[i] << " ";
	}
	return wf;
}


//int main()
//{
//	ifstream ifs("binar.bin", ios::in | ios::binary);
//	ifstream ifs_1("binar1.bin", ios::in | ios::binary);
//	mergeArraysFromBin2Txt(&ifs, &ifs_1);
//
//	return 0;
//}
//
