// STANDARD C++ INCLUDES
#include<iostream>
#include<fstream>

// LOCAL INCLUDES
#include<gcode/parser.hh>

int main(int argc, char** argv){
    std::cout << "########  GCODE_PARSER  ########" << std::endl;

    gcode::Program program;
    program.parseFile("../gcode/test01.gcode");
    program.print();
    return 0;
}
