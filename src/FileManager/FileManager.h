#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <string>
#include <iostream>

class FileManager
{
private:
    std::ifstream file;
    std::string line; // Khởi tạo biến line ở đây
    bool checkFile=true; 
public:
    FileManager(/* args */);
    void recordPlayerInfo(); 
    bool isPlayerNameExists(); 
    void displayTopPlayers(); 
    ~FileManager();
    void showGuild();
};



#endif
