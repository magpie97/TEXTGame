
#include <iostream>

using namespace std;



// main  ���� ����
// - Enter Lobby
// -- CreatePlayer
// --- EnterGame
// ----CreateMonster
// ===== EnterBattle

/*
    �÷��̾� ����
*/
enum PlayerType
{
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3,
};


/*
    ���� ����
*/
enum MonsterType
{
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3,
};



/*
    �÷��̾� ���� ����
*/
struct StatInfo
{
    int hp = 0;
    int attack = 0;
    int defence = 0;
};

// �Լ� ����
void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);





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
        PrintMessage("�κ� �����߽��ϴ�");

        // �÷��̾�
        StatInfo playerInfo;
        CreatePlayer(&playerInfo);
        PrintStatInfo("Player", playerInfo);

        EnterGame(&playerInfo);


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
        PrintMessage("ĳ���� ���� â");
        PrintMessage("1.���  2.�ü�  3.������");
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

void EnterGame(StatInfo* playerInfo)
{
    const int MONSTER_COUNT = 2;

    PrintMessage("���ӿ� ���� �Ͽ����ϴ�");
    

    while (true)
    {
        StatInfo monsterInfo[MONSTER_COUNT];
        CreateMonsters(monsterInfo, MONSTER_COUNT);

        for (int i = 0; i < MONSTER_COUNT; i++)
        {
            PrintStatInfo("Monster", monsterInfo[i]);


        }

        PrintStatInfo("Player", *playerInfo);

        PrintMessage("1. ����  2. ����  3. ����");
        int input;
        cin >> input;
        if (input == 1 || input == 2)
        {
            int index = input - 1;
            bool victory = EnterBattle(playerInfo, &monsterInfo[index]);
            if (victory == false)
                break;
        }


    }
}

void CreateMonsters(StatInfo monsterInfo[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int randValue = rand() % 3;


        switch (randValue)
        {
        case MT_Slime:
            monsterInfo->hp = 30;
            monsterInfo->attack = 2;
            monsterInfo->defence = 0;
        
            break;
        
        case MT_Skeleton:
            monsterInfo->hp = 15;
            monsterInfo->attack = 8;
            monsterInfo->defence = 1;
            
            break;

        case MT_Orc:
            monsterInfo->hp = 50;
            monsterInfo->attack = 10;
            monsterInfo->defence = 4;
            
            break;

        default:
            break;
        }

    }

}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
    while (true)
    {
        int damage = playerInfo->attack - monsterInfo->defence;
        if (damage < 0)
            damage = 0;

        monsterInfo->hp -= damage;
        if (monsterInfo->hp < 0)
            monsterInfo->hp = 0;

        PrintStatInfo("Monster", *monsterInfo);

        if (monsterInfo->hp == 0)
        {
            PrintMessage("���͸� óġ�߽��ϴ�");
            return true;
        }

        damage = monsterInfo->attack - playerInfo->defence;
        if (damage < 0)
            damage = 0;

        playerInfo->hp -= damage;
        if (playerInfo->hp < 0)
            playerInfo->hp = 0;


        PrintStatInfo("Player", *playerInfo);

        if (playerInfo->hp == 0)
        {
            PrintMessage("Game Over");

            return false;
        }

    }
    

    return false;
}

