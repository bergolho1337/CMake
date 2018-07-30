// This program reads a graph stored on a input file
// and output the visualization of its structure using VTK

#include <iostream>
#include "vtk_output.hpp"

using namespace std;

int main (int argc, char *argv[])
{
    if (argc-1 != 2)
    {
        cerr << "=============================================================================================" << endl;
        cerr << "Usage:> " << argv[0] << " --<option> <input>" << endl;
        cerr << "<option> = Action performed by the program" << endl;
        cerr << "\tconvert = Convert a VTK file to a graph format file" << endl;
        cerr << "\tvisualize = Open a VTK window to visualize the structure of the input graph" << endl;
        cerr << "\twrite = Write the input graph to a output VTP file" << endl;
        cerr << "=============================================================================================" << endl;
        exit(EXIT_FAILURE);
    }

    string option = argv[1];
    if (option == "--convert")
        convert_vtk_file(argv);
    else if (option == "--visualize")
    {
        vtk_graph_data *graph = new vtk_graph_data(argc,argv);
        graph->visualize();
        delete graph;
    }
    else if (option == "--write")
    {
        vtk_graph_data *graph = new vtk_graph_data(argc,argv);
        graph->write_to_vtk();
        delete graph;
    }
    else
    {
        cerr << "[ERROR] Invalid option" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}