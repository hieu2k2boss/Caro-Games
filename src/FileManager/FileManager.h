#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>
#include <vector>
#include <windows.h>
#include <algorithm>


class FileManager
{
private:
    std::ifstream file;
    std::string line;
    bool checkFile = true;
    std::string pathFile = "H:\\Download\\FPT\\TaiLieu\\BaiTap\\Caro\\Status\\" ; 
public:
    FileManager(/* args */);
    void recordPlayerInfo(std::string name, int win, int lose, int draw);
    void displayTopPlayers();
    void createFolder(std::string name);
    void createFile(std::string name, int win, int lose, int draw, int firstPlayer ,int number,int turn, int x, int y, char currentPlayer ,std::vector<std::vector<char>> vec);
    void updateFileGame(std::string name, int firstPlayer ,int number, int turn, int x, int y,char currentPlayer , std::vector<std::vector<char>> vec);
    void showInformation();
    std::vector<std::string> listDirectoriesInDirectory(const std::string& directoryPath);
    bool checkFolderExist(std::string name); 
    bool checkFileExist(std::string name); 
    ~FileManager();
    void showGuild();
};

#endif
