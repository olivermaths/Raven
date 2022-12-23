#include "parse_commands.hpp"
Command ParseCommand(std::string_view command) noexcept {
    if (command == "create")  return Command::kCreate;
    if (command == "build")   return Command::kBuild;
    if (command == "run")     return Command::kRun;
    if (command == "test")    return Command::kTest;
    if (command == "install") return Command::kInstall;
    return Command::kUnknow;
}

CreateFlag ParseCreateFlag(std::string_view flag) noexcept {
    if (flag == "--shared-lib" || flag == "--shared" || flag == "-l") return CreateFlag::kBin;
    if (flag == "--static-lib" || flag == "--lib"    || flag == "-s") return CreateFlag::kShared;
    if (flag == "--module"     || flag == "--mod"    || flag == "-m") return CreateFlag::kModule;
    return CreateFlag::kBin; // default
}

BuildFlag ParseBuildFlag(std::string_view flag) noexcept {
    if (flag == "--debug") return BuildFlag::kDebug;
    if (flag == "--release") return BuildFlag::kRelease;
    return BuildFlag::kDebug; // default
}
