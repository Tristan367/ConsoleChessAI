#include <iostream>
#include <fstream>
#include <string>

class Position {
public:
    char board[64];
    short lastMove;
    Position() {
        for (short i = 0; i < 64; i++) {
            board[i] = '0';
        }
        lastMove = -1;
    }
};
void printBoard(Position position) {
    for (short i = 7; i >= 0; i--) {
        for (short j = 0; j < 8; j++) {
            std::cout << position.board[i * 8 + j] << ' ';
        }
        std::cout << '\n';
    }
}

bool pieceWouldBeCaptured(Position position, short square) {
    short whiteProtectors = 0; 
    short blackProtectors = 0;
    // check diagonals
    short move;
    for (short i = 1; i < 7; i++) {
        move = square + (9 * i);
        if (move < 64 && move % 8 != 0) { // forward right
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'p':
                {
                    if (i == 1) {
                        blackProtectors++;
                        i = 7; // break the loop
                    }
                    break;
                }
                case 'b':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'B':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
            
            
        }
        else
        {
            break; // reaching end of board
        }
    }
    for (short i = 1; i < 7; i++) {
        move = square - (7 * i);
        if (move >= 0 && move % 8 != 0) { // backward right
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'P':
                {
                    if (i == 1) {
                        whiteProtectors++;
                        i = 7; // break the loop
                    }
                    break;
                }
                case 'b':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'B':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
        }
        else
        {
            break; // reaching end of board
        }
    }
    for (short i = 1; i < 7; i++) {
        move = square + (7 * i);
        if (move < 64 && move % 8 != 7) { // forward left
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'p':
                {
                    if (i == 1) {
                        blackProtectors++;
                        i = 7; // break the loop
                    }
                    break;
                }
                case 'b':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'B':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
        }
        else
        {
            break; // reaching end of board
        }
    }
    for (short i = 1; i < 7; i++) {
        move = square - (9 * i);
        if (move >= 0 && move % 8 != 0) { // backward left
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'P':
                {
                    if (i == 1) {
                        whiteProtectors++;
                        i = 7; // break the loop
                    }
                    break;
                }
                case 'b':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'B':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
        }
        else
        {
            break; // reaching end of board
        }
    }
    // orthogonals
    for (short i = 1; i < 7; i++) {
        move = square + (8 * i);
        if (move < 64) { // forward
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'r':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'R':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
        }
        else
        {
            break; // reaching end of board
        }
    }
    for (short i = 1; i < 7; i++) {
        move = square - (8 * i);
        if (move >= 0) { // backward
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'r':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'R':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
        }
        else
        {
            break; // reaching end of board
        }
    }
    for (short i = 1; i < 7; i++) {
        move = square + i;
        if (move < 64 && move % 8 != 0) { // right
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'r':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'R':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
        }
        else
        {
            break; // reaching end of board
        }
    }
    for (short i = 1; i < 7; i++) {
        move = square - i;
        if (move >= 0 && move % 8 != 7) { // left
            if (position.board[move] != '0') {
                switch (position.board[move])
                {
                case 'r':
                {
                    blackProtectors++;
                    break;
                }
                case 'q':
                {
                    blackProtectors++;
                    break;
                }
                case 'R':
                {
                    whiteProtectors++;
                    break;
                }
                case 'Q':
                {
                    whiteProtectors++;
                    break;
                }

                default:
                {
                    i = 7;
                    break;
                }
                }
            }
        }
        else
        {
            break; // reaching end of board
        }
    }
    //knights
    if (move < 64 && move % 8 != 0 && move % 8 != 1) { // if it is within the bounds of the board
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }
    move = square + 17;
    if (move < 64 && move % 8 != 0) {
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }
    move = square + 15;
    if (move < 64 && move % 8 != 7) {
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }
    move = square + 6;
    if (move < 64 && move % 8 != 7 && move % 8 != 6) {
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }
    move = square - 15;
    if (move >= 0 && move % 8 != 0) {
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }
    move = square - 6;
    if (move >= 0 && move % 8 != 0 && move % 8 != 1) {
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }
    move = square - 17;
    if (move >= 0 && move % 8 != 7) {
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }
    move = square - 10;
    if (move >= 0 && move % 8 != 7 && move % 8 != 6) {
        if (position.board[move] == 'n') {
            blackProtectors++;
        }
        if (position.board[move] == 'N') {
            whiteProtectors++;
        }
    }

    if (position.board[square] > 96) {
        if (whiteProtectors >= blackProtectors) {
            return true;
        }
    }
    if (position.board[square] < 96 && position.board[square] != '0') {
        if (blackProtectors >= whiteProtectors) {
            return true;
        }
    }
    return false;
}

float heuristicValue(Position position) {
    short moveCounter = 0;
    short moveCounterBlack = 0;
    short objectiveValue = 0;
    for (short i = 0; i < 64; i++) {
        short square = i;
        switch (position.board[square])
        {
        case '0': // empty
        {
            break;
        }
        case 'P': // white pawn
        {
            objectiveValue += 1;
            short move = square + 8;
            if (move < 64) {
                if (position.board[move] == '0') { // forward one
                    moveCounter++;
                }
                if (square % 8 != 0) { // diagonal left
                    move = square + 7;
                    if (position.board[move] > 96) { // is a black piece in that square
                        moveCounter++;
                    }
                }
                if (square % 8 != 7) { // diagonal right
                    move = square + 9;
                    if (position.board[move] > 96) { // is a black piece in that square
                        moveCounter++;
                    }
                }
            }
            break;
        }

        case 'N': // white knight
        {
            objectiveValue += 3;
            short move = square + 10;
            if (move < 64 && move % 8 != 0 && move % 8 != 1) { // if it is within the bounds of the board
                if (position.board[move] > 96 || position.board[move] == '0') { // if it is either empty or has an enemy piece in it
                    moveCounter++;
                }
            }
            move = square + 17;
            if (move < 64 && move % 8 != 0) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square + 15;
            if (move < 64 && move % 8 != 7) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square + 6;
            if (move < 64 && move % 8 != 7 && move % 8 != 6) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 15;
            if (move >= 0 && move % 8 != 0) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 6;
            if (move >= 0 && move % 8 != 0 && move % 8 != 1) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 17;
            if (move >= 0 && move % 8 != 7) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 10;
            if (move >= 0 && move % 8 != 7 && move % 8 != 6) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            break;
        }

        case 'B': // white bishop
        {
            objectiveValue += 3;
            short move;
            for (short i = 1; i < 7; i++) {
                move = square + (9 * i);
                if (move < 64 && move % 8 != 0) { // forward right
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (7 * i);
                if (move >= 0 && move % 8 != 0) { // backward right
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + (7 * i);
                if (move < 64 && move % 8 != 7) { // forward left
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (9 * i);
                if (move >= 0 && move % 8 != 0) { // backward left
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            break;

        }

        case 'R': // white rook
        {
            objectiveValue += 5;
            short move;
            for (short i = 1; i < 7; i++) {
                move = square + (8 * i);
                if (move < 64) { // forward
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (8 * i);
                if (move >= 0) { // backward
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + i;
                if (move < 64 && move % 8 != 0) { // right
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - i;
                if (move >= 0 && move % 8 != 7) { // left
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            break;
        }

        case 'Q': // white queen
        {
            objectiveValue += 9;
            /*
            short move;
            for (short i = 1; i < 7; i++) {
                move = square + (9 * i);
                if (move < 64 && move % 8 != 0) { // forward right
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (7 * i);
                if (move >= 0 && move % 8 != 0) { // backward right
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + (7 * i);
                if (move < 64 && move % 8 != 7) { // forward left
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (9 * i);
                if (move >= 0 && move % 8 != 0) { // backward left
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + (8 * i);
                if (move < 64) { // forward
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (8 * i);
                if (move >= 0) { // backward
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + i;
                if (move < 64 && move % 8 != 0) { // right
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - i;
                if (move >= 0 && move % 8 != 7) { // left
                    if (position.board[move] > 96 || position.board[move] == '0') {
                        moveCounter++;
                        if (position.board[move] > 96) {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            */
            break;
        }

        case 'K': // white king
        {
            objectiveValue += 100;
            short move = square + 8;
            if (move < 64) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square + 9;
            if (move < 64 && move % 8 != 0) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square + 7;
            if (move < 64 && move % 8 != 7) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 9;
            if (move >= 0 && move % 8 != 7) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 8;
            if (move >= 0) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 7;
            if (move >= 0 && move % 8 != 0) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square + 1;
            if (move < 64 && move % 8 != 0) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            move = square - 1;
            if (move >= 0 && move % 8 != 7) {
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                }
            }
            break;
        }

        case 'p': // black pawn
        {
            objectiveValue -= 1;
            short move = square - 8;
            if (move >= 0) {
                if (position.board[move] == '0') { // forward one
                    moveCounterBlack++;
                }
                if (square % 8 != 0) { // down left
                    move = square - 9;
                    if (position.board[move] < 96 && position.board[move] > 64) { // a white piece in that square
                        moveCounterBlack++;
                    }
                }
                if (square % 8 != 7) { // down right
                    move = square - 7;
                    if (position.board[move] < 96 && position.board[move] > 64) { // a white piece in that square
                        moveCounterBlack++;
                    }
                }
            }
            break;
        }

        case 'n': // black knight
        {
            objectiveValue -= 3;
            short move = square + 10;
            if (move < 64 && move % 8 != 0 && move % 8 != 1) { // if it is within the bounds of the board
                if (position.board[move] < 96) { // if it is either empty or has an enemy piece in it
                    moveCounterBlack++;
                }
            }
            move = square + 17;
            if (move < 64 && move % 8 != 0) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square + 15;
            if (move < 64 && move % 8 != 7) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square + 6;
            if (move < 64 && move % 8 != 7 && move % 8 != 6) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 15;
            if (move >= 0 && move % 8 != 0) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 6;
            if (move >= 0 && move % 8 != 0 && move % 8 != 1) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 17;
            if (move >= 0 && move % 8 != 7) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 10;
            if (move >= 0 && move % 8 != 7 && move % 8 != 6) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            break;
        }

        case 'b': // black bishop
        {
            objectiveValue -= 3;
            short move;
            for (short i = 1; i < 7; i++) {
                move = square + (9 * i);
                if (move < 64 && move % 8 != 0) { // forward right
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (7 * i);
                if (move >= 0 && move % 8 != 0) { // backward right
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + (7 * i);
                if (move < 64 && move % 8 != 7) { // forward left
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (9 * i);
                if (move >= 0 && move % 8 != 0) { // backward left
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            break;

        }

        case 'r': // black rook
        {
            objectiveValue -= 5;
            short move;
            for (short i = 1; i < 7; i++) {
                move = square + (8 * i);
                if (move < 64) { // forward
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (8 * i);
                if (move >= 0) { // backward
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + i;
                if (move < 64 && move % 8 != 0) { // right
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - i;
                if (move >= 0 && move % 8 != 7) { // left
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            break;
        }

        case 'q': // black queen
        {
            objectiveValue -= 9;
            /*
            short move;
            for (short i = 1; i < 7; i++) {
                move = square + (9 * i);
                if (move < 64 && move % 8 != 0) { // forward right
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (7 * i);
                if (move >= 0 && move % 8 != 0) { // backward right
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + (7 * i);
                if (move < 64 && move % 8 != 7) { // forward left
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (9 * i);
                if (move >= 0 && move % 8 != 0) { // backward left
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + (8 * i);
                if (move < 64) { // forward
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - (8 * i);
                if (move >= 0) { // backward
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square + i;
                if (move < 64 && move % 8 != 0) { // right
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            for (short i = 1; i < 7; i++) {
                move = square - i;
                if (move >= 0 && move % 8 != 7) { // left
                    if (position.board[move] < 96) {
                        moveCounterBlack++;
                        if (position.board[move] != '0') {
                            break; // obstructed by an enemy piece, stop looking in this direction
                        }
                    }
                    else
                    {
                        break; // stop looking in this direction when we see a freindly piece
                    }
                }
                else
                {
                    break; // reaching end of board
                }
            }
            */
            break;
        }

        case 'k': // black king
        {
            objectiveValue -= 100;
            short move = square + 8;
            if (move < 64) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square + 9;
            if (move < 64 && move % 8 != 0) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square + 7;
            if (move < 64 && move % 8 != 7) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 9;
            if (move >= 0 && move % 8 != 7) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 8;
            if (move >= 0) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 7;
            if (move >= 0 && move % 8 != 0) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square + 1;
            if (move < 64 && move % 8 != 0) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            move = square - 1;
            if (move >= 0 && move % 8 != 7) {
                if (position.board[move] < 96) {
                    moveCounterBlack++;
                }
            }
            break;
        }

        default:
            break;
        }
    }
    float value = (float)objectiveValue + (((float)moveCounter) / 100.0f) - (((float)moveCounterBlack) / 100.0f);
    return value;
}

short countWhiteMoves(Position position, short square) {
    short moveCounter = 0;
    switch (position.board[square])
    {
    case 'P': // white pawn
    {
        short move = square + 8;
        if (move < 64) {
            if (position.board[move] == '0') { // forward one
                moveCounter++;
            }
            if (square % 8 != 0) { // diagonal left
                move = square + 7;
                if (position.board[move] > 96) { // is a black piece in that square
                    moveCounter++;
                }
            }
            if (square % 8 != 7) { // diagonal right
                move = square + 9;
                if (position.board[move] > 96) { // is a black piece in that square
                    moveCounter++;
                }
            }
        }
        break;
    }

    case 'N': // white knight
    {
        short move = square + 10;
        if (move < 64 && move % 8 != 0 && move % 8 != 1) { // if it is within the bounds of the board
            if (position.board[move] > 96 || position.board[move] == '0') { // if it is either empty or has an enemy piece in it
                moveCounter++;
            }
        }
        move = square + 17;
        if (move < 64 && move % 8 != 0) {
            if (position.board[move] > 96 || position.board[move] == '0') { 
                moveCounter++;
            }
        }
        move = square + 15;
        if (move < 64 && move % 8 != 7) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square + 6;
        if (move < 64 && move % 8 != 7 && move % 8 != 6) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 15;
        if (move >= 0 && move % 8 != 0) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 6;
        if (move >= 0 && move % 8 != 0 && move % 8 != 1) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 17;
        if (move >= 0 && move % 8 != 7) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 10;
        if (move >= 0 && move % 8 != 7 && move % 8 != 6) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        break;
    }

    case 'B': // white bishop
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;

    }

    case 'R': // white rook
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'Q': // white queen
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (position.board[move] > 96 || position.board[move] == '0') {
                    moveCounter++;
                    if (position.board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'K': // white king
    {
        short move = square + 8;
        if (move < 64) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square + 9;
        if (move < 64 && move % 8 != 0) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square + 7;
        if (move < 64 && move % 8 != 7) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 9;
        if (move >= 0 && move % 8 != 7) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 8;
        if (move >= 0) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 7;
        if (move >= 0 && move % 8 != 0) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square + 1;
        if (move < 64 && move % 8 != 0) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        move = square - 1;
        if (move >= 0 && move % 8 != 7) {
            if (position.board[move] > 96 || position.board[move] == '0') {
                moveCounter++;
            }
        }
        break;
    }

    default:
        break;
    }

    return moveCounter;
}
short countBlackMoves(Position position, short square) {
    short moveCounter = 0;
    switch (position.board[square])
    {
    case 'p': // black pawn
    {
        short move = square - 8;
        if (move >= 0) {
            if (position.board[move] == '0') { // forward one
                moveCounter++;
            }
            if (square % 8 != 0) { // down left
                move = square - 9;
                if (position.board[move] < 96 && position.board[move] > 64) { // a white piece in that square
                    moveCounter++;
                }
            }
            if (square % 8 != 7) { // down right
                move = square - 7;
                if (position.board[move] < 96 && position.board[move] > 64) { // a white piece in that square
                    moveCounter++;
                }
            }
        }
        break;
    }

    case 'n': // black knight
    {
        short move = square + 10;
        if (move < 64 && move % 8 != 0 && move % 8 != 1) { // if it is within the bounds of the board
            if (position.board[move] < 96) { // if it is either empty or has an enemy piece in it
                moveCounter++;
            }
        }
        move = square + 17;
        if (move < 64 && move % 8 != 0) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square + 15;
        if (move < 64 && move % 8 != 7) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square + 6;
        if (move < 64 && move % 8 != 7 && move % 8 != 6) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 15;
        if (move >= 0 && move % 8 != 0) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 6;
        if (move >= 0 && move % 8 != 0 && move % 8 != 1) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 17;
        if (move >= 0 && move % 8 != 7) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 10;
        if (move >= 0 && move % 8 != 7 && move % 8 != 6) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        break;
    }

    case 'b': // black bishop
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;

    }

    case 'r': // black rook
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'q': // black queen
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (position.board[move] < 96) {
                    moveCounter++;
                    if (position.board[move] != '0') {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'k': // black king
    {
        short move = square + 8;
        if (move < 64) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square + 9;
        if (move < 64 && move % 8 != 0) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square + 7;
        if (move < 64 && move % 8 != 7) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 9;
        if (move >= 0 && move % 8 != 7) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 8;
        if (move >= 0) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 7;
        if (move >= 0 && move % 8 != 0) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square + 1;
        if (move < 64 && move % 8 != 0) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        move = square - 1;
        if (move >= 0 && move % 8 != 7) {
            if (position.board[move] < 96) {
                moveCounter++;
            }
        }
        break;
    }

    default:
        break;
    }

    return moveCounter;
}
void copyPosition(Position& dst, Position src) {
    for (short i = 0; i < 64; i++) {
        dst.board[i] = src.board[i];
    }
}
void createNewPosition(Position positions[], short index, short fromSqr, short toSqr) {
    copyPosition(positions[index+1], positions[index]); // copying the current position into the next position
    positions[index + 1].lastMove = toSqr; // storing the last move
    positions[index + 1].board[toSqr] = positions[index + 1].board[fromSqr]; // moving the piece
    positions[index + 1].board[fromSqr] = '0'; // making the square it came from empty
}
float getHeuristicValue(Position position) {
    float value = 0.0f;
    for (short i = 0; i < 64; i++) {
        switch (position.board[i])
        {
        case '0':
        {
            break;
        }
        case 'P':
        {
            value += 1.0f;
            break;
        }
        case 'N':
        {
            value += 3.0f;
            break;
        }
        case 'B':
        {
            value += 3.0f;
            break;
        }
        case 'R':
        {
            value += 5.0f;
            break;
        }
        case 'Q':
        {
            value += 9.0f;
            break;
        }
        case 'K':
        {
            value += 100.0f;
            break;
        }

        case 'p':
        {
            value -= 1.0f;
            break;
        }
        case 'n':
        {
            value -= 3.0f;
            break;
        }
        case 'b':
        {
            value -= 3.0f;
            break;
        }
        case 'r':
        {
            value -= 5.0f;
            break;
        }
        case 'q':
        {
            value -= 9.0f;
            break;
        }
        case 'k':
        {
            value -= 100.0f;
            break;
        }

        default:
            break;
        }
    }


    return value;
}
float miniMax(Position positions[], short depth, bool white);
float recurseWHITE(Position positions[], short positionIndex, short depth, short square, short &bestMove) {
    float value = -1000.0f;
    float val;
    switch (positions[positionIndex].board[square])
    {
    case 'P': // white pawn
    {
        short move = square + 8;
        if (move < 64) {
            if (positions[positionIndex].board[move] == '0') { // forward one
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
            if (square % 8 != 0) { // diagonal left
                move = square + 7;
                if (positions[positionIndex].board[move] > 96) { // is a black piece in that square
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }
                }
            }
            if (square % 8 != 7) { // diagonal right
                move = square + 9;
                if (positions[positionIndex].board[move] > 96) { // is a black piece in that square
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }
                }
            }
        }
        break;
    }

    case 'N': // white knight
    {
        short move = square + 10;
        if (move < 64 && move % 8 != 0 && move % 8 != 1) { // if it is within the bounds of the board
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') { // if it is either empty or has an enemy piece in it
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 17;
        if (move < 64 && move % 8 != 0) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 15;
        if (move < 64 && move % 8 != 7) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 6;
        if (move < 64 && move % 8 != 7 && move % 8 != 6) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 15;
        if (move >= 0 && move % 8 != 0) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 6;
        if (move >= 0 && move % 8 != 0 && move % 8 != 1) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 17;
        if (move >= 0 && move % 8 != 7) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 10;
        if (move >= 0 && move % 8 != 7 && move % 8 != 6) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        break;
    }

    case 'B': // white bishop
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }    
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }    
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }       
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
        
    }
    
    case 'R': // white rook
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }  
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    } 
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }     
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }   
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'Q': // white queen
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    } 
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }  
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }      
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    } 
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    } 
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, false);
                    if (val > value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] > 96) {
                        break; // obstructed by an enemy piece, stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'K': // white king
    {
        short move = square + 8;
        if (move < 64) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 9;
        if (move < 64 && move % 8 != 0) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 7;
        if (move < 64 && move % 8 != 7) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 9;
        if (move >= 0 && move % 8 != 7) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 8;
        if (move >= 0) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 7;
        if (move >= 0 && move % 8 != 0) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 1;
        if (move < 64 && move % 8 != 0) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 1;
        if (move >= 0 && move % 8 != 7) {
            if (positions[positionIndex].board[move] > 96 || positions[positionIndex].board[move] == '0') {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, false);
                if (val > value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        break;
    }

    default:
         break;
    }

    return value;
}
float recurseBLACK(Position positions[], short positionIndex, short depth, short square, short& bestMove) {
    float value = 1000.0f;
    float val;
    switch (positions[positionIndex].board[square])
    {
    case 'p': // black pawn
    {
        short move = square - 8;
        if (move >= 0) {
            if (positions[positionIndex].board[move] == '0') { // forward one
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
            if (square % 8 != 0) { // down left
                move = square - 9;
                if (positions[positionIndex].board[move] < 96 && positions[positionIndex].board[move] > 64) { // a white piece in that square
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                }
            }
            if (square % 8 != 7) { // down right
                move = square - 7;
                if (positions[positionIndex].board[move] < 96 && positions[positionIndex].board[move] > 64) { // a white piece in that square
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                }
            }
        }
        break;
    }

    case 'n': // black knight
    {
        short move = square + 10;
        if (move < 64 && move % 8 != 0) { // if it is within the bounds of the board
            if (positions[positionIndex].board[move] < 96) { // either empty or an enemy piece is there
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 17;
        if (move < 64 && move % 8 != 0) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 15;
        if (move < 64 && move % 8 != 7) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 6;
        if (move < 64 && move % 8 != 7) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 15;
        if (move >= 0 && move % 8 != 0) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 6;
        if (move >= 0 && move % 8 != 0) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 17;
        if (move >= 0 && move % 8 != 7) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 10;
        if (move >= 0 && move % 8 != 7) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        break;
    }

    case 'b': // black bishop
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'r': // black rook
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'q': // black queen
    {
        short move;
        for (short i = 1; i < 7; i++) {
            move = square + (9 * i);
            if (move < 64 && move % 8 != 0) { // forward right
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (7 * i);
            if (move >= 0 && move % 8 != 0) { // backward right
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (7 * i);
            if (move < 64 && move % 8 != 7) { // forward left
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (9 * i);
            if (move >= 0 && move % 8 != 0) { // backward left
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + (8 * i);
            if (move < 64) { // forward
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - (8 * i);
            if (move >= 0) { // backward
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square + i;
            if (move < 64 && move % 8 != 0) { // right
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        for (short i = 1; i < 7; i++) {
            move = square - i;
            if (move >= 0 && move % 8 != 7) { // left
                if (positions[positionIndex].board[move] < 96) {
                    createNewPosition(positions, positionIndex, square, move);
                    val = miniMax(positions, depth - 1, true);
                    if (val < value) {
                        value = val;
                        bestMove = move;
                    }
                    if (positions[positionIndex].board[move] != '0') {
                        break; // obstructed by an enemy piece,stop looking in this direction
                    }
                }
                else
                {
                    break; // stop looking in this direction when we see a freindly piece
                }
            }
            else
            {
                break; // reaching end of board
            }
        }
        break;
    }

    case 'k': // black king
    {
        short move = square + 8;
        if (move < 64) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 9;
        if (move < 64 && move % 8 != 0) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 7;
        if (move < 64 && move % 8 != 7) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 9;
        if (move >= 0 && move % 8 != 7) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 8;
        if (move >= 0) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 7;
        if (move >= 0 && move % 8 != 0) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square + 1;
        if (move < 64 && move % 8 != 0) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        move = square - 1;
        if (move >= 0 && move % 8 != 7) {
            if (positions[positionIndex].board[move] < 96) {
                createNewPosition(positions, positionIndex, square, move);
                val = miniMax(positions, depth - 1, true);
                if (val < value) {
                    value = val;
                    bestMove = move;
                }
            }
        }
        break;
    }
        
    default:
        break;
    }
    return value;
}


short bestMoveFrom, bestMoveTo; // where we store the best move
float miniMax(Position positions[], short depth, bool white) {
    static short staticDepth = depth;
    short depthIndex = staticDepth - depth;
    float value = 1000.0f; // assigning just in case 
    if (white) {
        value = -1000.0f;
    }
    if (depth > 0) {
        if (white) {
            for (short i = 0; i < 64; i++) {
                if (positions[depthIndex].board[i] < 96 && positions[depthIndex].board[i] != '0') {
                    short bestMoveOfSquare = -1;
                    float val = recurseWHITE(positions, depthIndex, depth, i, bestMoveOfSquare); // get's best move for a given square
                    if (val > value) {
                        if (depth == staticDepth) { // if we are the origin, store this move as the best move
                            bestMoveFrom = i;
                            bestMoveTo = bestMoveOfSquare;
                        }
                        value = val;
                    }
                    
                    /*
                    //DEGUBBING STUFF
                    if (depth == staticDepth) {
                        std::cout << '\n';
                        std::cout << "value: " << value << '\n';
                        std::cout << "piece: " << positions[depthIndex].board[i] << '\n';
                    }
                    */
                }
            }
        }
        else
        {
            for (short i = 0; i < 64; i++) {
                if (positions[depthIndex].board[i] > 96) {
                    short bestMoveOfSquare = -1;
                    float val = recurseBLACK(positions, depthIndex, depth, i, bestMoveOfSquare);
                    if (val < value) {
                        if (depth == staticDepth) { // if we are the origin, store this move as the best move
                            bestMoveFrom = i;
                            bestMoveTo = bestMoveOfSquare;
                        }
                        value = val;
                    }

                    /*
                    //DEGUBBING STUFF
                    if (depth == staticDepth) {
                        std::cout << '\n';
                        std::cout << "valueBLACK: " << value << '\n';
                        std::cout << "piece: " << positions[depthIndex].board[i] << '\n';
                    }
                    */
                }
            }
        }
    }
    else
    {
        if (positions[depthIndex - 1].board[positions[depthIndex].lastMove] != '0') { // we captured a piece on the deepest layer
            if (pieceWouldBeCaptured(positions[depthIndex], positions[depthIndex].lastMove)) { // if it would be captured back
                positions[depthIndex].board[positions[depthIndex].lastMove] = '0'; // removing the piece to score the position as if it were captured back
            }
        }
        //value = getHeuristicValue(positions[depthIndex]); // assigning value of the position
        value = heuristicValue(positions[depthIndex]); // assigning value of the position

       /*
        if (positions[1].board[34] == 'p') {
            if (value == 0) {
                std::cout << '\n';
                std::cout << "printing debug board!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                printBoard(positions[depthIndex]);
                //std::cout << "value: " << value << '\n';
                std::cout << '\n';
            }
        }
        */
    }
    return value;
}

void arrangeStartingBoard(Position &position) {
    for (short i = 16; i < 48; i++) {
        position.board[i] = '0';
    }
    for (short i = 8; i < 16; i++) {
        position.board[i] = 'P';
    }
    for (short i = 48; i < 56; i++) {
        position.board[i] = 'p';
    }
    position.board[0] = 'R';
    position.board[1] = 'N';
    position.board[2] = 'B';
    position.board[3] = 'Q';
    position.board[4] = 'K';
    position.board[5] = 'B';
    position.board[6] = 'N';
    position.board[7] = 'R';

    position.board[56] = 'r';
    position.board[57] = 'n';
    position.board[58] = 'b';
    position.board[59] = 'q';
    position.board[60] = 'k';
    position.board[61] = 'b';
    position.board[62] = 'n';
    position.board[63] = 'r';
}

void savePosition(Position position, std::string path) {
    std::ofstream myfile;
    myfile.open(path);

    for (short i = 0; i < 64; i++) {
        myfile << position.board[i];
        if (i % 8 == 7) {
            myfile << '\n';
        }
    }
    myfile.close();
}
void loadPosition(Position &dst, std::string path) {
    std::string line;
    std::string lines;
    std::ifstream myfile(path);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
                lines += line;
        }
        myfile.close();
    }
    else std::cout << "Unable to open file\n";
    for (short i = 0; i < 72; i++) { // 72 to include the line endings
        dst.board[i] = lines[i];
    }
}

int main()
{
    
    const short depth = 5;
    Position positions[depth + 1];
    arrangeStartingBoard(positions[0]);
    //loadPosition(positions[0], "debug6.txt");

    Position lastPosition = Position();
    copyPosition(lastPosition, positions[0]);

    printBoard(positions[0]);
    std::string input;

    while (true)
    {
        std::cin >> input;
        if (input[0] == 'S') {
            std::cin >> input;
            savePosition(lastPosition, input);
        }
        if (input[0] == 'L') {
            std::cin >> input;
            loadPosition(positions[0], input);
        }
        copyPosition(lastPosition, positions[0]);

        static bool whiteToMove = true;

        if (input[0] == 'W') {
            whiteToMove = true;
        }
        if (input[0] == 'B') {
            whiteToMove = false;
        }

        miniMax(positions, depth, whiteToMove);
        positions[0].board[bestMoveTo] = positions[0].board[bestMoveFrom];
        positions[0].board[bestMoveFrom] = '0';
        whiteToMove = !whiteToMove;

        printBoard(positions[0]);

    }

}

// lower case = black, uppercase = white, empty is '0'
//


