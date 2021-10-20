#include <gtkmm.h>
#include <iostream>
class AboutWindow : public Gtk::Window
{
public:
    AboutWindow();
    ~AboutWindow();

protected:
    Gtk::Label lbl_;
};

AboutWindow::AboutWindow()
{
    this->set_default_size(100, 100);
    this->set_title("About");

    lbl_.set_label("About label");
    this->add(lbl_);

    this->show_all_children();
}

AboutWindow::~AboutWindow()
{

}

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    virtual ~MainWindow();

protected:
    void onButtonClicked();
    void aboutWinClose();

    Gtk::Button button_;
    Gtk::Label lbl_;
    Gtk::Box box_;
    Gtk::AboutWindow* aboutw_;
};

MainWindow::MainWindow()
{
    this->set_default_size(100, 100);
    box_.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->add(box_);
    box_.pack_start(lbl_);

    lbl_.set_label("a test");

    button_.set_label("Open About Window");
    box_.pack_end(button_);

    button_.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::onButtonClicked));

    aboutw_ = 0;

    this->show_all_children();
}

MainWindow::~MainWindow()
{

}

void MainWindow::onButtonClicked()
{
    if(aboutw_ != 0)
        return;

    aboutw_ = new AboutWindow;
    aboutw_->signal_hide().connect(sigc::mem_fun(*this, &MainWindow::aboutWinClose));
    aboutw_->show();
}

void MainWindow::aboutWinClose()
{
    aboutw_ = 0;
}