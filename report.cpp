#include <iostream>
#include <vector>

using namespace std;

/*
 * The main body is all one line, pls no h8
 */
int main(int argc, char** argv) {
    /*
     * Basic Ideas:
     * creative use of reinterpret_cast
     * recurse on main, only load when argv contains just original string (use dynamic_cast?)
     * Else divide in 4, recurse on each. Print in correct order
     * creative use of comma and ?:
     */
    return // This is all one line, didn't you hear?

        // This check gets rid of the original argc and argv. We don't care for their type around these parts
        argc != 1 ? 
            cin >> argc, // waste one input here. We read until we are out so the first int doesnt matter
            
            // OS deletes argv so don't worry about it
            argv = new char*[11],
            argv[0] = NULL,
            argv[1] = NULL,
            argv[2] = reinterpret_cast<char*>(new vector<pair<double,double>>()),
            argv[3] = reinterpret_cast<char*>(new double(0)),
            argv[4] = reinterpret_cast<char*>(new double(1)),
            argv[5] = reinterpret_cast<char*>(new double(0)),
            argv[6] = reinterpret_cast<char*>(new double(1)),
            argv[7] = NULL,
            argv[8] = NULL,
            argv[9] = NULL,
            argv[10] = NULL,
            main(0, argv)
             :

            // The real part begins
            /*
             * argc is the program state
             * 
             * 0 is read and add to argv[2]
             * 1 is initial state. Don't call this with parameters
             * 2 is first split state
             * 3 is later split states, guarantees argv[7-10] will be initialized
             * 
             * From here each element of argv has special meaning
             * 
             * [0] = garbage, basically a free register. You are responsible for deleting anything you create
             * [1] = second garbage, counter in states 2-3
             * [2] = pointer to vector holding all doubles to use
             * [3] = pointer to minimum x value
             * [4] = pointer to maximum x value
             * [5] = pointer to minimum y value
             * [6] = pointer to maximum y value
             * [7] = vector for nw quad, null at pass
             * [8] = vector for ne quad, null at pass
             * [9] = vector for se quad, null at pass
             * [10] = vector for sw quad, null at pass
             */
            //cin >> argv[0],

            (argc == 0) ?
                argv[0] = reinterpret_cast<char*>(new double()),
                argv[1] = reinterpret_cast<char*>(new double()),
                cin >> *reinterpret_cast<double*>(argv[0]),
                cin >> *reinterpret_cast<double*>(argv[1]),
                cin ?
                    reinterpret_cast<vector<pair<double,double>>*>(argv[2])->push_back(
                        pair<double,double>(
                            *reinterpret_cast<double*>(argv[0]),
                            *reinterpret_cast<double*>(argv[1]))),
                    delete argv[0],
                    delete argv[1],
                    main(0, argv)
                     :
                    delete argv[0],
                    delete argv[1],
                    argv[1] = reinterpret_cast<int*>(new int(0)),
                    main(2, argv)
                 :

                // recurse to split values here


                0;            
}
