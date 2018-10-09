//
//  loger.cpp
//  coursera
//
//  Created by Денис Домашевич on 10/9/18.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <ostream>

class Loger {
public:
    explicit Loger(std::ostream& output_stream)
        :os(output_stream) {}
    
    void SetLogLine(bool value) { log_line = value; }
    void SetLogFile(bool value) { log_file = value; }
    
    void Log(const std::string& message) {
        if(log_file && log_line) {
            os << file << ':' << line << ' ';
        } else if(log_file) {
            os << file << ' ';
        } else if(log_line) {
            os << "Line" << line << ' ';
        }
        os << message << '\n';
    }
    
    void SetFile(const std::string& file_name) {
        file = file_name;
    }
    
    void SetLine(const int64_t line_number) {
        line = line_number;
    }
    
private:
    int64_t line;
    std::ostream& os;
    std::string file;
    bool log_line = false;
    bool log_file = false;
};

#define LOG(logger, message)        \
    logger.SetFile(__FILE__);       \
    logger.SetLine(__LINE__);       \
    logger.Log(message);

int main(int argc, const char * argv[]) {
   
    
    
    return 0;
}

