#include<gtkmm.h>
#include<iostream>
#include<list>

using namespace std;
using namespace Gtk;

class mainWindow : public Window
{
  public:
     mainWindow();
     
  protected: 
    void on_button_clicked();
    void addEdge(vector<int> adj[], int u, int v)
    {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    void printGraph(vector<int> adj[], int V)
    {
      cout << "valor de grafo=> " << V << endl;

      for (int v = 0; v < V; ++v)
      {
          cout << "\n Adjacency list of vertex "
              << v << "\n head ";
          for (auto x : adj[v])
            cout << "-> " << x;
          printf("\n");
      }
    }
    //void secondWindowMethod();

  private:
    Fixed fixed;
    ScrolledWindow scrolledWindow;
    Label label1;
    Label label2;
    Label label3;
    Entry e_start;
    Entry e_end;
    Button s_button;
    //Window secondWindow;
    Image *img;
};

mainWindow::mainWindow()
{
  set_title("Mapper - C++");
  set_default_size(1000, 900);
  set_border_width(10);

  add(scrolledWindow);
  scrolledWindow.add(fixed);

  label1.set_text("Distance - Maps - Weight - Time");
  fixed.add(label1);
  fixed.move(label1, 70, 10);

  label2.set_text("Start");
  fixed.add(label2);
  fixed.move(label2, 70, 60);

  label3.set_text("End");
  fixed.add(label3);
  fixed.move(label3, 70, 110);

  e_start.set_max_length(50);
  fixed.add(e_start);
  fixed.move(e_start, 110, 52);

  e_end.set_max_length(50);
  fixed.add(e_end);
  fixed.move(e_end, 110, 102);

  s_button.set_label("Search");
  s_button.signal_button_release_event().connect([&](GdkEventButton*) {
    //aqui se imprime toda la lista falta ahora que dependiendo de lo que sea se dibuje y cargar los datos en txt
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    string start = e_start.get_text();
    if (start == "asdf") {
     printGraph(adj, V);
    } else {
      cout << "false";
    }
      
      return true;
    });
  fixed.add(s_button);
  fixed.move(s_button, 150, 150);

  img = Gtk::manage(new Gtk::Image());
  img->set("costaRica.jpeg");
  fixed.add(*img);
  fixed.move(*img, 0, 200);  

  show_all();
}

// void mainWindow::secondWindowMethod()
// {
//     secondWindow.set_title("Second Window");
//     secondWindow.set_default_size(400, 300);
//     secondWindow.set_border_width(10);
//     secondWindow.show();
// }

/*************************************************/
/************************************************


void mainWindow::on_button_clicked() {
  string start = e_start.get_text();
  string end = e_end.get_text();
  if (start == "a")
  {
    cout << "a";
  } else 
  {
    cout << "error";
  }

}*/

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(argc, argv);
  mainWindow window;
  return app->run(window);

}
// g++ ##.cpp -o ## `pkg-config gtkmm-3.0 --cflags --libs`



