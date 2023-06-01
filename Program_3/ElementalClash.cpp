/*
Name: Amrit Thapa
Class: Cs-302-001


The "ElementalClash" class handles the gameplay of the "Elemental Clash" game.
It includes functions for initializing game settings, checking character name
existence, displaying player status, loading character information, displaying
a menu, executing attacks and special moves, displaying the character tree,
selecting characters, conducting battles, and starting the game.
*/
#include "ElementalClash.h"

// default constructor
ElementalClash::ElementalClash()
{
    turn = 1;
}

// destructor
ElementalClash::~ElementalClash()
{
}

// checks if the name exists
int ElementalClash::check(const string &name)
{
    for (size_t i = 0; i < character_names.size(); i++)
    {
        if (name == character_names[i])
        {
            return 1;
        }
    }
    throw 0;
}

// shows the status of the players
void ElementalClash::show_status()
{
    cout << " \n---- YOUR STATUS ----" << endl;
    player->display_status();
    cout << " \n---- OPPONENT STATUS ----" << endl;
    cpu->display_status();
}

// make all the letters lowercase
int ElementalClash::to_lower(string &name)
{
    for (char &letter : name)
    {
        letter = tolower(letter);
    }
    return 1;
}

// loads all the information in the tree
void ElementalClash ::load()
{
    string name, type, water_pressure, hardness, hotness;
    int health, damage, water_level, magic_water, hard_time, burn_time{};
    fstream file;
    file.open("roster.txt");
    if (file)
    {
        getline(file, type, '|');
        while (!file.eof())
        {
            getline(file, name, '|');
            to_lower(name);
            character_names.push_back(name);
            file >> health;
            file.ignore(100, '|');
            file >> damage;
            file.ignore(100, '|');
            Character character(name, type, health, damage);
            if (type == "WetWarriors")
            {
                getline(file, water_pressure, '|');
                file >> water_level;
                file.ignore(100, '|');
                file >> magic_water;
                file.ignore(100, '\n');
                WetWarriors warrior(character, water_pressure, water_level, magic_water);
                shared_ptr<Character> new_character = make_shared<WetWarriors>(warrior);
                database.insert(new_character, name);
            }
            if (type == "DirtyTitans")
            {
                getline(file, hardness, '|');
                file >> hard_time;
                file.ignore(100, '\n');
                DirtyTitans titan(character, hardness, hard_time);
                shared_ptr<Character> new_character = make_shared<DirtyTitans>(titan);
                database.insert(new_character, name);
            }
            if (type == "PyroDemons")
            {
                getline(file, hotness, '|');
                file >> burn_time;
                file.ignore(100, '\n');
                PyroDemons demon(character, hotness, burn_time);
                shared_ptr<Character> new_character = make_shared<PyroDemons>(demon);
                database.insert(new_character, name);
            }
            getline(file, type, '|');
        }
    }
}

// displays the menu of the possibilites
int ElementalClash ::menu(shared_ptr<Character> players)
{
    string type = players->get_type();
    int choice{};

    cout << "1: Attack" << endl;
    if (type == "WetWarriors")
    {
        cout << "2: Heal" << endl;
    }
    if (type == "DirtyTitans")
    {
        cout << "2: Ground Pound" << endl;
    }
    if (type == "PyroDemons")
    {
        cout << "2: Fiery Ball" << endl;
    }
    cout << "Pick a number: ";
    // cin >> choice;

    if (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(100, '\n');
        throw 0;
    }
    if (choice != 1 && choice != 2)
    {
        cin.ignore(100, '\n');
        throw 0;
    }
    else
    {
        cin.ignore(100, '\n');
    }

    return choice;
}

// attacks the computer
int ElementalClash::attack_cpu()
{
    cpu->defend(player->attack());
    return 1;
}

// arracks the player
int ElementalClash::attack_player()
{
    player->defend(cpu->attack());
    return 1;
}

// does the special moves of the character
void ElementalClash::special_move(shared_ptr<Character> players)
{

    string type = players->get_type();
    if (type == "WetWarriors")
    {
        shared_ptr<WetWarriors> wetwarriors = dynamic_pointer_cast<WetWarriors>(players);
        wetwarriors->heal();
    }
    if (type == "DirtyTitans")
    {
        shared_ptr<DirtyTitans> dirtytitans = dynamic_pointer_cast<DirtyTitans>(players);
        if (turn == 1)
        {
            cpu->defend(dirtytitans->ground_pound());
        }
        if (turn == 2)
        {
            player->defend(dirtytitans->ground_pound());
        }
    }
    if (type == "PyroDemons")
    {
        shared_ptr<PyroDemons> pyrodemons = dynamic_pointer_cast<PyroDemons>(players);
        if (turn == 1)
        {
            cpu->defend(pyrodemons->fiery_ball());
        }
        if (turn == 2)
        {
            player->defend(pyrodemons->fiery_ball());
        }
    }
}

// Displayes the whole tree of characters
void ElementalClash::display()
{
    cout << "\nCHARACTERS LIST" << endl;
    database.display();
    get_characters();
}

// Gets the name of the chosen charactes
void ElementalClash::get_characters()
{
    string name;
    int random_num;
    bool start = false;
    while (!start)
    {
        cout << "\nType in the character name: ";
        getline(cin, name);
        try
        {
            if (check(name))
            {
                player = database.fetch(name);
                start = true;
            }
        }
        catch (int)
        {
            cout << "sorry that character does not exist" << endl;
            cout << "Try again" << endl;
        }
    }
    srand(time(0));
    random_num = (rand() % 30) + 0;
    cpu = database.fetch(character_names.at(random_num));
    cout << " before " << endl;
    battle();
    if (player->health_status() <= 0)
    {
        cout << "Cpu Won" << endl;
    }
    if (cpu->health_status() <= 0)
    {
        cout << "You won" << endl;
    }
}

// does the battle functions
void ElementalClash ::battle()
{
    int choice{};
    int round = 1;
    srand(time(0));
    while (player->health_status() > 0 && cpu->health_status() > 0)
    {
        show_status();
        // system("pause");
        cout << "Press enter to continue..." << endl;
        cin.ignore();
        system("clear");
        cout << "\nROUND: " << round << endl;

        if (turn == 1)
        {
            while (true)
            {
                try
                {
                    choice = menu(player);
                    if (choice == 1)
                    {
                        attack_cpu();
                    }
                    if (choice == 2)
                    {
                        special_move(player);
                    }
                    turn = 2;
                    break;
                }
                catch (int)
                {
                    cout << "sorry that not a valid input" << endl;
                    cin.clear();
                }
            }
        }

        if (turn == 2)
        {
            choice = (rand() % 2) + 1;
            cout << "choice: " << choice << endl;
            if (choice == 1)
            {
                attack_player();
            }
            if (choice == 2)
            {
                special_move(cpu);
            }
            turn = 1;
        }
        ++round;
    }
}
// starts the battele
void ElementalClash::start_battle()
{
    load();
    display();
}