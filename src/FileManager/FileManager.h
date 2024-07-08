#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <tchar.h>
#include <sstream>

struct Record
{
    int firstPlayer;
    int turn;
    char currentPlayer;
    int x, y;
    std::vector<std::vector<char>> matrix;

    Record() : matrix(10, std::vector<char>(10, ' ')) {}
};

struct PlayerGame
{
    std::string name;
    int win;
    int lose;
    int draw;

    bool operator<(const PlayerGame &other) const
    {
        return win > other.win;
    }
};

class FileManager
{
private:
    std::ifstream file;
    std::string line;
    bool checkFile = true;
    std::string pathFile = "H:\\Download\\FPT\\TaiLieu\\BaiTap\\Caro\\Status\\";
    std::vector<std::string> listFile;

public:
    FileManager(/* args */);
    void recordPlayerInfo(std::string name, int win, int lose, int draw);
    void displayTopPlayers();
    void createFolder(std::string name);
    void createFile(std::string name, int win, int lose, int draw, int firstPlayer, int number, int turn, int x, int y, char currentPlayer, std::vector<std::vector<char>> vec);
    void updateFileGame(std::string name, int firstPlayer, int number, int turn, int x, int y, char currentPlayer, std::vector<std::vector<char>> vec);
    void showInformation();
    void removeAllFilesAndFolders(const std::string& directoryPath);
    void showMatch();
    int getValue(std ::string name, std::string findLine);
    void readPlayerInfo(const std::string &filePath, std::vector<PlayerGame> &players);
    void getAllPlayerInfo(const std::string &directory, std::vector<PlayerGame> &players);
    bool readRecord(std::ifstream &inputFile, Record &record);
    std::vector<std::string> listDirectoriesInDirectory(const std::string &directoryPath);
    bool checkFolderExist(std::string name);
    bool checkFileExist(std::string name);
    ~FileManager();
    void showGuild();
};

#endif
