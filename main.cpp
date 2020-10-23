#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <string>
#include <Eigen/Dense>
#include <Eigen/Core>

using namespace std;

int main() {

    ifstream in("/home/xcy/CLionProjects/regex/data.txt");
    vector<double> content;
    double data;
    string str1;
    regex r("[1-9]\\d*\\.\\d*|0\\.\\d*[1-9]\\d*$");
    vector<Eigen::Vector3d> observation;
    int count = 0;
    while(getline(in, str1))
    {
        for(sregex_iterator it(str1.begin(), str1.end(), r), end_it; it != end_it; ++it)
        {
            data = stof( it->str() );
            content.push_back(data);
        }
    }

    for(vector<double>::size_type ix = 0; ix != content.size(); ix += 3)
    {
        Eigen::Vector3d observation1(content[ix], content[ix + 1], content[ix + 2]);
        observation.push_back(observation1);
    }
    for(vector<Eigen::Vector3d>::iterator it = observation.begin(); it != observation.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << observation.size() << endl;

    std::cout << "Hello, World!" << std::endl;

    return 0;
}
