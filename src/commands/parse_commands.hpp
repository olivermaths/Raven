#include "Core.hpp"
enum class Command {
    kCreate,
    kBuild,
    kRun,
    kTest,
    kInstall,
    kUnknow
};

enum class CreateFlag {
    kBin,
    kLib,
    kShared,
    kModule,
};

enum class BuildFlag {
    kDebug,
    kRelease
};

Command ParseCommand(std::string_view command) noexcept;
CreateFlag ParseCreateFlag(std::string_view flag) noexcept;
BuildFlag ParseBuildFlag(std::string_view flag) noexcept;