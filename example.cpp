#include <iostream>
#include <ctime>
#include "parser/parser.h"
#include "parser/json.h"
#include "platform/fileio.h"

int main(int argc, char* argv[])
{
    std::string json = LoadFile("test-files/example_3.json");

    json::Document document;
    if (json::ParseFile(json, document))
    {
        auto& arr = document.start().array();

        for (auto& val : arr)
            std::cout << val["WHO"].string() << std::endl;
    }
}