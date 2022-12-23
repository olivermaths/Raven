#if defined (__linux__) && defined (__x86_64__) && (__cplusplus >= 202002L)
#include "Raven.hpp"


bool parseCommandLineArgs(int argc, const char** argv) {

    auto command = ParseCommand(argv[1]);
    if(command == Command::kCreate){
        if(argc < 3) goto print_usage;
        if(std::string_view(argv[2]).starts_with("-") && argc < 4) goto print_usage;

        if(std::string_view(argv[2]).starts_with("-")){
            auto create_flag = ParseCreateFlag(argv[2]);
            std::string_view project_name = argv[3];

            if(create_flag == CreateFlag::kModule){
                return CreateModuleDir(project_name);
            }
            goto print_usage;
        }
        auto project_name = argv[2];
        return  CreateProjectDirectory(project_name);
    }

    if(command == Command::kBuild){}
    if(command == Command::kRun){}
    if(command == Command::kTest){}
    if(command == Command::kInstall){}


print_usage:
    PrintUsage();
    return false;
}


int main(int argc, const char* argv[]) {
 
    if (argc < 2) {
        PrintUsage();
        return 1;
    }
    if(!parseCommandLineArgs(argc, argv)){
        return 1;
    }
    return 0;
}

#else

    @ Error Raven only supports POSIX-compliant operating system, x86_64 architecture, and C++20 or newer
    @ Raven does not guarante to work and keep working in others operating systems

#endif