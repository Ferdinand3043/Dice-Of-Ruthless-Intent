#include <iostream>
#include <string>
using std::cout;
using std:: endl;
using std::cerr;

namespace {
const int kConsoleDisplayWidth = 80;
const int kDiceWidth = 12;
const std::string kDiceGap = "   ";

const char* const kDiceFaces[6][6] = {
    {" __________ ", "|          |", "|          |", "|     *    |", "|          |", "|__________|"},
    {" __________ ", "|          |", "|      *   |", "|          |", "|   *      |", "|__________|"},
    {" __________ ", "|          |", "|      *   |", "|     *    |", "|   *      |", "|__________|"},
    {" __________ ", "|          |", "|   *   *  |", "|          |", "|   *   *  |", "|__________|"},
    {" __________ ", "|          |", "|   *   *  |", "|     *    |", "|   *   *  |", "|__________|"},
    {" __________ ", "|          |", "|   *   *  |", "|   *   *  |", "|   *   *  |", "|__________|"}
};
}

void display_dice_images(const int values[], int count) {
    if (count <= 0) {
        cerr << "Cannot display a roll without dice." << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        if (values[i] < 1 || values[i] > 6) {
            cerr << "Cannot display a die with value " << values[i] << "." << endl;
            return;
        }
    }

    const int total_width = count * kDiceWidth + (count - 1) * static_cast<int>(kDiceGap.size());
    const int padding = (kConsoleDisplayWidth - total_width) / 2;
    for (int row = 0; row < 6; ++row) {
        if (padding > 0) {
            cout << std::string(padding, ' ');
        }
        for (int i = 0; i < count; ++i) {
            if (i > 0) {
                cout << kDiceGap;
            }
            cout << kDiceFaces[values[i] - 1][row];
        }
        cout << endl;
    }
}

void display_dice_image(int value){
    display_dice_images(&value, 1);
}
