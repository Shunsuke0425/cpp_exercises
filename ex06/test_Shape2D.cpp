// COMPLETE include the necessary headers here
#include "Shape2D.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Point2D.h"
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
  std::cout << "success!" << std::endl;
  Shape2D *clone_Shape;
  clone_Shape = create->clone();
  std::cout << "success!" << std::endl;
  std::cout << "name is " << clone_Shape->get_name() << std::endl
  << "radius is " << clone_Shape->radius << std::endl;
  std::cout << "--------------------------------------------------------" << std::endl
            << "Which do you want output Rectangle or Circle?" << std::endl
            << "If you select Rectangle, put the ""Rectangle"" then. " << std::endl
            << "Therefore, you select Circle, put the ""Circle"" then. " << std::endl
            << "--------------------------------------------------------" << std::endl;
  std::string select_Shape;
  Shape2D *test_Shape;
  Rectangle pre_rectangle;
  Circle pre_circle;
  while(1){
      std::cout <<  ">>>";
      std::cin >> select_Shape;
      if(select_Shape == "Rectangle"){
      test_Shape = &pre_rectangle;
      break;
    }else if(select_Shape == "Circle"){
      test_Shape = &pre_circle;
      break;
    }else{
      std::cout << "you type the error!" << std::endl
      << select_Shape << " cannot match." << std::endl
      << "retry!" << std::endl;
    }
  }
  std::cout << "Shape name is : " << test_Shape->get_name() << std::endl;
  float size_h, size_w, size_corner, size_r, size_c;
  if(select_Shape == "Rectangle"){
    std::cout << "Put Rectangle status!" << std::endl
    << "height >>> ";
    std::cin >> size_h;
    std::cout << "width >>> ";
    std::cin >> size_w;
    std::cout << "left_corner >>> ";
    std::cin >> size_corner;
    test_Shape->Set(size_h,size_w,size_corner);
  }else if(select_Shape == "Circle"){
    std::cout << "Put Circle status!" << std::endl
    << "radius >>> ";
    std::cin >> size_r;
    std::cout << "center >>> ";
    std::cin >> size_c;
    test_Shape->Set(size_r,size_c);
  }
  std::cout << "Area : " << test_Shape->compute_area() << std::endl;
 // COMPLETE 
  // Add tests to test your implementation of the class Polygon.
}