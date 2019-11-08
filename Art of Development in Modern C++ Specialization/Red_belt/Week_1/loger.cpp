//
//  loger.cpp
//  coursera
//
//  Created by Денис Домашевич on 04/30/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <ostream>

class Logger {
public:
    explicit Logger(std::ostream& output_stream)
        :os(output_stream) {}

    void SetLogLine(bool value) { log_line = value; }
    void SetLogFile(bool value) { log_file = value; }

    void Log(const std::string& message) {
        if(log_file && log_line) {
            os << file << ':' << line << ' ';
        } else if(log_file) {
            os << file << ' ';
        } else if(log_line) {
            os << "Line " << line << ' ';
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

void TestLog() {
    std::ostringstream logs;
    Logger l(logs);
    LOG(l, "hello");

    l.SetLogFile(true);
    LOG(l, "hello");

    l.SetLogLine(true);
    LOG(l, "hello");

    l.SetLogFile(false);
    LOG(l, "hello");

    std::string expected = "hello\n";
    expected += "logger.cpp hello\n";
    expected += "logger.cpp:10 hello\n";
    expected += "Line 13 hello\n";

    std::cout << logs.str() << std::endl;
    std::cout << std::endl;
    std::cout << expected << std::endl;
}

int main() {
    TestLog();
}
