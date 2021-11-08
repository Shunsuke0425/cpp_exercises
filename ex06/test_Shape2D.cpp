// COMPLETE include the necessary headers here
#include "Shape2D.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

int main(void) {
  // COMPLETE 
  // Write tests to test your implementation of the classes Rectangle and Circle. 
  /////////////TEST////////////////////
  //Create TEST//
  std::cout << "TEST the create() :" << std::endl;
  Shape2D *create;
  Rectangle r;
  Circle c;
  create = &r;
  create->create();
  std::cout << "name is " << create->get_name() <<std::endl;
  std::cout << "height is " << create->height << std::endl
  << "width is " << create->width << std::endl;
  //Clone TEST//
  std::cout << "TEST the clone() :" << std::endl;
  create = &c;
  Shape2D *clone_Shape;
  clone_Shape = create->clone();
  std::cout << "name is " << clone_Shape->get_name() << std::endl
  << "radius is " << clone_Shape->radius << std::endl;

  ///TEST each shape
  std::cout << "--------------------------------------------------------" << std::endl
            << "Which do you want output Rectangle or Circle?" << std::endl
            << "If you select Rectangle, put the ""Rectangle"" then. " << std::endl
            << "Therefore, you select Circle, put the ""Circle"" then. " << std::endl
            << "--------------------------------------------------------" << std::endl;
  Point2D point;
  Shape2D *test_Shape;
  std::string select_Shape;
  float size_h, size_w, size_cornerX, size_cornerY, size_r, size_centerX, size_centerY;

  ///Select phaze
  while(1){
    std::cout <<  ">>>";
    std::cin >> select_Shape;
    if(select_Shape == "Rectangle"){
      std::cout << "Put Rectangle status!" << std::endl
      << "height >>> ";
      std::cin >> size_h;
      std::cout << "width >>> ";
      std::cin >> size_w;
      std::cout << "left_corner's x point >>> ";
      std::cin >> size_cornerX;
      std::cout << "left_corner's y point >>> ";
      std::cin >> size_cornerY;
      break;
    }else if(select_Shape == "Circle"){
      std::cout << "Put Circle status!" << std::endl
      << "radius >>> ";
      std::cin >> size_r;
      std::cout << "center's x point >>> ";
      std::cin >> size_centerX;
      std::cout << "center's y point >>> ";
      std::cin >> size_centerY;
      break;
    }else{
      std::cout << "you type the error!" << std::endl
      << select_Shape << " cannot match." << std::endl
      << "retry!" << std::endl;
    }
  }
  if(select_Shape == "Circle"){
    Circle pre_circle(point, size_r);
    test_Shape = &pre_circle;
  }else if(select_Shape == "Rectangle"){
    Rectangle pre_rectangle(point, size_h, size_w);
    test_Shape = &pre_rectangle;
  }else;
  std::cout << "Area : " << test_Shape->compute_area() << std::endl;
 // COMPLETE 
  // Add tests to test your implementation of the class Polygon.
}