#include "fileio.h"

#include <cstdint>
#include <stdio.h>
#include <fstream>
#include <string>
#include "containers/darray.h"
#include "misc/gn_assert.h"

std::string LoadFile(const std::string_view& filepath)
{
    FILE* file = fopen(filepath.data(), "rb");
    ASSERT(file != nullptr);

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*) malloc((length + 1) * sizeof(char));
    fread(buffer, sizeof(char), length, file);
    buffer[length] = '\0';

    std::string contents = buffer;
    free(buffer);

    fclose(file);
    return std::move(contents);
}