#include <iostream>
#include <string>
#include <vector>

class Player {
private:
    std::string name;
    int level;
    std::string notes;

public:
    // Konstruktor
    Player(const std::string& playerName, int playerLevel, const std::string& playerNotes = "")
            : name(playerName), level(playerLevel), notes(playerNotes) {
        std::cout << "Player " << name << " created." << std::endl;
    }

    // Destruktor
    ~Player() {
        std::cout << "Player " << name << " destroyed." << std::endl;
    }

    // Getter- / Setter

    // Befreundeter Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Name: " << player.name << ", Level: " << player.level;
        if (!player.notes.empty()) {
            os << ", Notes: " << player.notes;
        }
        return os;
    }
};

class PlayerDatabase {
private:
    std::vector<Player>* playerList;

public:
    // Konstruktor
    PlayerDatabase() : playerList(new std::vector<Player>) {
        std::cout << "PlayerDatabase created." << std::endl;
    }

    // Destruktor
    ~PlayerDatabase() {
        delete playerList;
        std::cout << "PlayerDatabase destroyed." << std::endl;
    }

    // Spieler hinzuzufügen
    void addPlayer(const Player& player) {
        playerList->push_back(player);
    }

    // Liste leeren
    void clear() {
        playerList->clear();
    }

    // Anzahl der Spieler zurückzugeben
    size_t getPlayerCount() const {
        return playerList->size();
    }

    // n-ten Spieler in der Liste
    const Player& operator[](size_t index) const {
        return (*playerList)[index];
    }

    Player& operator[](size_t index) {
        return (*playerList)[index];
    }

    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const PlayerDatabase& database) {
        os << "PlayerDatabase contents:\n";
        for (const Player& player : *(database.playerList)) {
            os << player << "\n";
        }
        return os;
    }
};

int main() {
    PlayerDatabase database;

    Player player1("Alice", 10, "magic");
    Player player2("Bob", 5, "strategy");

    database.addPlayer(player1);
    database.addPlayer(player2);

    std::cout << "Player count: " << database.getPlayerCount() << std::endl;

    std::cout << "Player at index 0:\n" << database[0] << std::endl;

    std::cout << "\n";

    std::cout << "Database contents before clearing:\n" << database << std::endl;

    database.clear();

    std::cout << "Database contents after clearing:\n" << database << std::endl;

    return 0;
}
