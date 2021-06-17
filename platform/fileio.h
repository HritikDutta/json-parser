#pragma once

#include <string>
#include "containers/darray.h"
#include "misc/types.h"

std::string LoadFile(const std::string_view& filepath);
gn::darray<Byte> LoadBinaryFile(const std::string_view& filepath);