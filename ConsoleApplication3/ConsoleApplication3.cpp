#include <iostream>
#include <vector>
using namespace std;

class Information {
private:
    string name;
    int call;
public:
    Information(string n, int c) : name(n), call(c) {}
    string getName() const { return name; }
    int getCall() const { return call; }

    void setName(const string& n) { name = n; }
    void setCall(int c) { call = c; }
};

bool Check(const vector<Information>& members, const string& name, int call) {
    for (const auto& member : members) {
        if (member.getName() == name && member.getCall() == call) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<Information> members;
    string name;
    int call;

    while (true) {
        int a;
        cout << "***SWING 회원 정보 관리 프로그램***" << endl;
        cout << "1. 회원가입" << endl;
        cout << "2. 로그인" << endl;
        cout << "3. 회원 정보 수정" << endl;
        cout << "4. 종료" << endl;
        cout << "번호를 입력하세요: ";
        cin >> a;

        if (a == 1) {
            cout << "*** 회원가입을 진행합니다 ***" << endl;
            cout << "이름을 입력하세요: ";
            cin >> name;
            cout << "전화번호를 입력하세요: ";
            cin >> call;
            members.emplace_back(name, call); 
            cout << "회원가입이 완료되었습니다." << endl;
            continue;
        }

        if (a == 2) {
            cout << "*** 로그인을 진행합니다 ***" << endl;
            cout << "이름을 입력하세요: ";
            cin >> name;
            cout << "전화번호를 입력하세요: ";
            cin >> call;
            if (Check(members, name, call)) {
                cout << "로그인이 완료되었습니다." << endl;
                cout << "🌟🌟🌟 SWING " << name << "님을 응원합니다 🌟🌟🌟" << endl;
            }
            else {
                cout << "로그인 정보가 잘못되었습니다." << endl;
            }
            continue;
        }

        if (a == 3) {
            cout << "*** 회원 정보 수정을 진행합니다 ***" << endl;
            cout << "이름을 입력하세요: ";
            cin >> name;
            cout << "전화번호를 입력하세요: ";
            cin >> call;
            bool found = false;
            for (auto& member : members) {
                if (member.getName() == name && member.getCall() == call) {
                    cout << "새로운 이름을 입력하세요: ";
                    string newName;
                    cin >> newName;
                    cout << "새로운 전화번호를 입력하세요: ";
                    int newCall;
                    cin >> newCall;
                    member.setName(newName);
                    member.setCall(newCall);
                    cout << "회원 정보가 수정되었습니다." << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "회원 정보를 찾을 수 없습니다." << endl;
            }
            continue;
        }

        if (a == 4) {
            cout << "SWING 회원 정보 관리 프로그램을 종료합니다." << endl;
            break;
        }

        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }
    }
    return 0;
}
