#include "vtk_output.hpp"

vtk_graph_data::vtk_graph_data (int argc, char *argv[])
{
  int V, E;
  point p;
  line l;

  ifstream in(argv[2]);
  
  in >> V >> E;

  for (int i = 0; i < V; i++)
  {
    in >> p.x >> p.y >> p.z;
    points.push_back(p);
  }
    
  for (int i = 0; i < E; i++)
  {
    in >> l.from >> l.to;
    lines.push_back(l);
  }

  in.close();
}

void vtk_graph_data::print ()
{
  cout << "Points:" << endl;
  for (size_t i = 0; i < points.size(); i++)
    cout << points[i].x << " " << points[i].y << " " << points[i].z << endl;
  
  cout << endl;
  cout << "Lines:" << endl;
  for (size_t i = 0; i < lines.size(); i++)
    cout << lines[i].from << " " << lines[i].to << endl;
}

void vtk_graph_data::visualize ()
{
  //string filename("output.vtp");
  
  vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
  // Insert the points
  vtkSmartPointer<vtkPoints> vtk_points = vtkSmartPointer<vtkPoints>::New();
  for (size_t i = 0; i < points.size(); i++)
      vtk_points->InsertNextPoint(points[i].x,points[i].y,points[i].z);
  polydata->SetPoints(vtk_points);

  // Insert the lines using the edges of the graph
    vtkSmartPointer<vtkCellArray> vtk_lines = vtkSmartPointer<vtkCellArray>::New();
    for (size_t j = 0; j < lines.size(); j++)
    {
        vtkSmartPointer<vtkLine> vtk_line = vtkSmartPointer<vtkLine>::New();
        vtk_line->GetPointIds()->SetId(0,lines[j].from);  
        vtk_line->GetPointIds()->SetId(1,lines[j].to);
        vtk_lines->InsertNextCell(vtk_line);
    }
    polydata->SetLines(vtk_lines);

    // Create a mapper and an actor
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polydata);

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    //actor->GetProperty()->SetLineWidth(4);

    //Create a renderer, render window, and interactor
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  // Add the actor to the scene
  renderer->AddActor(actor);

  renderWindow->SetWindowName("Graph");
  renderWindow->Render();
  renderWindowInteractor->Start();

}

void vtk_graph_data::write_to_vtk ()
{
  std::string filename("output.vtp");
  
  vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
  // Insert the points
  vtkSmartPointer<vtkPoints> vtk_points = vtkSmartPointer<vtkPoints>::New();
  for (size_t i = 0; i < points.size(); i++)
      vtk_points->InsertNextPoint(points[i].x,points[i].y,points[i].z);
  polydata->SetPoints(vtk_points);

  // Insert the lines using the edges of the graph
  vtkSmartPointer<vtkCellArray> vtk_lines = vtkSmartPointer<vtkCellArray>::New();
  for (size_t j = 0; j < lines.size(); j++)
  {
      vtkSmartPointer<vtkLine> vtk_line = vtkSmartPointer<vtkLine>::New();
      vtk_line->GetPointIds()->SetId(0,lines[j].from);  
      vtk_line->GetPointIds()->SetId(1,lines[j].to);
      vtk_lines->InsertNextCell(vtk_line);
  }
  polydata->SetLines(vtk_lines);

  // Write the polydata to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetFileName(filename.c_str());
  writer->SetInputData(polydata);
  writer->Write();

  cout << "[+] File saved :> \"output.vtp\"" << endl;
}

void create_cylinder (char *argv[])
{
    // Create a sphere
  vtkSmartPointer<vtkCylinderSource> cylinderSource =
    vtkSmartPointer<vtkCylinderSource>::New();
  cylinderSource->SetCenter(0.0, 0.0, 0.0);
  cylinderSource->SetRadius(5.0);
  cylinderSource->SetHeight(7.0);
  cylinderSource->SetResolution(100);
  cylinderSource->Update();

  // Color the points of the cylinder with the same scalar of the first point
  int numPtsCylinder = cylinderSource->GetOutput()->GetPoints()->GetNumberOfPoints();
  vtkSmartPointer<vtkFloatArray> scalars =
      vtkSmartPointer<vtkFloatArray>::New();
  scalars->SetNumberOfValues( numPtsCylinder );
  for( int j = 0; j < numPtsCylinder; j++ )
      scalars->SetValue(j,j*0.0025);
  cylinderSource->GetOutput()->GetPointData()->SetScalars(scalars);
  cylinderSource->Update();
 
  // Create a mapper and actor
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(cylinderSource->GetOutputPort());
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  //Create a renderer, render window, and interactor
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  // Add the actor to the scene
  renderer->AddActor(actor);
  renderer->SetBackground(.1, .3,.2); // Background color dark green
 
  // Render and interact
  renderWindow->SetWindowName(argv[0]);
  renderWindow->Render();
  renderWindowInteractor->Start();
}

void convert_vtk_file (char *argv[])
{
  int V, E;
  point p;
  line l;
  std::string str;
  std::vector<point> points;
  std::vector<line> lines;

  ifstream in(argv[2]);
  while (in >> str)
    if (str == "POINTS") break;
  in >> V >> str;
  for (int i = 0; i < V; i++)
  {
    in >> p.x >> p.y >> p.z;
    points.push_back(p);
  }

  while (in >> str)
    if (str == "LINES") break;
  in >> E >> str;
  for (int i = 0; i < E; i++)
  {
    in >> str >> l.from >> l.to;
    lines.push_back(l);
  }  

  in.close();

  ofstream out("converted.txt");
  
  out << V << " " << E << endl;
  for (int i = 0; i < V; i++)
    out << points[i].x << " " << points[i].y << " " << points[i].z << endl;
  for (int i = 0; i < E; i++)
    out << lines[i].from << " " << lines[i].to << endl;
  
  out.close();
}