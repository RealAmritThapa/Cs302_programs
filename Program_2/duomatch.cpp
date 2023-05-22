/*
Name: Amrit Thapa
Class: Cs-302-001
Program #2
//final
purpose:
This code implements a Duomatch game with player and game logic. The Player class
represents a player with attributes such as name, level, and position. It provides
functions for displaying player information, checking the path for cards and applying
their effects. The Duomatch class manages the game, including player turns, game states,
loading card data, initializing the game, and rolling the dice. It also handles the creation
of the game path, fills it with cards, and provides functions for displaying game information
and a welcome message.
*/
#include "duomatch.h"
// ====================== PLAYER =======================

// constructor
Player ::Player() : level(0)
{
}

// destructor
Player ::~Player()
{
    level = 0;
}

// constructor with paramaters
Player ::Player(string &user_name, int user_level, shared_ptr<Level_node> data) : name(user_name), level(user_level)
{
    current_position = data;
}

// displays the players information
void Player ::display_player()
{
    // cout << "========= PLAYER INFO ==============\n";
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
}

// cheeck the info of the path they are on
// then updates levels
int Player ::path_check(int game_level, int roll)
{
    int state{};
    if (current_position->has_card())
    {
        int type = current_position->cards_type();
        int effect = 0;

        if (type == 1)
        {
            int current_level{};
            cout << "you have landed on an obstacle card" << endl;
            effect = current_position->display_node(current_level);
            level = current_level + effect;
            if (level < 1)
            {
                level = 1;
            }
        }
        if (type == 2)
        {
            string answer;
            int current_level{};
            cout << "you have landed on an challenege card" << endl;
            current_position->display_node(current_level);
            cout << "please enter you answer to move on: ";
            getline(cin, answer);
            if (current_position->check_answer(answer))
            {
                cout << "well done you may move on" << endl;
                effect = current_position->effect();
                level = current_level + effect;
            }
            else
            {
                level = current_level + 1;
                cout << "sorry that is incorrect." << endl;
                cout << "you will only be able to move one step forward" << endl;
            }
        }
        if (type == 3)
        {
            int current_level{};
            cout << "you have landed on an reward card" << endl;
            current_position->display_node(current_level);
            level = current_level + roll;
        }
    }
    else
    {
        int current_level{};
        int effect{};
        effect = current_position->display_node(current_level);
        level = level + roll;
        // cout << "you got lucky no card" << endl;
    }

    // cout << "you new level is: " << level << endl;
    if (level >= game_level)
    {
        system("clear");
        cout << "\n------  WINNER -----" << endl;
        cout << "congrats " << name << " you won\n"
             << endl;
        level = game_level;
        state = 1;
    }
    return state;
}

// equality overloaded
Player &Player::operator=(const shared_ptr<Level_node> &data)
{
    current_position = data;
    storage.insert(storage.begin(), data);
    return *this;
}

// inserts infor into players
istream &operator>>(istream &input, Player &player)
{
    getline(input, player.name);
    return input;
}

// returns the level of the player
void Player ::get_level(int &move)
{
    move += level;
}

// generates all the cards they got during the game
void Player ::report()
{
    for (const auto &element : storage)
    {
        element->effect();
    }
}
// ====================== DUOMATCH =======================

// constructor with preset default level
Duomatch ::Duomatch() : levels(10), turn(1) {}

// destructor
Duomatch ::~Duomatch()
{
    levels = 0;
    turn = 0;
}

// gathers the info of the players
void Duomatch::get_player_info()
{
    int age = 0;
    string user_name;
    shared_ptr<Level_node> data = path_manager.move_player(0);
    Player player1;
    cout << "lets get some player info: " << endl;
    cout << "===== PLAYER 1 =====" << endl;
    cout << "Name =>  ";
    cin >> player1;
    player1 = data;
    player_1 = player1;
    cout << "===== PLAYER 2 =====" << endl;
    // cin.ignore(100, '\n');
    Player player2;
    cout << "Name =>  ";
    cin >> player2;
    player2 = data;
    player_2 = player2;
}

// starts the whole game with all the necessary function
void Duomatch ::start()
{
    int state = 0;
    welcome();
    load();
    // obstacle_card.display();
    cout << "\nhow many levels would you like(chose more than 15) => ";
    cin >> levels;
    cin.ignore(100, '\n');
    fill_path();
    get_player_info();
    system("clear");
    cout << "\n------ PLAYER 1 INFO" << endl;
    player_1.display_player();
    cout << "\n------ PLAYER 2 INFO" << endl;
    player_2.display_player();

    cout << ">>> Perfect! let the games begin <<<" << endl;

    while (state == 0)
    {
        state = main_game();
    }
    cout << "-----PLAYER 1: REPORT-----" << endl;
    player_1.report();
    cout << "-----PLAYER 2: REPORT-----" << endl;
    player_2.report();
}

// this is where the game logic starts
int Duomatch::main_game()
{

    int roll = 0;
    int move = 0;
    int state = 0;
    if (turn == 1)
    {
        cout << "\n-------------PLAYER 1 TURN------------------" << endl;
        cout << "Press 1 to roll die => ";
        cin >> roll;
        cin.ignore(100, '\n');
        if (roll == 1)
        {
            move = roll_die();
            roll = move;
            cout << "you rolled: " << move << endl;
            player_1.get_level(move);
            player_1 = path_manager.move_player(move);
            state = player_1.path_check(levels, roll);

            if (state == 1)
            {
                return state;
            }
            turn = 2;
        }
    }
    if (turn == 2)
    {
        cout << "\n-------------PLAYER 2 TURN------------------" << endl;
        cout << "Press 1 to a roll die => ";
        cin >> roll;
        cin.ignore(100, '\n');
        if (roll == 1)
        {
            move = roll_die();
            roll = move;
            // cout << "you rolled: " << roll << endl;
            player_2.get_level(move);
            cout << "you rolled: " << roll << endl;
            player_2 = path_manager.move_player(move);
            state = player_2.path_check(levels, roll);

            if (state == 1)
            {
                return state;
            }
            turn = 1;
        }
    }
    system("clear");
    cout << "\n____ Updated ___" << endl;
    player_1.display_player();
    cout << "\n____ Updated ___" << endl;
    player_2.display_player();

    return state;
}

// loads all the cards into LLL
void Duomatch::load()
{
    string type;
    char name[100];
    string description;
    string effect;
    int step_back{};
    name[0] = '\0';
    string question;
    string answer;
    string token;
    string reward_power;
    int move_forward{};

    ifstream file_loader;
    file_loader.open("cards.txt");

    if (file_loader)
    {
        getline(file_loader, type, ',');
        while (!file_loader.eof())
        {
            file_loader.get(name, 100, ',');
            file_loader.ignore(100, ',');
            getline(file_loader, description, ',');
            Card card(name, type, description);
            if (type == "obstacle")
            {
                getline(file_loader, effect, ',');
                file_loader >> step_back;
                file_loader.ignore(100, '\n');
                Obstacle obstacle(card, step_back, effect);
                // cout << obstacle << endl;
                // obstacle_card.insert(obstacle);
                obstacle_card += obstacle;
            }

            if (type == "challenge")
            {
                getline(file_loader, question, ',');
                getline(file_loader, answer, ',');
                file_loader >> move_forward;
                file_loader.ignore(100, '\n');
                Challenge challenge(card, question, answer, move_forward);
                challenge_card += challenge;
                // challenge_card.insert(challenge);
            }

            if (type == "reward")
            {
                getline(file_loader, token, ',');
                getline(file_loader, reward_power, ',');
                file_loader >> move_forward;
                file_loader.ignore(100, '\n');
                Reward reward(card, move_forward, token, reward_power);
                reward_card += reward;
                // reward_card.insert(reward);
            }

            getline(file_loader, type, ',');
        }
        file_loader.close();
    }
}

// displays all the cards contained in the LLL
void Duomatch ::display() const
{
    obstacle_card.display();
    cout << "+++++++++++++++++++++\n\n"
         << endl;
    challenge_card.display();
    cout << "+++++++++++++++++++++\n\n"
         << endl;
    reward_card.display();
    cout << "+++++++++++++++++++++\n\n"
         << endl;
}

// randmonly places the cards in the DLL
void Duomatch ::fill_path()
{
    // shared_ptr<Card> list;
    // start();
    int random = 0;
    int card_choice = 0;
    int num = 0;
    srand(time(0));
    for (int i = 0; i < levels; ++i)
    {

        num = (rand() % 2) + 1;
        card_choice = (rand() % 3) + 1;
        random = (rand() % 10);
        shared_ptr<Card> card; // = make_shared<Card>();
        switch (card_choice)
        {
        case 1:
            card = (challenge_card.retrieve(random));
            break;
        case 2:
            card = (obstacle_card.retrieve(random));
            break;
        case 3:
            card = (reward_card.retrieve(random));
            break;
        default:
            break;
        }
        // cout << *card;
        path_manager.insert(card, num);
        // path_manager.insert(*card, num);
    }
    path_manager.set_dll();
}

// welcomes the players
void Duomatch ::welcome()
{
    cout << "\nHello welcome to Duomatch. This is two player game." << endl;
    cout << "You will each roll a die. and be moved to the spot" << endl;
    cout << "Some spots will have mystery card. whoever makes it to last first wins" << endl;
}

// displays the DLL
void Duomatch ::show()
{
    get_player_info();

    // shared_ptr<Level_node> data = path_manager.move_player(2);
    //  data->display_node();
    path_manager.set_dll();
    player_1 = path_manager.move_player(2);
    player_1.display_player();
    player_1.path_check(levels, 5);
    //   player_2.display_player();
    // cout << "start" << endl;
    // path_manager.display_dll();
    //  obstacle_card.display();
    //  reward_card.display();
}

// returns the random die roll
int Duomatch ::roll_die()
{
    srand(time(0));
    return (rand() % 6) + 1;
}