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

    std::string filePlayer = pathFile + name + "\\informationPlayer.txt";
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

    std::string fileStatusGame = pathFile + name + "\\StatusGame" + to_string(number) + ".txt";
    std::ofstream outfileGame(fileStatusGame);

    if (outfileGame.is_open())
    {
        outfileGame << firstPlayer; // Nếu là 1: X     0: O
        outfileGame << "\n";
        outfileGame << turn;
        outfileGame << "\n";
        outfileGame << currentPlayer;
        outfileGame << "\n";
        outfileGame << x << ' ' << y;
        outfileGame << "\n";
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
    std::ofstream outfile;
    std ::string pathFileStatus = pathFile + name + "\\StatusGame" + to_string(number) + ".txt";

    outfile.open(pathFileStatus, std::ios::app);

    // Kiểm tra xem file có mở thành công không
    if (!outfile.is_open())
    {
        std::cout << "Don't open file!" << std::endl;
    }

    outfile << firstPlayer; // Nếu là 1: X     0: O
    outfile << "\n";
    outfile << turn;
    outfile << "\n";
    outfile << currentPlayer;
    outfile << "\n";
    outfile << x << ' ' << y;
    outfile << "\n";

    for (const auto &row : vec)
    {
        for (auto num : row)
        {
            outfile << num;
        }

        outfile << "\n"; // Xuống dòng sau mỗi hàng
    }
    outfile << "\n";
    // Đóng file
    outfile.close();
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

void FileManager::showInformation(){
    std::string namePlayer;
    listFile = listDirectoriesInDirectory(pathFile);
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

void FileManager::deleteFolder()
{
}

void FileManager::showMatch()
{
    int number;
    std::string namePlayer;
    listFile = listDirectoriesInDirectory(pathFile);
    std::cout << "List Player ! " << endl;
    for (const auto &file : listFile)
    {
        std::cout << file << std::endl;
    }

    std::cout << "Enter the player information you want to find ! ";
    std::cin >> namePlayer;
    std::cout << "What match ? " << endl;
    std::cin >> number;

    std::ifstream inputFile(pathFile + namePlayer + "\\StatusGame" + to_string(number) + ".txt");

    if (!inputFile)
    {
        std::cerr << "Unable to open file";
    }

    std::vector<Record> records;
    Record record;

    // Read all records from the file
    while (readRecord(inputFile, record))
    {
        records.push_back(record);
        // Re-initialize the record for the next read
        record = Record();
    }

    inputFile.close();

    // Output the read values to verify
    for (const auto &rec : records)
    {
        std::cout << "First Player: " << rec.firstPlayer << std::endl;
        std::cout << "Turn: " << rec.turn << std::endl;
        std::cout << "Current Player: " << rec.currentPlayer << std::endl;
        std::cout << "Coordinates: (" << rec.x << "," << rec.y << ")" << std::endl;
        std::cout << "Matrix:" << std::endl;
        for (const auto &row : rec.matrix)
        {
            for (const auto &cell : row)
            {
                std::cout << cell;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

bool FileManager::readRecord(std::ifstream &inputFile, Record &record)
{
    std::string line;

    // Read firstPlayer, turn, currentPlayer, and coordinates x, y
    if (!std::getline(inputFile, line))
        return false;
    record.firstPlayer = std::stoi(line);

    if (!std::getline(inputFile, line))
        return false;
    record.turn = std::stoi(line);

    if (!std::getline(inputFile, line))
        return false;
    record.currentPlayer = line[0];

    if (!std::getline(inputFile, line))
        return false;
    std::istringstream coordStream(line);
    coordStream >> record.x >> record.y;

    // Read the 10x10 matrix
    for (int i = 0; i < 10; ++i)
    {
        if (!std::getline(inputFile, line))
            return false;
        for (int j = 0; j < 10; ++j)
        {
            if (j < line.size())
            {
                record.matrix[i][j] = line[j];
            }
            else
            {
                record.matrix[i][j] = ' ';
            }
        }
    }

    // Read the empty line separating records
    std::getline(inputFile, line);

    return true;
}

std::vector<std::string> FileManager::listDirectoriesInDirectory(const std::string &directoryPath)
{
    std::vector<std::string> directories;
    std::string searchPath = directoryPath + "\\*";
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        std::cerr << "FindFirstFile failed (" << GetLastError() << ")" << std::endl;
        return directories;
    }

    do
    {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            std::string dirName = findFileData.cFileName;
            if (dirName != "." && dirName != "..")
            { // Bỏ qua các thư mục đặc biệt . và ..
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