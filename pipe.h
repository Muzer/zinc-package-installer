#ifndef PIPE_H
#define PIPE_H

#include <iostream>

using namespace std;

class Pipe
{
public:
    Pipe(string cmd);

private:
    string command;
};

#endif // PIPE_H
