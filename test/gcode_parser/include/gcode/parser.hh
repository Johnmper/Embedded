#ifndef __GCODE_PARSER_PARSER_HEADER
#define __GCODE_PARSER_PARSER_HEADER

#include"types.hh"

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<string>
#include<vector>

namespace gcode{

    bool is_address(const char& c);

    class Program{
    public:

        Program(){};
        ~Program(){};

        void print();

        int parse(const char* buf, std::size_t size);
        int parseFile(const char* file_path);
        int parseCommandInt(const char* buf, std::size_t kk1, std::size_t kk2);
        int parseCommandFloat(const char* buf, std::size_t kk1, std::size_t kk2);
    private:
        std::vector<Command> code;
    };

}



#endif //__GCODE_PARSER_PARSER_HEADER
