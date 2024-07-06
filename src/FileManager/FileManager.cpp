#include "FileManager.h"


using namespace std; 


FileManager::FileManager(/* args */)
{
}

void FileManager::showGuild()
{
    file.open("H:\\Download\\FPT\\TaiLieu\\BaiTap\\MockTest\\src\\FileManager\\instructions.txt", std::ios::binary);

    if (!file)
    {
        cerr << "Failed to open file!" << endl;
        file.close();
    }

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    file.close();
}

FileManager::~FileManager()
{
}