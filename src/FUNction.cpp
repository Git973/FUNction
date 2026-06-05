#include <iostream>
using namespace std;

void clearScreen() {
	for (int i = 0; i < 50; i++) {cout << "\n";}
}



void titleScreen() {
	cout << "      FUNction\nhaving fun with integers\n    (and strings)!\n\n";
}



void resetSelector(int &confirm, int &selector) {
	selector = 99;
	confirm = 100;
}



void errorClear() {
if (std::cin.fail()){
    std::cin.clear();
    while (std::cin.get() != '\n') {}
}
}



void titleSelect(int &menu,int &quit, int &selector, int &confirm) {
while (true) {
	clearScreen();
	if (selector == 0) {cout << "                          >[0]Quit\n";}
	else {cout << "                            [0]Quit\n";}
	titleScreen();
	cout << "here are some FUN games:\n";
	if (selector == 1) {cout << " >[1] Tic Tac Toe<\n";}
	else {cout << "   [1] Tic Tac Toe\n";}
	if (selector == 2) {cout << " >[2] Connect 4<\n";}
	else {cout << "   [2] Connect 4\n";}
	if (selector == 3) {cout << " >[3] Hangman<\n";}
	else {cout << "   [3] Hangman\n";}
	cout << "\nor if you wanna be more FUNctional:\n";
	if (selector == 4) {cout << " >[4] Calculator<\n";}
	else {cout << "   [4] Calculator\n";}
    
    if (selector == 99) {cout << "\nPress to Confirm: ";}
	else {cout << "\nPress " << selector << " again to confirm:";}
	cin >> selector;
	errorClear();
	if (confirm == selector && selector > 0 && selector < 5)
	{switch (selector){
	    case 1: menu = 2; break;
        case 2: menu = 4; break;
	    case 3: menu = 9; break;
		case 4: menu = 9; break;};
 	 break;}
	else if (confirm == selector && selector == 0){quit = 0;break;}
	confirm = selector;
}
}



void tttSelect(int &menu, int &selector, int &confirm, bool &AIplayer) {
while (true) {
	clearScreen();
	titleScreen();
	cout << "Let's Play: Tic Tac Toe\n";
	if (selector == 1) {cout << " >[1] Singleplayer<\n";}
	else {cout << "   [1] Singleplayer\n";}
	if (selector == 2) {cout << " >[2] Multiplayer<\n";}
	else {cout << "   [2] Multiplayer\n";}
	if (selector == 3) {cout << " >[3] Back<\n";}
    else {cout << "   [3] Back\n";}

	if (selector == 99) {cout << "\nPress to Confirm: ";}
	else {cout << "\nPress " << selector << " again to confirm:";}
	cin >> selector;
	errorClear();
	if (confirm == selector && selector > 0 && selector < 5)
	{switch (selector){
		case 1: AIplayer = true; menu = 3; break;
		case 2: AIplayer = false; menu = 3; break;
		case 3: menu = 1; break;};
	 break;}
	confirm = selector;
}
}



const int tttwins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

void tttGame(char tttboard[9],char &player, int &position, int &move, int &menu, int &invalid, int &selector, bool &AIplayer, bool draw, bool win) {
player = 'X';
win = draw = invalid = 0;
clearScreen();
for (int i = 0; i < 9; i++){tttboard[i] = '1' + i;}
while (true) {
	if (player == 'X' || !AIplayer) {
		if(!AIplayer) {clearScreen();}
		if (invalid) {cout << "Invalid move, try again.\n";invalid = false;}
		cout << "\n-------------\n";
		cout << "| " << tttboard[0] << " | " << tttboard[1] << " | " << tttboard[2] << " |\n";
		cout << "|---|---|---|\n";
		cout << "| " << tttboard[3] << " | " << tttboard[4] << " | " << tttboard[5] << " |\n";
		cout << "|---|---|---|\n";
		cout << "| " << tttboard[6] << " | " << tttboard[7] << " | " << tttboard[8] << " |\n";
		cout << "-------------\n";
		cout << player << "'s chose position (1-9): ";
		cin >> position;
		errorClear();
		move = position - 1;}

	else {
	    for (int i = 0; i < 9; i++) {if (tttboard[i] != 'X' && tttboard[i] != 'O') {move = i;break;}}
		clearScreen();
		cout << "AI chose position: " << move + 1 << "\n";}

	if (tttboard[move] != 'X' && tttboard[move] != 'O') {tttboard[move] = player;}
	else {invalid = true;continue;}

	for (int i = 0; i < 8; i++){
		int a = tttwins[i][0];
		int b = tttwins[i][1];
		int c = tttwins[i][2];
		if (tttboard[a] == tttboard[b] && tttboard[b] == tttboard[c] && (tttboard[a] == 'X' || tttboard[a] == 'O'))
		{win = true;break;}
	}

    draw = true;
	for (int i = 0; i < 9; i++){
		if (tttboard[i] != 'X' && tttboard[i] != 'O') {draw = false;break;}
	}
	
	if (draw || win){break;}
	
	if (player == 'X') {player = 'O';}
	else {player = 'X';}
}

clearScreen();
titleScreen();
cout << "\n     -------------\n";
cout << "     | " << tttboard[0] << " | " << tttboard[1] << " | " << tttboard[2] << " |\n";
cout << "     |---|---|---|\n";
cout << "     | " << tttboard[3] << " | " << tttboard[4] << " | " << tttboard[5] << " |\n";
cout << "     |---|---|---|\n";
cout << "     | " << tttboard[6] << " | " << tttboard[7] << " | " << tttboard[8] << " |\n";
cout << "     -------------\n";
if (win) {cout << "\n\n     Player " << player << " wins!\n";}
else {cout << "\n\n     It's a draw!\n";}
cout << "[Press any key to continue]:";
cin >> selector;
errorClear();
menu =1;
}



void c4Select(int &menu, int &selector, int &confirm, bool &AIplayer) {
while (true) {
	clearScreen();
	titleScreen();
	cout << " Let's Play: Connect 4\n";
	if (selector == 1) {cout << " >[1] Singleplayer<\n";}
	else {cout << "   [1] Singleplayer\n";}
	if (selector == 2) {cout << " >[2] Multiplayer<\n";}
	else {cout << "   [2] Multiplayer\n";}
	if (selector == 3) {cout << " >[3] Back<\n";}
    else {cout << "   [3] Back\n";}

	if (selector == 99) {cout << "\nPress to Confirm: ";}
	else {cout << "\nPress " << selector << " again to confirm:";}
	cin >> selector;
	errorClear();
	if (confirm == selector && selector > 0 && selector < 5)
	{switch (selector){
		case 1: AIplayer = false; menu = 9; break;
		case 2: AIplayer = true; menu = 9; break;
		case 3: menu = 1; break;};
	 break;}
	confirm = selector;
	errorClear();
}
}



//uncontinued c4Game
void c4Game(char c4board[42],char &player, int &position, int &move, int &menu, int &invalid, int &selector, bool &AIplayer, bool draw, bool win){
for(int i = 0; i < 42; i++){if(i<7){c4board[i] = i+'1';}
                            else{c4board[i] = ' ';}}
while(false){
    clearScreen();
    cout << "\n-----------------------------\n";
    cout << "| " << c4board[0] << " | " << c4board[1] << " | " << c4board[2] << " | " << c4board[3] << " | " << c4board[4] << " | " << c4board[5] << " | " << c4board[6] << " |\n";
    cout << "|---|---|---|---|---|---|---|\n";
    cout << "| " << c4board[7] << " | " << c4board[8] << " | " << c4board[9] << " | " << c4board[10] << " | " << c4board[11] << " | " << c4board[12] << " | " << c4board[13] << " |\n";
    cout << "|---|---|---|---|---|---|---|\n";
    cout << "| " << c4board[14] << " | " << c4board[15] << " | " << c4board[16] << " | " << c4board[17] << " | " << c4board[18] << " | " << c4board[19] << " | " << c4board[20] << " |\n";
    cout << "|---|---|---|---|---|---|---|\n";
    cout << "| " << c4board[21] << " | " << c4board[22] << " | " << c4board[23] << " | " << c4board[24] << " | " << c4board[25] << " | " << c4board[26] << " | " << c4board[27] << " |\n";
    cout << "|---|---|---|---|---|---|---|\n";
    cout << "| " << c4board[28] << " | " << c4board[29] << " | " << c4board[30] << " | " << c4board[31] << " | " << c4board[32] << " | " << c4board[33] << " | " << c4board[34] << " |\n";
    cout << "|---|---|---|---|---|---|---|\n";
    cout << "| " << c4board[35] << " | " << c4board[36] << " | " << c4board[37] << " | " << c4board[38] << " | " << c4board[39] << " | " << c4board[40] << " | " << c4board[41] << " |\n";
    cout << "-----------------------------\n";
}
cout << "[Press any key to continue]:";
cin >> selector;
errorClear();
menu =1;
}



void hangSelect(){}



void hangGame(){}



void notAvailable(int &menu,int &quit, int &selector, int &confirm){
while (true) {
	clearScreen();
	titleScreen();
	cout << "    COMING SOON!!\n";
	cout << "It seems that this section\n  is not yet complete\n\n";
	if (selector == 1) {cout << " >[1] Back to Menu<\n";}
	else {cout << "   [1] Back to Menu\n";}

	if (selector == 99) {cout << "\nPress to Confirm: ";}
	else {cout << "\nPress " << selector << " again to confirm:";}
	cin >> selector;
	errorClear();
    if (confirm == selector && selector == 1) {menu = 1; break;}
	confirm = selector;
}
}





int main () {
int menu,quit,confirm,selector,position,move,invalid;
char tttboard[9],c4board[42],player;
bool AIplayer,draw,win;
resetSelector(confirm,selector);
menu = quit = 1;

while(true) {
	switch (menu) {
	case 1: //mainmenu
		resetSelector(confirm,selector);
		titleSelect(menu,quit,selector,confirm);
		break;
	case 2: //tttSelect
		resetSelector(confirm,selector);
		tttSelect(menu,selector,confirm,AIplayer);
		break;
	case 3: //tttGame
        resetSelector(confirm,selector);
        tttGame(tttboard,player,position,move,menu,invalid,selector,AIplayer,draw,win);
        break;
	case 4: //c4Select
    	resetSelector(confirm,selector);
	    c4Select(menu,selector,confirm,AIplayer);
		break;
	case 5: //c4Game
    	resetSelector(confirm,selector);
	    c4Game(c4board,player,position,move,menu,invalid,selector,AIplayer,draw,win);
		break;
	case 6: //hangSelect
		break;
	case 7: //hangGame
		break;
	case 8: //calculator
		break;
	case 9: //notAvailable
	    resetSelector(confirm,selector);
	    notAvailable(menu,quit,selector,confirm);
		break;
	}
if (!quit){break;}
}

return 0;
}