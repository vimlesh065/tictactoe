#include <iostream>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
auto show_board(int k)
{

    int a;
    a = k % 9;
    if (a == 0)
    {
        board[0] = ' ';
        board[1] = ' ';
        board[2] = ' ';
        board[3] = ' ';
        board[4] = ' ';
        board[5] = ' ';
        board[6] = ' ';
        board[7] = ' ';
        board[8] = ' ';
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
        cout << "-----------" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
        cout << "-----------" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
    }
    else
    {
        cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
        cout << "-----------" << endl;
        cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
        cout << "-----------" << endl;
        cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
    }
}
auto x_player_choice()
{
    while (true)
    {
        cout << "select your position from 1 to 9" << endl;
        int x_choice;
        cin >> x_choice;
        if (x_choice < 1 || x_choice > 9)
        {
            cout << "please choose position from 1 to 9" << endl;
        }
        if (board[(x_choice)-1] != ' ')
        {
            cout << "please select empty position" << endl;
        }
        else
        {
            board[(x_choice)-1] = 'X';
            break;
        }
    }
}
auto o_player_choice()
{
    while (true)
    {
        cout << "select your position from 1 to 9" << endl;
        int o_choice;
        cin >> o_choice;
        if (o_choice < 1 || o_choice > 9)
        {
            cout << "please choose position from 1 to 9" << endl;
        }
        if (board[(o_choice)-1] != ' ')
        {
            cout << "please select empty position" << endl;
        }
        else
        {
            board[(o_choice)-1] = 'O';
            break;
        }
    }
}
auto count_move(char S)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == S)
        {
            total += 1;
        }
    }
    return total;
}
auto check_winner()
{
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        return board[3];
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        return board[6];
    }
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        return board[1];
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        return board[2];
    }
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[6] == board[4] && board[4] == board[2] && board[6] != ' ')
    {
        return board[6];
    }
    if (count_move('X') + count_move('O') < 9)
    {
        return 'c';
    }
    else
    {
        return 'D';
    }
}
auto start_game()
{
    string  input = "yes", c;
    int k = -1;

    string x_player_name, o_player_name;
    cout << "x player,please enter your name" << endl;
    getline(cin, x_player_name);
    cout << "o player,please enter your name" << endl;
    getline(cin, o_player_name);
loop:
    while (input == "yes" || input == "YES")
    {
        system("cls");
        k += 1;
        show_board(k);

        if (count_move('X') == count_move('O'))
        {
            cout << x_player_name << "'s turn" << endl;
            x_player_choice();
        }
        else
        {
            cout << o_player_name << "'s turn" << endl;
            o_player_choice();
        }
        char winner = check_winner();
        if (winner == 'X')
        {
            system("cls");
            show_board(k);

            cout << "congratulation " << x_player_name << " ,you won the game" << endl;
            break;
        }
        if (winner == 'O')
        {
            system("cls");
            show_board(k);
            cout << "congratulation " << o_player_name << " ,you won the game" << endl;
            break;
        }
        if (winner == 'D')
        {
            cout << "game is draw." << endl;
            break;
        }
    }
    k = 8;
    if (input == "yes"|| input =="YES")
    {
        cout << "DO YOU WANT TO PLAY AGAIN,ENTER YES OR NO" << endl;
        cin >> c;
        input = c;
        goto loop;
    }
}

int main()
{

    start_game();
    return 0;
}
