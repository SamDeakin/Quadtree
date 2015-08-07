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
     * recurse on main, use argc as the 'state' of the program
     * Else divide in 4, recurse on each. Print in correct order
     * creative use of comma and ?:
     */
    return // This is all one line, didn't you hear?

        // This check gets rid of the original argc and argv. We don't care for their type around these parts
        argc == 1 ? 
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
             * 1 is initial state. Don't call this program with command line arguments
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

                // state 0, read in
                argv[0] = reinterpret_cast<char*>(new double()),
                argv[1] = reinterpret_cast<char*>(new double()),
                cin >> *reinterpret_cast<double*>(argv[0]),
                cin >> *reinterpret_cast<double*>(argv[1]),
                cin ?(
                    reinterpret_cast<vector<pair<double,double>>*>(argv[2])->push_back(pair<double,double>(*reinterpret_cast<double*>(argv[0]),*reinterpret_cast<double*>(argv[1]))),
                    delete argv[0],
                    delete argv[1],
                    main(0, argv)
                    ):(
                    delete argv[0],
                    delete argv[1],
                    argv[1] = reinterpret_cast<char*>(new int(0)),
                    main(2, argv))
                 :
                (argc == 2) ?(

                    // state 2, initialize new vectors
                    argv[7] = reinterpret_cast<char*>(new vector<pair<double,double>>()),
                    argv[8] = reinterpret_cast<char*>(new vector<pair<double,double>>()),
                    argv[9] = reinterpret_cast<char*>(new vector<pair<double,double>>()),
                    argv[10] = reinterpret_cast<char*>(new vector<pair<double,double>>()),
                    main(3, argv)
                    ):(
                    
                    // state 3, print for now then recurse
                    cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])].first << endl,
                    cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])].second << endl,
                    
                    // this puts the current number into the correct quadrant
                    ((*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])].first <= 
                        ((*reinterpret_cast<double*>(argv[3]) + *reinterpret_cast<double*>(argv[4])) / 2) ?
                        // number on south side
                        (*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])].second <= 
                            ((*reinterpret_cast<double*>(argv[5]) + *reinterpret_cast<double*>(argv[6])) / 2) ?
                            // sw
                            reinterpret_cast<vector<pair<double,double>>*>(argv[10])->push_back((*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])])
                             :
                            // se
                            reinterpret_cast<vector<pair<double,double>>*>(argv[9])->push_back((*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])])
                         :
                        // number on north side
                        (*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])].second <= 
                            ((*reinterpret_cast<double*>(argv[5]) + *reinterpret_cast<double*>(argv[6])) / 2) ?
                            // nw
                            reinterpret_cast<vector<pair<double,double>>*>(argv[7])->push_back((*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])])
                             :
                            // ne
                            reinterpret_cast<vector<pair<double,double>>*>(argv[8])->push_back((*reinterpret_cast<vector<pair<double,double>>*>(argv[2]))[*reinterpret_cast<int*>(argv[1])])),

                    (*reinterpret_cast<int*>(argv[1]))++,

                    // this is the loop recursion statement
                    (*reinterpret_cast<int*>(argv[1]) < reinterpret_cast<vector<pair<double,double>>*>(argv[2])->size()) ?
                        main(3, argv)
                         :

                        // done putting values in their correct quadrant
                        // here we determine recursion
                        // nw first
                        (reinterpret_cast<vector<pair<double,double>>*>(argv[7])->size() < 2 ?(
                            // size 1 or 0, don't recurse
                            (reinterpret_cast<vector<pair<double,double>>*>(argv[7])->size() == 0 ?(
                                // 0, just delete the vector
                                delete argv[7],
                                0
                                ):(
                                // 1, print then delete
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[7]))[0].first << endl,
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[7]))[0].second << endl,
                                delete argv[7],
                                0))
                            ):(
                            // > 1 number, must divide further
                            argv[0] = reinterpret_cast<char*>(new char*[11]),
                            (reinterpret_cast<char**>(argv[0]))[0] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[1] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[2] = argv[7],
                            (reinterpret_cast<char**>(argv[0]))[3] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[3]) + *reinterpret_cast<double*>(argv[4])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[4] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[4])))),
                            (reinterpret_cast<char**>(argv[0]))[5] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[5])))),
                            (reinterpret_cast<char**>(argv[0]))[6] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[5]) + *reinterpret_cast<double*>(argv[6])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[7] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[8] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[9] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[10] = NULL,
                            main(2, reinterpret_cast<char**>(argv[0])))),
                        // ne
                        (reinterpret_cast<vector<pair<double,double>>*>(argv[8])->size() < 2 ?(
                            (reinterpret_cast<vector<pair<double,double>>*>(argv[8])->size() == 0 ?(
                                // 0, just delete the vector
                                delete argv[8],
                                0
                                ):(
                                // 1, print then delete
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[8]))[0].first << endl,
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[8]))[0].second << endl,
                                delete argv[8],
                                0))
                            ):(
                            // > 1 number, must divide further
                            argv[0] = reinterpret_cast<char*>(new char*[11]),
                            (reinterpret_cast<char**>(argv[0]))[0] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[1] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[2] = argv[8],
                            (reinterpret_cast<char**>(argv[0]))[3] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[3]) + *reinterpret_cast<double*>(argv[4])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[4] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[4])))),
                            (reinterpret_cast<char**>(argv[0]))[5] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[5]) + *reinterpret_cast<double*>(argv[6])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[6] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[6])))),
                            (reinterpret_cast<char**>(argv[0]))[7] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[8] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[9] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[10] = NULL,
                            main(2, reinterpret_cast<char**>(argv[0])))),
                        // se
                        (reinterpret_cast<vector<pair<double,double>>*>(argv[9])->size() < 2 ?(
                            (reinterpret_cast<vector<pair<double,double>>*>(argv[9])->size() == 0 ?(
                                // 0, just delete the vector
                                delete argv[9],
                                0
                                ):(
                                // 1, print then delete
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[9]))[0].first << endl,
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[9]))[0].second << endl,
                                delete argv[9],
                                0))
                            ):(
                            // > 1 number, must divide further
                            argv[0] = reinterpret_cast<char*>(new char*[11]),
                            (reinterpret_cast<char**>(argv[0]))[0] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[1] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[2] = argv[9],
                            (reinterpret_cast<char**>(argv[0]))[3] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[3])))),
                            (reinterpret_cast<char**>(argv[0]))[4] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[3]) + *reinterpret_cast<double*>(argv[4])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[5] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[5]) + *reinterpret_cast<double*>(argv[6])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[6] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[6])))),
                            (reinterpret_cast<char**>(argv[0]))[7] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[8] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[9] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[10] = NULL,
                            main(2, reinterpret_cast<char**>(argv[0])))),
                        // sw last
                        (reinterpret_cast<vector<pair<double,double>>*>(argv[10])->size() < 2 ?(
                            (reinterpret_cast<vector<pair<double,double>>*>(argv[10])->size() == 0 ?(
                                // 0, just delete the vector
                                delete argv[10],
                                0
                                ):(
                                // 1, print then delete
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[10]))[0].first << endl,
                                cout << (*reinterpret_cast<vector<pair<double,double>>*>(argv[10]))[0].second << endl,
                                delete argv[10],
                                0))
                            ):(
                            // > 1 number, must divide further
                            argv[0] = reinterpret_cast<char*>(new char*[11]),
                            (reinterpret_cast<char**>(argv[0]))[0] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[1] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[2] = argv[9],
                            (reinterpret_cast<char**>(argv[0]))[3] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[3])))),
                            (reinterpret_cast<char**>(argv[0]))[4] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[3]) + *reinterpret_cast<double*>(argv[4])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[5] = reinterpret_cast<char*>(new double(
                                (*reinterpret_cast<double*>(argv[5])))),
                            (reinterpret_cast<char**>(argv[0]))[6] = reinterpret_cast<char*>(new double(
                                ((*reinterpret_cast<double*>(argv[5]) + *reinterpret_cast<double*>(argv[6])) / 2))),
                            (reinterpret_cast<char**>(argv[0]))[7] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[8] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[9] = NULL,
                            (reinterpret_cast<char**>(argv[0]))[10] = NULL,
                            main(2, reinterpret_cast<char**>(argv[0])))),
                        // we know we are done with argv[1-6]
                        delete argv[1],
                        delete argv[2],
                        delete argv[3],
                        delete argv[4],
                        delete argv[5],
                        delete argv[6],
                        0);
}
