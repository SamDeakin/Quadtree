#ifndef __DEBUGGING_H__
#define __DEBUGGING_H__
#include <vector>

/*
 * functions used only for debugging
 * these all print their input to cerr
 */

// "    ('list[0].first','list[0].second')('list[1].first','list[1].second')..."
void log(std::vector<std::pair<double,double>>* list);
// "    xmin='xmin' xmax='xmax' ymin='ymin' ymax='ymax'"
void log(double xmin, double xmax, double ymin, double ymax);
// "location:"
void log(std::string location);

#endif