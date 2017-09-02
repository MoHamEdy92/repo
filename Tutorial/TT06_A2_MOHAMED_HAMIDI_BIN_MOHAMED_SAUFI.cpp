/**********|**********|**********|
Program: TT06_A2_MOHAMED_HAMIDI_BIN_MOHAMED_SAUFI.cpp
Course: TCP1101 Programming Fundamentals
Year: 2017/18 Trimester 1
Name: Mohamed Hamidi bin Mohamed Saufi
ID: 1161303937
Email: hamidisaufi@gmail.com
Phone: 011-11392329
**********|**********|**********/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

string newFileName(string textEnter);  //For creating a new file
string emptySpace(int max);  //For adding empty spaces to tiles with respect to the length of string
string tableLine(int max);  //For adding the table lines with respect to the length of string
string textInsert(string textEnter);  //Function for updating text in a tile
void insertWrongEmptyTiles(int tileNumber);  //Function to be called when the tiles selected has empty previous tile
void emptyTextInTiles();  //Function to be called in the attempt to overwrite text in an empty tile

int main()
{
  char menu;
  string filename = "NULL";
  int tile, tileEnd, countingWords;
  string lineOfText, textToBeSaved, textToBeLoaded, searchText;
  char fileSave[100], fileLoad[100];
  const int tileNumber = 1000;
  string text[tileNumber], backupText[tileNumber], secondBackup[tileNumber], backupEmpty[tileNumber];
  string secondBackupEmpty[tileNumber], clipBoard[tileNumber], afterText[tileNumber], findInTile[tileNumber];
  int maxLength [tileNumber];
  for (int i = 0; i < 1000; i++)
  {
    text[i] = " ";
    backupText[i] = " ";
    secondBackup[i] = " ";
    afterText[i] = " ";
    findInTile[i] = "|";
  }
  string emptySpaces[8] = { " "," ", " ", " ", " ", " ", " ", " " };
  string tableLines[8] = { "-", "-", "-", "-", "-", "-", "-", "-" };  //Default table arrays
  int newFile = 0, insertText = 0, deleteText = 0, overwriteText = 0, undoCount = 0, undoText = 0, saveText = 0, loadText = 0;
  int copyText = 0, cutText = 0, pasteText = 0, findText = 0;
  cout << endl;
  cout << "Welcome to the Full Stone-Age Tiled Editor" << endl;
  cout << "What do you want to do today?" << endl;
  cout << endl;
  cout << "File name: " << filename << endl;
  cout << endl;
  do
  {
    cout << "*============================================================" << endl;
    cout << endl;
    cout << "[N]ew, [I]nsert, [D]elete, [O]verwrite, [L]oad, [S]ave," << endl;
    cout << "[C]opy, show-clip [B]oard, [X]cut, [P]aste, [F]ind, [U]ndo, [Q]uit" << endl;
    cout << "==> ";
    cin >> menu;
    cout << endl;

    if (menu == 'q' || menu == 'Q')
    {
      cout << "Thank you for using Full Stone-Age Tiled Editor" << endl;
      cout << endl;
      cout << "Here are your final stats:-" << endl;
      cout << "Number of new file attempt: " << newFile << endl;
      cout << "Number of insert attempt: " << insertText << endl;
      cout << "Number of delete attempt: " << deleteText << endl;
      cout << "Number of overwrite attempt: " << overwriteText << endl;
      cout << "Number of save attempt: " << saveText << endl;
      cout << "Number of load attempt: " << loadText << endl;
      cout << "Number of copy attempt: " << copyText << endl;
      cout << "Number of cut attempt: " << cutText << endl;
      cout << "Number of paste attempt: " << pasteText << endl;
      cout << "Number of find attempt: " << findText << endl;
      cout << "Number of undo attempt: " << undoText << endl;
      cout << endl;
    }

    else {
      if (filename == "NULL")      //When there is no new file created
      {
        if (menu == 'n' || menu == 'N')
        {
          newFile += 1;

          filename = newFileName(filename);
          system("cls");
          cout << endl;
          cout << "|----+---+---+---+---+---+---+---+---|" << endl
               << "|    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |" << endl
               << "|----+---+---+---+---+---+---+---+---|" << endl
               << "| 00 |   |   |   |   |   |   |   |   |" << endl
               << "|----+---+---+---+---+---+---+---+---|" << endl;
          cout << endl;
          cout << "File name: " << filename << ".txt" << endl;
          cout << endl;
        }

        else
        {
          system("cls");
          cout << endl;
          cout << "Invalid command. Please create a new file" << endl;
          cout << endl;
        }
      }

      else       //When a new file is created
      {
        if (menu == 'n' || menu == 'N')
        {
          newFile += 1;
          undoCount = 0;
          for (int i = 0; i < tileNumber; i++)
          {
            text[i] = " ";
          }
          for (int i = 0; i < 8; i++)
          {
            emptySpaces[i] = " ";
            tableLines[i] = "-";
          }

          filename = newFileName(filename);
          system("cls");
        }

        else if (menu == 'i' || menu == 'I')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          insertText += 1;
          undoCount = 0;
          for (int i = 0; i < tileNumber; i++)
          {
            secondBackupEmpty[i] = backupEmpty[i];
            backupEmpty[i] = afterText[i];

            secondBackup[i] = backupText[i];
            backupText[i] = text[i];
          }

          if (text[0] == " ")
          {
            cout << "Tile number ==> 1" << endl;
            text[0] = textInsert(text[0]);
            istringstream iss(text[0]);

            for (int i = 0; i < tileNumber; i++)
            {
              iss >> text[i];
            }

            system("cls");
          }

          else
          {
            do
            {
              cout << "Tile number ==> ";
              cin >> tile;

              if (tile >= 1 && tile <= 80)
              {
                if (text[tile - 1] == " ")
                {
                  if (text[tile - 2] == " ")
                  {
                    for (int i = 0; i < (tile - 1); i++)
                    {
                      if (text[i] == " ")
                      {
                        cout << "Please enter the text in tile " << (i + 1) << " first" << endl;
                        text[i] = textInsert(text[i]);
                        istringstream iss(text[i]);

                        for (int j = i; j < tileNumber; j++)
                        {
                          iss >> text[j];
                        }

                        system("cls");
                        break;
                      }
                    }
                  }
                  else
                  {
                    text[tile - 1] = textInsert(text[tile - 1]);
                    istringstream iss(text[tile - 1]);

                    for (int i = (tile - 1); i < tileNumber; i++)
                    {
                      iss >> text[i];
                    }

                    system("cls");
                  }
                }
                else
                {
                  if (text[79] == " ")
                  {
                    lineOfText = textInsert(lineOfText);
                    stringstream iss(lineOfText);
                    countingWords = 1;
                    for (int i = 0; i < (lineOfText.length() - 1); i++)
                    {
                      if (lineOfText[i] == ' ' && lineOfText[i + 1] != ' ')
                      {
                        countingWords = countingWords + 1;
                      }
                    }

                    for (int i = (tile - 1); i < (tile + countingWords - 1); i++)
                    {
                      for (int j = 10; j >= 1; j--)
                      {
                        text[i + countingWords * (j + 1)] = text[i + countingWords * j];
                      }
                      text[i + countingWords] = text[i];
                      iss >> text[i];
                    }
                  }

                  else
                  {
                    system("cls");
                    cout << "The tiles are already full. Please delete or overwrite any tile" << endl;
                  }
                }
              }
              else
              {
                cout << endl;
                cout << "Invalid tile number. Please try again" << endl;
              }
            } while (tile > 80);
          }
        }

        else if (menu == 'd' || menu == 'D')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          deleteText += 1;
          undoCount = 0;
          for (int i = 0; i < 80; i++)
          {
            secondBackup[i] = backupText[i];
            backupText[i] = text[i];
          }

          do
          {
            cout << "From tile number ==> ";
            cin >> tile;
            cout << "To tile number ==> ";
            cin >> tileEnd;

            if (tile >= 1 && tile <= 80)
            {
              if (text[tile - 1] == " " || text[tileEnd - 1] == " ")
              {
                system("cls");
                emptyTextInTiles();
              }
			  
			  else 
			  {
			    if (tileEnd < tile)
                {
			      system("cls");
			      cout << endl;
			      cout << "Please key in the appropriate tile numbers" << endl;
			    }

                else 
                {
                  for (int i = (tile - 1); i < 80; i++)
                  {
                    text[i] = text[i + (tileEnd - (tile - 1))];
                  }
                  system("cls");
                }
              }
            }

            else
            {
              cout << endl;
              cout << "Invalid tile number. Please try again" << endl;
            }
          } while (tile > 80);
        }

        else if (menu == 'o' || menu == 'O')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          overwriteText += 1;
          undoCount = 0;
          do
          {
            cout << "Tile number ==> ";
            cin >> tile;

            if (tile >= 1 && tile <= 80)
            {
              if (text[tile - 1] == " ")
              {
                system("cls");
                emptyTextInTiles();
              }

              else
              {
                text[tile - 1] = " ";
                afterText[tile - 1] = " ";
                text[tile - 1] = textInsert(text[tile - 1]);
                istringstream iss(text[tile - 1]);

                countingWords = 1;
                for (int i = 0; i < (text[tile - 1].length() - 1); i++)
                {
                  if (text[tile - 1][i] == ' ' && text[tile - 1][i + 1] != ' ')
                  {
                    countingWords = countingWords + 1;
                  }
                }

                for (int i = (tile - 1); i < (tile + countingWords - 1); i++)
                {
                  iss >> text[i];
                }
              }
            }

            else
            {
              cout << endl;
              cout << "Invalid tile number. Please try again" << endl;
            }
          } while (tile > 80);
        }

        else if (menu == 'S' || menu == 's')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          saveText = saveText + 1;
          for (int i = 0; i < 80; i++)
          {
            textToBeSaved = textToBeSaved + text[i] + " ";
            if (text[i] == " ")
            {
              break;
            }
          }
          cout << "File name (enter=" << filename << ".txt) ==> ";
          cin >> fileSave;
          system("cls");
          cout << endl;
          ofstream save;
          save.open(fileSave);
          if (save.fail())
          {
            cout << "Error, unable to save into such file" << endl;
          }
          else
          {
            cout << endl;
            cout << "File saved." << endl;
            save << textToBeSaved;
            save.close();
            cout << "----------------------- " << fileSave << " for reference -----------------------" << endl;
            cout << endl;
            cout << textToBeSaved << endl << endl;
          }
        }

        else if (menu == 'L' || menu == 'l')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          loadText = loadText + 1;
          cout << "File name ==> ";
          cin >> fileLoad;
          system("cls");
          ifstream load(fileLoad);
          if (load.fail())
          {
            cout << "Error, file is not found. Please try again" << endl;
          }
          else
          {
            filename = fileLoad;
            getline(load, textToBeLoaded);
            istringstream iss(textToBeLoaded);
            for (int i = 0; i < tileNumber; i++)
            {
              iss >> text[i];
            }
            load.close();
            cout << "----------------------- " << fileLoad << ".txt for reference -----------------------" << endl;
            cout << endl;
            cout << textToBeLoaded << endl << endl;
          }
        }

        else if (menu == 'C' || menu == 'c')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          copyText = copyText + 1;
          do
          {
            cout << "From tile number ==> ";
            cin >> tile;
            cout << "To tile number ==> ";
            cin >> tileEnd;

            if (tile >= 1 && tile <= 80)
            {
              if (text[tile - 1] == " " || text[tileEnd - 1] == " ")
              {
                system("cls");
                emptyTextInTiles();
              }
              else
              {
                if (tileEnd < tile)
                {
			      system("cls");
			      cout << endl;
			      cout << "Please key in the appropriate tile numbers" << endl;
			    }
                else
                {
                  for (int i = 0; i < 80; i++)
                  {
                    clipBoard[i] = " ";
                  }
                  for (int i = (tile - 1); i <= (tileEnd - 1); i++)
                  {
                    clipBoard[i - (tile - 1)] = text[i];
                  }
                }
              }
            }

            else
            {
              cout << endl;
              cout << "Invalid tile number. Please try again" << endl;
            }
          } while (tile > 80);
        }

        else if (menu == 'B' || menu == 'b')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          system("cls");
          cout << endl;
          cout << "Clipboard :" << endl;
          for (int i = 0; i < 80; i++)
          {
            cout << clipBoard[i] << " ";
            if (clipBoard[i] == " ")
            {
              break;
            }
          }
          cout << endl;
        }

        else if (menu == 'X' || menu == 'x')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          cutText = cutText + 1;
          undoCount = 0;
          for (int i = 0; i < 80; i++)
          {
            secondBackup[i] = backupText[i];
            backupText[i] = text[i];
          }

          do
          {
            cout << "From tile number ==> ";
            cin >> tile;
            cout << "To tile number ==> ";
            cin >> tileEnd;

            if (tile >= 1 || tile <= 80)
            {
              if (text[tile - 1] == " " || text[tileEnd - 1] == " ")
              {
                system("cls");
                emptyTextInTiles();
              }
			  
			  
              else 
              {
                if (tileEnd < tile)
                {
                  system("cls");
                  cout << endl;
                  cout << "Please key in the appropriate tile numbers" << endl;
                }

                else
                {
                  for (int i = 0; i < 80; i++)
                  {
                    clipBoard[i] = " ";
                  }

                  for (int i = (tile - 1); i <= (tileEnd - 1); i++)
                  {
                    clipBoard[i - (tile - 1)] = text[i];
                  }

                  for (int i = (tile - 1); i < 80; i++)
                  {
                    text[i] = text[i + (tileEnd - (tile - 1))];
                  }
                  system("cls");
                }
              }
            }

            else
            {
              cout << endl;
              cout << "Invalid tile number. Please try again" << endl;
            }
          } while (tile > 80);
        }

        else if (menu == 'P' || menu == 'p')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          pasteText += 1;
          undoCount = 0;
          for (int i = 0; i < tileNumber; i++)
          {
            secondBackupEmpty[i] = backupEmpty[i];
            backupEmpty[i] = afterText[i];

            secondBackup[i] = backupText[i];
            backupText[i] = text[i];
          }

          if (text[0] == " ")
          {
            cout << "Tile number ==> 1" << endl;
            text[0] = textInsert(text[0]);
            istringstream iss(text[0]);

            for (int i = 0; i < tileNumber; i++)
            {
              iss >> text[i];
            }

            system("cls");
          }

          else
          {
            do
            {
              cout << "Tile number ==> ";
              cin >> tile;

              if (tile >= 1 && tile <= 80)
              {
                if (text[tile - 1] == " ")
                {
                  if (text[tile - 2] == " ")
                  {
                    for (int i = 0; i < (tile - 1); i++)
                    {
                      if (text[i] == " ")
                      {
                        lineOfText = "";
                        for (int j = 0; j < 80; j++)
                        {
                          lineOfText = lineOfText + clipBoard[j] + " ";
                          if (clipBoard[j + 1] == " ")
                          {
                            break;
                          }
                        }
                        stringstream iss(lineOfText);
                        for (int j = i; j < tileNumber; j++)
                        {
                          iss >> text[j];
                        }

                        system("cls");
                        break;
                      }
                    }
                  }
                  else
                  {
                    lineOfText = "";
                    for (int j = 0; j < 80; j++)
                    {
                      lineOfText = lineOfText + clipBoard[j] + " ";
                      if (clipBoard[j + 1] == " ")
                      {
                        break;
                      }
                    }
                    stringstream iss(lineOfText);
                    for (int i = (tile - 1); i < tileNumber; i++)
                    {
                      iss >> text[i];
                    }
                    system("cls");
                  }
                }
                else
                {
                  if (text[79] == " ")
                  {
                    lineOfText = "";
                    for (int i = 0; i < 80; i++)
                    {
                      lineOfText = lineOfText + clipBoard[i] + " ";
                      if (clipBoard[i + 1] == " ")
                      {
                        break;
                      }
                    }
                    stringstream iss(lineOfText);
                    countingWords = 1;
                    for (int i = 0; i < (lineOfText.length() - 1); i++)
                    {
                      if (lineOfText[i] == ' ' && lineOfText[i + 1] != ' ')
                      {
                        countingWords = countingWords + 1;
                      }
                    }

                    for (int i = (tile - 1); i < (tile + countingWords - 1); i++)
                    {
                      for (int j = 10; j >= 1; j--)
                      {
                        text[i + countingWords * (j + 1)] = text[i + countingWords * j];
                      }
                      text[i + countingWords] = text[i];
                      iss >> text[i];
                    }
                    system("cls");
                  }

                  else
                  {
                    system("cls");
                    cout << "The tiles are already full. Please delete or overwrite any tile" << endl;
                  }
                }
              }
              else
              {
                cout << endl;
                cout << "Invalid tile number. Please try again" << endl;
              }
            } while (tile > 80);
          }
        }

        else if (menu == 'F' || menu == 'f')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          findText = findText + 1;
          cout << "Enter text to find : ";
          cin >> searchText;
          for (int i = 0; i < 80; i++)
          {
            if (text[i] == searchText)
            {
              findInTile[i] = "=";
            }
          }
          system("cls");
        }

        else if (menu == 'U' || menu == 'u')
        {
          for (int i = 0; i < 1000; i++)
          {
            findInTile[i] = "|";
          }
          undoText = undoText + 1;
          undoCount = undoCount + 1;
          if (undoCount <= 2)
          {
            for (int i = 0; i < tileNumber; i++)
            {
              afterText[i] = backupEmpty[i];
              backupEmpty[i] = secondBackupEmpty[i];

              text[i] = backupText[i];
              backupText[i] = secondBackup[i];
            }
            system("cls");
          }
          else
          {
            system("cls");
            cout << endl;
            cout << "Maximum number of undo command has been reached" << endl;
          }
        }

        else
        {
          system("cls");
          cout << endl;
          cout << "Invalid command. Please try again." << endl;
        }

        for (int i = 0; i < tileNumber; i++)
        {
          afterText[i] = " ";
        }

        for (int i = 0; i < 8; i++)
        {
          maxLength[i] = text[i].length();
          for (int j = 8; j <= 72; j = j + 8)
          {
            if (text[i + j].length() > maxLength[i])
            {
              maxLength[i] = text[i + j].length();
            }
          }

          for (int i = 0; i < 8; i++)
          {
            emptySpaces[i] = emptySpace(maxLength[i]);
            tableLines[i] = tableLine(maxLength[i]);
          }
        }

        for (int i = 0; i < tileNumber; i++)
        {
          for (int j = text[i].length(); j < maxLength[i % 8]; j++)
          {
            afterText[i] = afterText[i] + " ";
          }
        }

        cout << endl;
        cout << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl
             << "|    | 1" << emptySpaces[0] << "| 2" << emptySpaces[1] << "| 3" << emptySpaces[2] << "| 4" << emptySpaces[3] << "| 5" << emptySpaces[4] << "| 6" << emptySpaces[5] << "| 7" << emptySpaces[6] << "| 8" << emptySpaces[7] << "|" << endl
             << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl
             << "| 00 | " << text[0] << afterText[0] << findInTile[0] <<" " << text[1] << afterText[1] << findInTile[1] << " " << text[2] << afterText[2] << findInTile[2] << " " << text[3] << afterText[3] << findInTile[3] << " " << text[4] << afterText[4] << findInTile[4] << " " << text[5] << afterText[5] << findInTile[5] << " " << text[6] << afterText[6] << findInTile[6] << " " << text[7] << afterText[7] << findInTile[7] << endl
             << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;
        if (text[8] != " ")
        {
          cout << "| 08 | " << text[8] << afterText[8] << findInTile[8] << " " << text[9] << afterText[9] << findInTile[9] << " " << text[10] << afterText[10] << findInTile[10] << " " << text[11] << afterText[11] << findInTile[11] << " " << text[12] << afterText[12] << findInTile[12] << " " << text[13] << afterText[13] << findInTile[13] << " " << text[14] << afterText[14] << findInTile[14] << " " << text[15] << afterText[15] << findInTile[15] << endl
               << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

          if (text[16] != " ")
          {
            cout << "| 16 | " << text[16] << afterText[16] << findInTile[16] << " " << text[17] << afterText[17] << findInTile[17] << " " << text[18] << afterText[18] << findInTile[18] << " " << text[19] << afterText[19] << findInTile[19] << " " << text[20] << afterText[20] << findInTile[20] << " " << text[21] << afterText[21] << findInTile[21] << " " << text[22] << afterText[22] << findInTile[22] << " " << text[23] << afterText[23] << findInTile[23] << endl
                 << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

            if (text[24] != " ")
            {
              cout << "| 24 | " << text[24] << afterText[24] << findInTile[24] << " " << text[25] << afterText[25] << findInTile[25] << " " << text[26] << afterText[26] << findInTile[26] << " " << text[27] << afterText[27] << findInTile[27] << " " << text[28] << afterText[28] << findInTile[28] << " " << text[29] << afterText[29] << findInTile[29] << " " << text[30] << afterText[30] << findInTile[30] << " " << text[31] << afterText[31] << findInTile[31] << endl
                   << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

              if (text[32] != " ")
              {
                cout << "| 32 | " << text[32] << afterText[32] << findInTile[32] << " " << text[33] << afterText[33] << findInTile[33] << " " << text[34] << afterText[34] << findInTile[34] << " " << text[35] << afterText[35] << findInTile[35] << " " << text[36] << afterText[36] << findInTile[36] << " " << text[37] << afterText[37] << findInTile[37] << " " << text[38] << afterText[38] << findInTile[38] << " " << text[39] << afterText[39] << findInTile[39] << endl
                     << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

                if (text[40] != " ")
                {
                  cout << "| 40 | " << text[40] << afterText[40] << findInTile[40] << " " << text[41] << afterText[41] << findInTile[41] << " " << text[42] << afterText[42] << findInTile[42] << " " << text[43] << afterText[43] << findInTile[43] << " " << text[44] << afterText[44] << findInTile[44] << " " << text[45] << afterText[45] << findInTile[45] << " " << text[46] << afterText[46] << findInTile[46] << " " << text[47] << afterText[47] << findInTile[47] << endl
                       << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

                  if (text[48] != " ")
                  {
                    cout << "| 48 | " << text[48] << afterText[48] << findInTile[48] << " " << text[49] << afterText[49] << findInTile[49] << " " << text[50] << afterText[50] << findInTile[50] << " " << text[51] << afterText[51] << findInTile[51] << " " << text[52] << afterText[52] << findInTile[52] << " " << text[53] << afterText[53] << findInTile[53] << " " << text[54] << afterText[54] << findInTile[54] << " " << text[55] << afterText[55] << findInTile[55] << endl
                         << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

                    if (text[56] != " ")
                    {
                      cout << "| 56 | " << text[56] << afterText[56] << findInTile[56] << " " << text[57] << afterText[57] << findInTile[57] << " " << text[58] << afterText[58] << findInTile[58] << " " << text[59] << afterText[59] << findInTile[59] << " " << text[60] << afterText[60] << findInTile[60] << " " << text[61] << afterText[61] << findInTile[61] << " " << text[62] << afterText[62] << findInTile[62] << " " << text[63] << afterText[63] << findInTile[63] << endl
                           << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

                      if (text[64] != " ")
                      {
                        cout << "| 64 | " << text[64] << afterText[64] << findInTile[64] << " " << text[65] << afterText[65] << findInTile[65] << " " << text[66] << afterText[66] << findInTile[66] << " " << text[67] << afterText[67] << findInTile[67] << " " << text[68] << afterText[68] << findInTile[68] << " " << text[69] << afterText[69] << findInTile[69] << " " << text[70] << afterText[70] << findInTile[70] << " " << text[71] << afterText[71] << findInTile[71] << endl
                             << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;

                        if (text[72] != " ")
                        {
                          cout << "| 72 | " << text[72] << afterText[72] << findInTile[72] << " " << text[73] << afterText[73] << findInTile[73] << " " << text[74] << afterText[74] << findInTile[74] << " " << text[75] << afterText[75] << findInTile[75] << " " << text[76] << afterText[76] << findInTile[76] << " " << text[77] << afterText[77] << findInTile[77] << " " << text[78] << afterText[78] << findInTile[78] << " " << text[79] << afterText[79] << findInTile[79] << endl
                               << "|----+-" << tableLines[0] << "-+-" << tableLines[1] << "-+-" << tableLines[2] << "-+-" << tableLines[3] << "-+-" << tableLines[4] << "-+-" << tableLines[5] << "-+-" << tableLines[6] << "-+-" << tableLines[7] << "-|" << endl;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        cout << endl;
        cout << "File name: " << filename << ".txt" << endl;
        cout << endl;

        }
      }
    } while (menu != 'q' && menu != 'Q');
  return 0;
}

void emptyTextInTiles()
{
  cout << endl;
  cout << "No text detected in selected tile" << endl;
  return;
}

string newFileName(string textEnter)
{
  cout << "Please enter your file name" << endl;
  cout << "New file name ==> ";
  cin >> textEnter;
  cout << endl;
  return textEnter;
}

string textInsert(string textEnter)
{
  cout << "Text ==> ";
  cin.ignore();
  getline(cin, textEnter);
  system("cls");
  return textEnter;
}

void insertWrongEmptyTiles(int tileNumber)
{
  cout << endl;
  cout << "Please fill out tile number " << tileNumber << " first" << endl;
  cout << "Tile number ==> " << tileNumber << endl;
  return;
}

string emptySpace(int max)
{
  string emptySp = "";
  for (int i = 0; i < max; i++)
  {
    emptySp += " ";
  }
  return emptySp;
}

string tableLine(int max)
{
  string tableLi = "";
  for (int i = 0; i < max; i++)
  {
    tableLi += "-";
  }
  return tableLi;
}
