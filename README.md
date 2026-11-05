**Connect Four**  
A simple two-player **Connect Four** game written in C++. The game runs in the terminal and uses a 6-row by 7-column board.  
**Features**  
- Two-player local gameplay: Black (`BK`) and White (`WH`).  
- Players take turns dropping a piece into one of the seven columns.  
- Pieces occupy the lowest available position in the selected column.  
- The game checks for four consecutive pieces horizontally, vertically, and diagonally.  
- The board is displayed in the terminal after each move.  
- Players can start another match or exit after a game ends.  
**Requirements**  
- A C++ compiler that supports at least C++11, such as GCC, Clang, or MinGW-w64.  
- A terminal capable of displaying the board and (for the screen-clearing effect) ANSI escape sequences.  
**Build**  
Clone the repository:  
```  
git clone <REPOSITORY-URL>  
 cd <REPOSITORY-DIRECTORY>  
   
```  
Compile the source file with GCC:  
```  
g++  -Wall -W –O2 connect_four.cpp -o connect_four  
   
```  
On Windows with MinGW-w64, the output executable will normally be `connect_four.exe`:  
```  
g++ -std=c++11 -Wall -Wextra –O2 connect_four.cpp -o connect_four.exe  
   
```  
**Run**  
On Linux or macOS:  
```  
./connect_four  
   
```  
On Windows PowerShell:  
```  
.\connect_four.exe  
   
```  
**How to play**  
1. Run the program.  
2. Black plays first, followed by White.  
3. When prompted, enter a column number from **1** to **7**.  
4. The piece is placed in the lowest available cell in that column.  
5. The first player to connect four pieces horizontally, vertically, or diagonally wins.  
6. After a match, enter `y` to play again or `n` to quit.  
If a column is full, the program asks the current player to choose another column.  
**Project structure**  
```  
.  
 ├── connect_four.cpp  
 ├── README.md  
 ├── LICENSE.md  
 └── .gitignore  
   
```  
**Notes**  
This is a small console-based project. It does not include a graphical interface, network multiplayer, or an automated opponent.  
**License**  
This project is distributed under the MIT License. See [LICENSE.md.](LICENSE.md "LICENSE.md")  
