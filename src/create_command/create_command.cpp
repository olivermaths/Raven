#include "create_command.hpp"
#include <filesystem>
#include <iostream>
#include <string_view>

using std::filesystem::create_directory;

bool create_file(std::string_view content, std::string_view path) noexcept;





bool CreateProjectDirectory(std::string_view project_name) {
        
        try {
                create_directory(project_name);
                create_directory(std::filesystem::path(project_name) /"src");
                create_directory(std::filesystem::path(project_name) / "test");
                create_directory(std::filesystem::path(project_name) / "build");
                create_directory(std::filesystem::path(project_name) / "include");

        } catch (const std::filesystem::filesystem_error &ex) {
                std::cerr << "Error: Failed to create project directory or subdirectories '" << project_name << "': " << ex.what() << '\n';
                return false;
        }

        try {
                constexpr std::string_view content =
                                        "#include <iostream>\n"
                                        "int main()\n"
                                        "{\n"
                                        "\tstd::cout << \"Hello, World!\" << std::endl;\n"
                                        "\treturn 0;\n"
                                        "}\n";

                
                std::string path = std::filesystem::path(project_name) / "src/main.cc";
                
                bool result = create_file(content, path);
                
                if (!result) {
                        std::cerr << "Error: Failed to create 'main.cc' file: " << '\n';
                        return false;
                }

               constexpr std::string_view test_content =
                        "#include <cassert>\n"
                        "#include <string>\n"
                        "#include <string_view>\n"
                        "\n"
                        "std::string reverse(std::string_view str)"
                        "{\n"
                        "        std::string result;\n"
                        "        for (int i = str.length() - 1; i >= 0; --i) {\n"
                        "                result += str[i];\n"
                        "        }\n"
                        "        return result;\n"
                        "}\n"
                        "int main() {\n"
                        "        std::string_view input = \"Hello, world!\";\n"
                        "        std::string_view expected_output = \"!dlrow ,olleH\";\n"
                        "        std::string result = reverse(input);\n"
                        "        assert(result == expected_output);\n"
                        "        return 0;\n"
                        "}";

                path = std::filesystem::path(project_name) / "test/main_test.cc";
                result = create_file(test_content, path);
                
                if (!result) {
                        std::cerr << "Error: Failed to create 'main_test.cc' file: " << '\n';
                        return false;
                }


        } catch (const std::filesystem::filesystem_error &ex) {
                std::cerr << "Error: Failed to create a file : " << ex.what() << '\n';
                return false;
        }

        return true;
}



bool CreateModuleDir(std::string_view ModuleName){
        
        try {
                int result = true;
                create_directory(ModuleName);
               
                std::string filename = ModuleName.data();
                
                filename.append("/");
                long it = ModuleName.find_last_of("/");
                auto name = ModuleName.substr(it + 1, ModuleName.size()).data();
                filename.append(name);
                filename.append(".cc");
                
                std::string content = "#include \"";
                content.append(name);
                content.append(".hpp\"");

                result = create_file(content, filename);
                
                if(!result) goto failed_to_create_file;
                
                filename.replace(filename.size() - 2, 3, "hpp");
                
                result = create_file("#pragma once", filename);
                
                if(!result) goto failed_to_create_file;
                
                return true;

        } catch (const std::filesystem::filesystem_error &ex) {
                std::cerr << "Error: Failed to create module directory '" << ModuleName << "': " << ex.what() << '\n';
                return false;
        }
        return true;

failed_to_create_file:
        std::cerr << "Error: Failed to create the module files\n";
        return false;

}





bool CreateStaticLib(std::string_view lib_name){return false;}
bool CreateSharedLib(std::string_view lib_name){return false;}






bool create_file(std::string_view content, std::string_view path) noexcept 
{
        std::ofstream file(path.data());
        if (file.is_open()) {
                  file << content;
                  file.close();
                  return true;
        }
        return false;
}


