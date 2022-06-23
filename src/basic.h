#pragma once
#pragma warning (disable : 4005)

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "linmath.h"
#include "stb/stb_image.h"
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <filesystem>


#include "utils/filesystem.h"
#include "utils/errorhandler.h"
#include "utils/vector2.h"
#include "utils/vector3.h"
#include "utils/vector4.h"
#include "utils/color.h"
#include "utils/utilString.h"
#include "utils/math.h"





#define DEBUG 1

typedef unsigned int uint;
typedef void (*Function) ();
typedef std::map<std::string, int> Map;
typedef std::pair<std::string, int> MapPair;
namespace fs = std::filesystem;
