#include "debugging.h"
#include <vector>
#include <iostream>

using namespace std;

void log(vector<pair<double,double>>* list) {
    cerr << "    ";
    for (pair<double,double> p : *list) {
        cerr << "(" << p.first << "," << p.second << ")";
    }
    cerr << endl;
}

void log(double xmin, double xmax, double ymin, double ymax) {
    cerr << "    xmin='" << xmin << "' xmax='" << xmax << "' ymin='" << ymin << "' ymax='" << ymax << "'" << endl;
}

void log(string location) {
    cerr << location << ":" << endl;
}