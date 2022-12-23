#pragma once
#ifndef __RAVEN_CREATE_COMMMNAD_IMPL__
#define __RAVEN_CREATE_COMMMNAD_IMPL__
#include "Core.hpp"
bool CreateProjectDirectory(std::string_view project_name);
bool CreateModuleDir(std::string_view ModuleName);

#endif