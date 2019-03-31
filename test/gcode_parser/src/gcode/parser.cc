#include<gcode/parser.hh>


namespace gcode{

    bool is_address(const char& c){
        switch(c){
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                return true;
            default:
                break;
        }
        return false;
    }
    void Program::print(){

        for(auto& it : code){
            it.print();
        }
    }

    int Program::parse(const char* buf, std::size_t size){
        // TODO: Actual parsing
        //  Start by parsing lines/blocks
        //  Then interpretation of command ID
        //  Call Specific Command Object contructor
        bool is_float = false;
        for(std::size_t kk1=0; kk1 < size; ++kk1){
            if(buf[kk1]=='('){
                // Found comment, search for its end
                for(std::size_t kk2=kk1+1; kk2 < size ; ++kk2){
                    if(buf[kk2]==')'){
                        // Found end of comment, update position
                        kk1 = kk2;
                        break;
                    }
                }
            }
            else if(is_address(buf[kk1])){
                // Found valid address, search for end of address and check if address key is float or int
                for(std::size_t kk2=kk1+1; kk2 < size ; ++kk2){
                    if(buf[kk2]=='.'){
                        is_float = true;
                    }
                    else if(buf[kk2]==' ' || buf[kk2]=='\n' || buf[kk2]=='('){
                        if(is_float){
                            parseCommandFloat(buf,kk1,kk2);
                            is_float = false;
                        }
                        else{
                            parseCommandInt(buf,kk1,kk2);
                        }
                        kk1=kk2-1;
                        break;
                    }
                }
            }
        }

        return 0;
    }

    /// @brief      Parses a complete gcode file
    int Program::parseFile(const char* file_path){
        std::ifstream file_code(file_path);
        if(!file_code.is_open()){
            std::cerr << "Failed to open [test01.gcode] file." << std::endl;
            return -1;
        }

        std::stringstream str;
        str<<file_code.rdbuf();
        parse(str.str().c_str(),str.str().size());

        return 0;
    }

    int Program::parseCommandInt(const char* buf, std::size_t kk1, std::size_t kk2){

        if(kk2 < kk1){
            std::cerr << "Error" << std::endl;
            return -1;
        }
        std::string tmp(buf+kk1+1,kk2-kk1-1);
        code.push_back(Command(buf[kk1],std::stoi(tmp)));

        return 0;
    }

    int Program::parseCommandFloat(const char* buf, std::size_t kk1, std::size_t kk2){

        if(kk2 < kk1){
            std::cerr << "Error" << std::endl;
            return -1;
        }
        std::string tmp(buf+kk1+1,kk2-kk1-1);
        code.push_back(Command(buf[kk1],std::stof(tmp)));

        return 0;
    }
}
