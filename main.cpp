 //     _____          ___                                 ___           ___                                        
 //    /  /::\        /  /\          ___                  /__/\         /  /\                        ___            
 //   /  /:/\:\      /  /:/_        /__/\                |  |::\       /  /::\                      /  /\           
 //  /  /:/  \:\    /  /:/ /\       \  \:\               |  |:|:\     /  /:/\:\    ___     ___     /  /:/           
 // /__/:/ \__\:|  /  /:/ /:/_       \  \:\            __|__|:|\:\   /  /:/~/:/   /__/\   /  /\   /  /:/            
 // \  \:\ /  /:/ /__/:/ /:/ /\  ___  \__\:\          /__/::::| \:\ /__/:/ /:/___ \  \:\ /  /:/  /  /::\            
 //  \  \:\  /:/  \  \:\/:/ /:/ /__/\ |  |:|          \  \:\~~\__\/ \  \:\/:::::/  \  \:\  /:/  /__/:/\:\           
 //   \  \:\/:/    \  \::/ /:/  \  \:\|  |:|           \  \:\        \  \::/~~~~    \  \:\/:/   \__\/  \:\          
 //    \  \::/      \  \:\/:/    \  \:\__|:|            \  \:\        \  \:\         \  \::/         \  \:\         
 //     \__\/        \  \::/      \__\::::/              \  \:\        \  \:\         \__\/           \__\/         
 //                   \__\/           ~~~~                \__\/         \__\/                                       
 //-----------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class Point {
  public:
  int x, y;

  Point() {}
  Point(int x, int y) { this->x = x; this->y = y; }
  
  friend ostream& operator<<(ostream& os, const Point& pt) {
    os << "(" << pt.x << ", " << pt.y << ")";
    return os;
  }
};
class Shape{
  // FEEL FREE TO CHANGE THE THIS CLASS
  // AS LONG AS YOU DON'T HAVE TO CHANGE THE
  // CONTENTS OF MAIN() AND 
  // PRINT_SHAPES() FUNCTIONS
  protected:
  Point _location;

  public:
  Shape() {}
  Shape(const Point& location) : _location(location) {}
  ~Shape() {}
  
  virtual void draw() {
    std::cout << "location: " << _location << endl;
  }
  
  virtual void get_info_from_user() {
    std::cout << "Enter position: ";
    std::cin >> _location.x >> _location.y;
  }
  
};
// YOU NEED TO COMPLETE THIS CLASS
class Tri : public Shape {
  protected:
  int _width, _height;

  public:
  // TODO ...
    Tri(){}
    ~Tri(){}

  void get_info_from_user() {
    std::cout << "Enter position: ";
    std::cin >> _location.x >> _location.y;
    std::cout << "Enter Width & Height ";
    std::cin >> _width >> _height;
  }
  void draw() {
    std::cout << "Triangle " << std::endl <<"location: " << _location << endl
    << "width (" << _width << ") Height (" << _height << ")" << std::endl;
  }
};


// YOU NEED TO COMPLETE THIS CLASS
class Cir : public Shape{
  protected:
  int _radius;

  public:
    Cir(){}
    ~Cir(){}

   void get_info_from_user() {
    std::cout << "Enter position: ";
    std::cin >> _location.x >> _location.y;
    std::cout << "Enter Radius: ";
    std::cin >> _radius;
  }
  void draw() {
    std::cout << "Circle " << std::endl <<"location: " << _location << endl
    << "Radius (" << _radius <<")" << std::endl;
  }
};

/////////////////////////////////////////////////
//
// DO NOT CHANGE CODE BELOW THIS LINE
//
/////////////////////////////////////////////////
#define MAX_SHAPES 10

void print_shapes(Shape** shapes, int n){
  for (int i=0; i<n; ++i){ 
    std::cout << "[" << i << "] "; shapes[i]->draw();}
  
}

int main(){
  Shape* shapes[MAX_SHAPES];

  int n = 0;
  char shape_choice;
  do {
    std::cout << "Choose a shape to add" << std::endl;
    std::cout << "\t(a) for triangle" << std::endl;
    std::cout << "\t(b) for circle" << std::endl;
    std::cout << "\t(p) to print the shapes" << std::endl;
    std::cout << "\t(0-9) to modify a shape" <<std::endl;
    std::cout << "\t(q) to exit" << std::endl;
    std::cout << ": ";
    std::cin >> shape_choice;

    if (shape_choice == 'q') break;
    
    switch(shape_choice){
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        shapes[((int) shape_choice) - 48]->get_info_from_user();
      break;
      case 'a':
        if (n >=  MAX_SHAPES) {
          std::cout << "== Cannot add any more shapes ==" << std::endl;
          continue;
        }      
        std::cout << "== You selected a triangle. ==" << std::endl;
        shapes[n] = new Tri();
        shapes[n]->get_info_from_user();
        ++n;
      break;
      case 'b':
        if (n >=  MAX_SHAPES) {
          std::cout << "== Cannot add any more shapes ==" << std::endl;
          continue;
        }
        std::cout << "== You selected a circle. ==" << std::endl;
        shapes[n] = new Cir();
        shapes[n]->get_info_from_user();
        ++n;     
      break;
      case 'p':
        print_shapes(shapes, n);
      break;
      case 'q':
      break;
      default:
        cerr << "== Invalid choice ==" << std::endl;
      break;
    }
  } while (true);

  for (int i=0; i<n; ++i) delete shapes[i];
}