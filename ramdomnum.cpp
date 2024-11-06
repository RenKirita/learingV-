#include <iostream>
#include <cstdlib>  // rand, srandを使用するために必要
#include <ctime>    // timeを使用してランダムシードを生成

using namespace std;

int main() {
    // ランダムシードを初期化
    srand(static_cast<unsigned int>(time(0)));

    // 1から100の間のランダムな数を生成
    int target = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "数当てゲームへようこそ！1から100の間の数を当ててください。" << endl;

    // ゲームのループ
    do {
        cout << "あなたの予想は？ ";
        cin >> guess;
        attempts++;

        if (guess > target) {
            cout << "もっと小さい数です。" << endl;
        } else if (guess < target) {
            cout << "もっと大きい数です。" << endl;
        } else {
            cout << "正解！ " << attempts << "回で当てました！" << endl;
        }

    } while (guess != target);

    return 0;
}