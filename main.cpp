#include <gtkmm.h>
#include <iostream>

using namespace std;
using namespace Gtk;

class mainWindow : public Window
{
  public:
     mainWindow();
     
  protected: 
    void on_button_clicked();
    void secondWindowMethod();

  private:
    Fixed fixed;
    ScrolledWindow scrolledWindow;
    Label label1;
    Label label2;
    Label label3;
    Entry e_start;
    Entry e_end;
    Button s_button;
    Window secondWindow;
};

mainWindow::mainWindow()
{
  set_title("Mapper - C++");
  set_default_size(400, 300);
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

  s_button.signal_clicked().connect(sigc::mem_fun(*this, &mainWindow::on_button_clicked));
  s_button.set_label("Search");
  fixed.add(s_button);
  fixed.move(s_button, 150, 150);

  show_all();
}

void mainWindow::secondWindowMethod()
{
    secondWindow.set_title("Second Window");
    secondWindow.set_default_size(400, 300);
    secondWindow.set_border_width(10);
    secondWindow.show();
}

void mainWindow::on_button_clicked() {
  string start = e_start.get_text();
  string end = e_end.get_text();

  if (start == "asdf")
  {
    secondWindowMethod();

  } else 
  {
    cout << "error";
  }

  // if (start == "asdf") {
  //   cout << start  << endl;
  //   cout << end  << endl;
  // }
}



int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create(argc, argv);
  mainWindow window;
  return app->run(window);

}
// g++ ##.cpp -o ## `pkg-config gtkmm-3.0 --cflags --libs`



