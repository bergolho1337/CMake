//
// Created by bergolho on 30/07/18.
//

#ifndef VTK_OUTPUT_H
#define VTK_OUTPUT_H

#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include "vtkCellArray.h"
#include "vtkPoints.h"
#include "vtkPointData.h"
#include "vtkXMLPolyDataReader.h"
#include <vtkVersion.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkAppendPolyData.h>
#include <vtkFloatArray.h>
#include <vtkCylinderSource.h>
#include <vtkMath.h>
#include <vtkProperty.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkLine.h>
#include <vtkCellData.h>
#include <vtkLine.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>
#include <vtkUnsignedCharArray.h>

#include <fstream>
#include <string>
#include <vector>

class point
{
public:
    double x, y, z;
    double s;
public:
    point () { }
    point (double x, double y, double z, double s) : x(x), y(y), z(z), s(s) { }
};

class line
{
public:
    int to;
    int from;
public:
    line () { }
    line (int to, int from) : to(to), from(from) { }
};

class vtk_graph_data
{
private:
    std::vector<point> points;
    std::vector<line> lines;
public:
    vtk_graph_data (int argc, char *argv[]);
    void write_to_vtk ();
    void visualize ();
    void print ();
};

void create_cylinder (char *argv[]);
void convert_vtk_file (char *argv[]);



#endif