#include "pipe.h"

Pipe::Pipe(string cmd)
{
    command = cmd;
    pipe = popen(cmd.c_str(), "w");
    if (!pipe)
    {
        cout << "Cannot open pipe." << endl;
        exit(1);
    }
}

string Pipe::read_string()
{
    char buffer[1000];
    string result = "";
    while (!feof(pipe))
    {
        if (fgets(buffer, sizeof(buffer), pipe) != NULL)
                result += buffer;
    }
    return result;
}

bool Pipe::possible_to_read()
{
    return feof(pipe);
}

void Pipe::close()
{
    pclose(pipe);
}
