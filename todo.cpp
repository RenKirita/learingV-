#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 関数宣言
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);

int main() {
    vector<string> tasks;
    int choice;

    cout << "シンプルなTo-Doリストへようこそ！" << endl;

    while (true) {
        cout << "\nメニュー：" << endl;
        cout << "1. タスクを追加" << endl;
        cout << "2. タスクを表示" << endl;
        cout << "3. タスクを削除" << endl;
        cout << "4. 終了" << endl;
        cout << "選択してください (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "終了します。さようなら！" << endl;
                return 0;
            default:
                cout << "無効な選択です。もう一度お試しください。" << endl;
        }
    }
}

// タスクを追加する関数
void addTask(vector<string>& tasks) {
    string task;
    cout << "追加するタスクを入力してください: ";
    cin.ignore();  // バッファをクリア
    getline(cin, task);
    tasks.push_back(task);
    cout << "タスクが追加されました。" << endl;
}

// タスクを表示する関数
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "タスクはありません。" << endl;
    } else {
        cout << "\nTo-Doリスト:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

// タスクを削除する関数
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "削除するタスクがありません。" << endl;
        return;
    }

    int index;
    cout << "削除するタスクの番号を入力してください: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "無効な番号です。" << endl;
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "タスクが削除されました。" << endl;
    }
}