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

void FileManager::createFolder(std::string name)
{
    if (!checkFolderExist(name))
    {
        std::string directory_name = pathFile + name;

        if (CreateDirectory(directory_name.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError())
        {
            std::cout << "Successfull !!!" << std::endl;
        }
        else
        {
            std::cerr << "Don't create folder ! \"" << directory_name << "\"." << std::endl;
        }
    }
}

void FileManager::createFile(std::string name, int win, int lose, int draw, int number, int firstPlayer, int turn, int x, int y, char currentPlayer, std::vector<std::vector<char>> vec)
{

    std::string filePlayer = pathFile + "\\" + name + "\\informationPlayer.txt";
    std::ofstream outfile(filePlayer);

    if (outfile.is_open())
    {
        outfile << "Name player: " + name + "\n";
        outfile << "Win: " + to_string(win) + "\n";
        outfile << "Lose: " + to_string(lose) + "\n";
        outfile << "Draw: " + to_string(draw) + "\n";
        outfile.close();
    }
    else
    {
        std::cerr << "Don't create file \"" << filePlayer << "\"." << std::endl;
    }

    std::string fileStatusGame = pathFile + "\\" + name + "\\StatusGame" + to_string(number) + ".txt";
    std::ofstream outfileGame(fileStatusGame);

    if (outfileGame.is_open())
    {
        outfileGame << "firstPlayer: " + to_string(firstPlayer) + "\n"; // Nếu là 1: X     0: O
        outfileGame << "Turn: " + to_string(turn) + "\n";
        outfileGame << "Current Player: " + to_string(currentPlayer) + "\n";
        outfileGame << "x,y " + to_string(x) + " " + to_string(y) + "\n";
        for (const auto &row : vec)
        {
            for (const auto &elem : row)
            {
                outfileGame << elem << " ";
            }
            outfileGame << "\n";
        }
        outfileGame << "\n";
        outfileGame.close();
    }
    else
    {
        std::cerr << "Don't create file \"" << filePlayer << "\"." << std::endl;
    }
}

void FileManager::updateFileGame(std::string name, int firstPlayer, int number, int turn, int x, int y, char currentPlayer, std::vector<std::vector<char>> vec)
{
    std::ofstream outfile(pathFile + "\\" + name + " \\StatusGame" + to_string(number) + ".txt", std::ios::app); // Mở tệp tin để ghi tiếp vào cuối tệp
    if (outfile.is_open())
    {
        outfile << "firstPlayer: " + to_string(firstPlayer) + "\n"; // Nếu là 1: X     0: O
        outfile << "Turn: " + to_string(turn) + "\n";
        outfile << "Current Player: " + to_string(currentPlayer) + "\n";
        outfile << "x,y " + to_string(x) + " " + to_string(y) + "\n";
        for (const auto &row : vec)
        {
            for (const auto &elem : row)
            {
                outfile << elem << " ";
            }
            outfile << "\n";
        }
        outfile << "\n";
        outfile.close();
    }
}

bool FileManager::checkFolderExist(std::string name)
{

    std::string path = pathFile; // Thư mục hiện tại
    std::vector<std::string> directories;
    std::string search_path = path + "\\*.*";
    WIN32_FIND_DATA fd;

    HANDLE hFind = FindFirstFile(search_path.c_str(), &fd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            // Kiểm tra nếu là thư mục và không phải là "." hoặc ".."
            if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) &&
                strcmp(fd.cFileName, ".") != 0 &&
                strcmp(fd.cFileName, "..") != 0)
            {
                directories.push_back(fd.cFileName);
            }
        } while (FindNextFile(hFind, &fd));
        FindClose(hFind);
    }
    else
    {
        std::cerr << "Don't Open: " << path << std::endl;
    }

    for (const auto &dir : directories)
    {
        if (dir == name)
        {
            return 1;
        }
    }
    return 0;
}

bool FileManager::checkFileExist(std::string name)
{
    std::ifstream infile(name);
    return 1;
}

void FileManager::recordPlayerInfo(std::string name, int win, int lose, int draw)
{
    std::string filePlayer = pathFile + "\\" + name + "\\informationPlayer.txt";
    std::ifstream infile(filePlayer);  // Mở file để đọc
    std::ofstream outfile("temp.txt"); // Tạo một file tạm để lưu nội dung cập nhật

    if (infile.is_open() && outfile.is_open())
    {
        std::string line;
        while (std::getline(infile, line))
        {
            if (line.find("Win: ") == 0)
            {
                outfile << "Win: " << win << "\n";
            }
            else if (line.find("Lose: ") == 0)
            {
                outfile << "Lose: " << lose << "\n";
            }
            else if (line.find("Draw: ") == 0)
            {
                outfile << "Draw: " << draw << "\n";
            }
            else
            {
                outfile << line << "\n"; // Giữ nguyên các dòng không cần cập nhật
            }
        }
        infile.close();
        outfile.close();

        // Xóa file cũ và đổi tên file tạm thành tên file cũ
        if (std::remove(filePlayer.c_str()) != 0)
        {
            std::cerr << "Remove old file !" << std::endl;
        }
        if (std::rename("temp.txt", filePlayer.c_str()) != 0)
        {
            std::cerr << "Don't remove old file !" << std::endl;
        }
    }
    else
    {
        std::cerr << "Don't open file \"" << filePlayer << "\" hoặc tạo file tạm." << std::endl;
    }
}

void FileManager::showInformation()
{
    std::string namePlayer;
    std::vector<std::string> listFile = listDirectoriesInDirectory(pathFile);
    std::cout << "List Player ! " << endl;
    for (const auto &file : listFile)
    {
        std::cout << file << std::endl;
    }
    std::cout << "Enter the player information you want to find ! ";
    std::cin >> namePlayer;

    bool checkFilePlayer = std::find(listFile.begin(), listFile.end(), namePlayer) != listFile.end();

    if (checkFilePlayer)
    {
        #ifdef _WIN32
            system("CLS");
        #else
            system("clear");
        #endif
        std::cout << "Successful !" << std::endl;
        file.open(pathFile + "\\" + namePlayer + "\\informationPlayer.txt", std::ios::binary);

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
    else
    {
        std::cout << "No information found !" << std::endl;
    }
}

std::vector<std::string> FileManager::listDirectoriesInDirectory(const std::string &directoryPath)
{
    std::vector<std::string> directories;
    std::string searchPath = directoryPath + "\\*";
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "FindFirstFile failed (" << GetLastError() << ")" << std::endl;
        return directories;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            std::string dirName = findFileData.cFileName;
            if (dirName != "." && dirName != "..") { // Bỏ qua các thư mục đặc biệt . và ..
                directories.push_back(dirName);
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
    return directories;
}

FileManager::~FileManager()
{
}