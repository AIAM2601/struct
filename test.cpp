#include <gtkmm.h>
#include <iostream>

class MainWindow : public Gtk::Window  
 {  
   public:  
     MainWindow();  
     virtual ~MainWindow();  
   protected:  
     Gtk::Box m_Vbox;  
     DrawImage myImage
 };  

MainWindow::MainWindow() : 
m_Vbox(Gtk::ORIENTATION_VERTICAL)
{  
   set_title("Display Image");  
   set_size_request(400,400);  
 }  
   
 MainWindow::~MainWindow()  
 {  
   //dtor   
 }  

  class DrawImage : public Gtk::DrawingArea  
 {  
   public:  
     DrawImage(const std::string& filename);  
     virtual ~DrawImage();  
   protected:  
     Glib::RefPtr<Gdk::Pixbuf> myImage;  
     bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;  
 };  

 DrawImage::DrawImage(const std::string& filename)  
 {  
   try{  
     myImage = Gdk::Pixbuf::create_from_file(filename);  
   }catch(...)  
   {  
     std::cerr<<"An error occured while loading the image file."<<std::endl;  
   }  
   
   if(myImage)  
     set_size_request(myImage->get_width(), myImage->get_height());  
   set_halign(Gtk::ALIGN_CENTER);  
   set_valign(Gtk::ALIGN_CENTER);  
 }  
   
 DrawImage::~DrawImage()  
 {  
   //dtor  
 }  
   
 bool DrawImage::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)  
 {  
   if(!myImage)  
     return false;  
   
   Gtk::Allocation allocation = get_allocation();  
   const int height = allocation.get_height();  
   const int width = allocation.get_width();  
   
   Gdk::Cairo::set_source_pixbuf(cr, myImage, width-myImage->get_width(), height-myImage->get_height());  
   
   cr->paint();  
   return true;  
 }  
 
MainWindow::MainWindow():
m_Vbox(Gtk::ORIENTATION_VERTICAL), myImage("Bimage.png")
{
    set_title("Display Image");
    set_size_request(400,400);
   
    add(m_Vbox);  
   
    m_Vbox.pack_start(myImage, Gtk::PACK_SHRINK);  
   
    show_all_children();
}  