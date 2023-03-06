
#include <iostream>

using namespace std;



// main  게임 구성
// - Enter Lobby
// -- CreatePlayer
// --- EnterGame
// ----CreateMonster
// ===== EnterBattle

/*
    플레이어 직업
*/
enum PlayerType
{
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3,
};


/*
    몬스터 종류
*/
enum MonsterType
{
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3,
};



/*
    플레이어 직업 스탯
*/
struct StatInfo
{
    int hp = 0;
    int attack = 0;
    int defence = 0;
};

// 함수 원형
void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);


int main()
{
    srand((unsigned)time(nullptr));
    EnterLobby();





    return 0;
}

void EnterLobby()
{
    while (true)
    {
        PrintMessage("로비에 입장했습니다");

        // 플레이어
        StatInfo playerInfo;
        CreatePlayer(&playerInfo);
        PrintStatInfo


    }
}

void PrintMessage(const char* msg)
{
    cout << "**********************" << endl;
    cout << msg << endl;
    cout << "**********************" << endl;
}

void CreatePlayer(StatInfo* playerInfo)
{
    bool ready = false;

    while (ready == false)
    {
        PrintMessage("캐릭터 생성 창");
        PrintMessage("1.기사  2.궁수  3.마법사");
        cout << " > ";

        int input;
        cin >> input;

        switch (input)
        {
        case PT_Knight:
            playerInfo->hp = 120;
            playerInfo->attack = 10;
            playerInfo->defence = 5;
            ready = true;

            break;

        case PT_Archer:
            playerInfo->hp = 100;
            playerInfo->attack = 8;
            playerInfo->defence = 3;
            ready = true;

            break;

        case PT_Mage:
            playerInfo->hp = 80;
            playerInfo->attack = 20;
            playerInfo->defence = 1;
            ready = true;

            break;

        default:
            break;
        }

    }

}

void PrintStatInfo(const char* name, const StatInfo& info)
{
    cout << "*********" << endl;
    cout << name << " : HP = " << info.hp << " ATT = " << info.attack << " DEF = " << info.defence << endl;
    cout << "*********" << endl;

}

