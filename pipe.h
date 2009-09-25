#ifndef PIPE_H
#define PIPE_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

class Pipe
{
public:
    Pipe(string cmd);
    void write_string(string msg);
    string read_string();
    bool possible_to_read();
    void close();

private:
    string command;
    FILE* pipe;
};

#endif // PIPE_H
