#include <cstdio>
#include <cstdlib>
#include "src/graph.h"

int main ()
{
    struct graph *g = new_graph();

    //read_graph_from_file(g,"input");
    generate_graph(g,100,150);

    print_graph(g);

    free_graph(g);

    //createCylinder();

    return 0;
}