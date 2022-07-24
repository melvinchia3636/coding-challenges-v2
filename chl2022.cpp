#include <string>
#include <iostream>
#include <map>
#include <math.h>
#include <iomanip>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <chrono>
#include <list>
#include <bits/stdc++.h>

typedef std::chrono::system_clock Clock;

std::vector<std::string> splitString(std::string str, std::string delimiter = " ")
{
    std::vector<std::string> words;
    int start = 0;
    int end = str.find(delimiter);
    while (end != -1)
    {
        words.push_back(str.substr(start, end - start));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    words.push_back(str.substr(start, end - start));
    return words;
}

int chopTheTree()
{
    float numberOfTrees;
    std::cout << "Number of trees: ";
    std::cin >> numberOfTrees;
    if (numberOfTrees <= 0 or floor(numberOfTrees) != numberOfTrees)
    {
        std::cout << "You must specify a positive integer number for the number of trees!" << std::endl;
        return -1;
    }

    std::map<std::string, float> treeTypesMap;

    treeTypesMap["American Beech"] = 6;
    treeTypesMap["Basswood"] = 3;
    treeTypesMap["Common Horsechestnut"] = 8;
    treeTypesMap["Dogwood"] = 8;
    treeTypesMap["European White Birch"] = 5;
    treeTypesMap["White Fir"] = 7.5;

    for (int i = 0; i < numberOfTrees; i++)
    {
        float circumference;
        std::string treeType;

        std::cout << "Please enter circumference: ";
        std::cin >> circumference;
        if (circumference <= 0.0)
        {
            std::cout << "The circumference for " << treeType << " must be greater than 0!" << std::endl;
            continue;
        }

        std::cout << "Please enter tree type: ";
        std::getline(std::cin >> std::ws, treeType);
        if (not treeTypesMap.count(treeType))
        {
            std::cout << "Species entered is not available!" << std::endl;
            continue;
        }

        float DBH = circumference / 3.141592;
        float treeAge = DBH * treeTypesMap[treeType];

        std::cout << treeType << " : " << std::fixed << std::setprecision(1) << circumference << " : " << std::fixed << std::setprecision(1) << treeAge << std::endl;
    }

    return 0;
}

bool charNeedRemove(char c)
{
    return not isalnum(c) and c != '\'';
}

void findVocabulary()
{
    // accept input
    std::string paragraph;
    std::cout << "Enter the paragraph you want to calculate for vocab: " << std::endl;
    std::getline(std::cin >> std::ws, paragraph);

    // transfrom the string to uppercase
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::toupper);

    // split the string with space
    std::vector<std::string> splittedString = splitString(paragraph);

    // remove special character except "\'"
    for (int i = 0; i < splittedString.size(); i++)
    {
        splittedString[i].erase(std::remove_if(splittedString[i].begin(), splittedString[i].end(), [](char c)
                                               { return not isalnum(c) and c != '\''; }),
                                splittedString[i].end());
    }

    // sort the string
    sort(splittedString.begin(), splittedString.end());

    // remove duplicates
    splittedString.erase(unique(splittedString.begin(), splittedString.end()), splittedString.end());

    // output the result
    std::cout << splittedString.size() << std::endl;
    for (int i = 0; i < splittedString.size(); i++)
    {
        std::cout << splittedString[i] << std::endl;
    }

    return;
}

std::array<int, 2> longestContinuousSTR(std::string DNA, std::string STR)
{
    int occurence = DNA.find(STR, 0);
    int max_count = 0;
    int count = 0;
    int STR_len = STR.length();

    while (occurence != -1)
    {
        int next_occurence = DNA.find(STR, occurence + 1);
        if (next_occurence == occurence + STR_len)
        {
            count++;
        }
        else
        {
            max_count = std::max(max_count, count);
            count = 0;
        }
        if (next_occurence == -1)
            break;
        occurence = next_occurence;
    }

    return {occurence - max_count * STR_len, (max_count + 1) * STR_len};
}

void DNAMatching()
{
    std::string STR, crimeScene;
    int suspect_count = 4;
    std::string suspect[suspect_count];
    ;

    std::cout << "Please enter STR: ";
    std::cin >> STR;
    std::cout << "Please enter DNA found in crime scene: ";
    std::cin >> crimeScene;
    for (int i = 0; i < suspect_count; i++)
    {
        std::cout << "Please enter DNA of suspect " << i << " : ";
        std::cin >> suspect[i];
    }

    std::array<int, 2> longestSTRInCrimeScene = longestContinuousSTR(crimeScene, STR);
    std::string longestSTR = crimeScene.substr(longestSTRInCrimeScene[0], longestSTRInCrimeScene[1]);

    for (int i = 0; i < suspect_count; i++)
    {
        if (suspect[i].substr(longestSTRInCrimeScene[0], longestSTRInCrimeScene[1]) == longestSTR)
        {
            std::cout << i + 1 << std::endl
                      << longestSTRInCrimeScene[1] / STR.length() << std::endl;
            return;
        }
    }
    std::cout << 0 << std::endl
              << 0 << std::endl;
}

void twoOPT()
{
    int changeCount;
    std::cout << "Please enter the number of iterations: ";
    std::cin >> changeCount;

    std::string route = "abcdefgha";

    for (int i = 0; i < changeCount; i++)
    {
        std::string swap;
        std::cout << "Please enter the start and end node of iteration " << i << ": ";
        std::cin >> swap;

        int first = route.find(swap[0]);
        int second = route.find(swap[1]);

        int start = std::min(first, second);
        int end = std::max(first, second);

        std::string result = route;
        for (int j = 0; j <= end - start; j++)
        {
            result[start + j] = route[end - j];
        }
        route = result;
    }

    std::cout << route << std::endl;
    return;
}

void arrangeIC()
{
    std::string ICString;
    std::cout << "Please enter the IC List : ";
    std::cin >> ICString;
    std::vector<std::string> ICList = splitString(ICString, ";");

    auto now = Clock::now();
    std::time_t now_c = Clock::to_time_t(now);
    struct tm *ntm = std::localtime(&now_c);

    std::vector<std::map<std::string, std::string>> ICInfoList;
    for (int i = 0; i < ICList.size(); i++)
    {
        std::string birthDate = splitString(ICList[i], "-")[0];
        std::map<std::string, std::string> ICInfo;

        std::string genderCode(1, ICList[i].back());
        int genderCodeNum = std::stoi(genderCode);
        std::string birthYear = birthDate.substr(0, 2);
        birthYear = (std::stoi(birthYear) > ntm->tm_year - 100 ? "19" : "20") + birthYear;

        ICInfo["original"] = ICList[i];
        ICInfo["birthDate"] = birthDate;
        ICInfo["birthYear"] = birthYear;
        ICInfo["birthMonth"] = birthDate.substr(2, 2);
        ICInfo["birthDay"] = birthDate.substr(4, 2);
        ICInfo["gender"] = genderCodeNum % 2 ? "1" : "0";

        ICInfoList.push_back(ICInfo);
    }

    std::vector<std::string> sortPriorities;

    for (int i = 0; i < 3; i++)
    {
        std::string input;
        std::cout << "Please enter sort priority #" << i << " : ";
        std::getline(std::cin >> std::ws, input);
        sortPriorities.push_back(input);
    }

    std::sort(ICInfoList.begin(), ICInfoList.end(), [sortPriorities](std::map<std::string, std::string> a, std::map<std::string, std::string> b)
              {
        for (int s = 0; s < sortPriorities.size(); s++) {
            if (sortPriorities[s].find("Gender") != -1) {
                if (sortPriorities[s].find("Female") != -1) {
                    if (a["gender"] < b["gender"]) return true;
                    if (a["gender"] > b["gender"]) return false;
                } else {
                    if (a["gender"] < b["gender"]) return false;
                    if (a["gender"] > b["gender"]) return true;
                }
            }

            if (sortPriorities[s].rfind("Birth ", 0) == 0) {
                if (a["birth"+splitString(sortPriorities[s])[1]] < b["birth"+splitString(sortPriorities[s])[1]]) return true;
                if (a["birth"+splitString(sortPriorities[s])[1]] > b["birth"+splitString(sortPriorities[s])[1]]) return false;
            }

            if (sortPriorities[s] == "Birthdate") {
                if (a["birthYear"]+a["birthMonth"]+a["birthDay"] < b["birthYear"]+b["birthMonth"]+b["birthDay"]) return true;
                if (a["birthYear"]+a["birthMonth"]+a["birthDay"] > b["birthYear"]+b["birthMonth"]+b["birthDay"]) return false;
            }
        }
        return false; });

    for (int i = 0; i < ICInfoList.size(); i++)
    {
        std::cout << ICInfoList[i]["original"] << " " << ICInfoList[i]["birthDay"] << " " << ICInfoList[i]["birthMonth"] << " " << ICInfoList[i]["birthYear"] << " " << (ICInfoList[i]["gender"] == "1" ? "Male" : "Female") << std::endl;
    }
}

void mineSweeper()
{
    std::string input1;
    std::cout << "Please enter the row count, column count and mine count of your board: ";
    std::getline(std::cin >> std::ws, input1);

    std::vector<std::string> splittedInput1 = splitString(input1);
    int rows = std::stoi(splittedInput1[0]);
    int cols = std::stoi(splittedInput1[1]);
    int mineCount = std::stoi(splittedInput1[2]);

    char mine[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mine[i][j] = ' ';
        }
    }

    for (int i = 0; i < mineCount; i++)
    {
        std::string mineCoorsInput;
        std::cout << "Please enter the x and y coordinate of mine #" << i << " : ";
        std::getline(std::cin >> std::ws, mineCoorsInput);

        std::vector<std::string> mineCoors = splitString(mineCoorsInput);
        int mineRow = std::stoi(mineCoors[0]);
        int mineCol = std::stoi(mineCoors[1]);

        mine[mineRow][mineCol] = '*';
    }

    int neighbour[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mine[i][j] != '*')
            {
                int neighbourSUSCount = 0;

                for (int n = 0; n < 8; n++)
                {
                    if (i + neighbour[n][0] >= 0 and i + neighbour[n][0] < rows)
                    {
                        if (j + neighbour[n][1] >= 0 and j + neighbour[n][1] < cols)
                        {
                            if (mine[i + neighbour[n][0]][j + neighbour[n][1]] == '*')
                            {
                                neighbourSUSCount++;
                            }
                        }
                    }
                }
                mine[i][j] = neighbourSUSCount + '0';
            }

            std::cout << mine[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

std::string round2(double x)
{
    std::string n = std::to_string(x);
    std::string wtd = n.substr(0, n.find('.') + 4);
    int l = wtd.back() - '0';
    wtd = wtd.substr(0, wtd.length() - 1);
    if (l >= 5)
    {
        wtd[wtd.length() - 1] = std::to_string(wtd.back() - '0' + 1)[0];
    }
    return wtd;
}

void linearInterpolation()
{
    int count;
    std::cout << "Please enter the number of inputs: ";
    std::cin >> count;

    std::vector<std::string> input;
    for (int i = 0; i < count; i++)
    {
        std::string inp;
        std::cout << "Please enter the value for input #" << i + 1 << ": ";
        std::cin >> inp;
        input.push_back(inp);
    }

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == "#")
        {
            int x0, x1;
            double y0, y1;

            for (int f = i - 1; f >= 0; f--)
            {
                if (input[f] != "#")
                {
                    x0 = f + 1;
                    y0 = std::stod(input[f]);
                    break;
                }
            }

            for (int f = i + 1; f < input.size(); f++)
            {
                if (input[f] != "#")
                {
                    x1 = f + 1;
                    y1 = std::stod(input[f]);
                    break;
                }
            }

            float ans = y0 + ((y1 - y0) / (x1 - x0)) * (i + 1 - x0);
            std::cout << round2(ans) << std::endl;
        }
    }
}

float largest(float arr[], int n)
    {
        return *std::max_element(arr, arr+n);
    }

int findDishes()
{
    float price[8] = {
        10,
        78,
        50,
        20,
        40,
        5,
        67,
        35,
    };

    int lowestPrice = 0;
    int li, lj, lk;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (i != j and j != k and i != k)
                {
                    int totalPrice = price[i] + price[j] + price[k];
                    if ((totalPrice >= 80 and totalPrice < lowestPrice) or lowestPrice == 0)
                    {
                        lowestPrice = totalPrice;
                        li = i;
                        lj = j;
                        lk = k;
                    }
                }
            }
        }
    }

    price[li] = 0;
    price[lj] = 0;
    price[lk] = 0;
    
    int maxPrice = largest(price, 8);
    for (int i = 0; i < 8; i++)
    {
        if (price[i] == maxPrice)
        {
            price[i] = 0;
            break;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        std::cout << price[i] << " ";
    }
}

int main()
{
    findDishes();
}