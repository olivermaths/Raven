#pragma once
#ifndef __RAVEN__ 
#define __RAVEN__
        #include "Core.hpp"
        #include "commands/parse_commands.hpp"
        #include "create_command/create_command.hpp"

inline void PrintUsage()
{
    std::string_view usage =
                        "Usage: command [COMMAND] [FLAGS]\n\n"
                        "Common commands:\n"
                        "  raven create <project_name>\n"
                        "\tCreate a new project in the specified directory\n\n"
                        "Commands:\n"
                        "  create        Create a new project\n"
                        "                -l, --lib    Create a static library\n"
                        "                -s  --shared create a shared library\n"
                        "                -b, --bin    Create a binary        \n"
                        "                -m, --module Create a module directory\n  \n"
                        "  build         Build a project\n"
                        "                -r, --release   Build for release\n"
                        "                -d, --debug     Build with debugging symbols\n\n"
                        "  run           Run a project\n"
                        "  test          Test a project\n"
                        "  install       Install a project\n"
                        "\n"
                        "Options:\n"
                        "  -h, --help    Show this help message\n";
    std::puts(usage.data());
}
#endif