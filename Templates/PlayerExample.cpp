// Example program
#include <iostream>
#include <string>
#include <vector>

struct LeaguePlayer
{
    int playerId;
    std::string firstName;
    std::string lastName;
};

struct ExhibitionPlayer
{
    int id;
    std::string firstName;
    std::string middleInitial;
    std::string lastName;
};

struct GameplayPlayer
{
    int gameId;
    std::string fullName;
};

template<class PlayerT>
class PlayerMapper
{
public:
    void mapPlayers(std::vector<PlayerT>& playersIn, std::vector<GameplayPlayer>& playersOut);
    void mapSinglePlayer(PlayerT& playerIn, GameplayPlayer& playerOut);
};

template<class PlayerT>
void PlayerMapper<PlayerT>::mapPlayers(std::vector<PlayerT>& playersIn, std::vector<GameplayPlayer>& playersOut)
{
    for (auto& playerIn : playersIn)
    {
        GameplayPlayer playerOut;
        mapSinglePlayer(playerIn, playerOut);
        playersOut.push_back(playerOut);
    }
}

template<class PlayerT>
void PlayerMapper<PlayerT>::mapSinglePlayer(PlayerT& playerIn, GameplayPlayer& playerOut)
{
    playerOut.gameId = playerIn.playerId;
    playerOut.fullName = playerIn.firstName + " " + playerIn.lastName;    
}

template<>
void PlayerMapper<ExhibitionPlayer>::mapSinglePlayer(ExhibitionPlayer& playerIn, GameplayPlayer& playerOut)
{
    playerOut.gameId = playerIn.id;
    playerOut.fullName = playerIn.firstName + " " + playerIn.middleInitial + ". " + playerIn.lastName;
}


int main()
{
    std::vector<LeaguePlayer> lPlayers = {
        { 0, "First", "Last" },
        { 1, "First", "Last" },
        { 2, "First", "Last" },
        { 3, "First", "Last" },
        { 4, "First", "Last" },
        { 5, "First", "Last" },
        { 6, "First", "Last" },
        { 7, "First", "Last" },
        { 8, "First", "Last" },
        { 9, "First", "Last" } 
    };

    std::vector<ExhibitionPlayer> ePlayers = {
        { 0, "First", "A", "Last" },
        { 1, "First", "A", "Last" },
        { 2, "First", "A", "Last" },
        { 3, "First", "A", "Last" },
        { 4, "First", "A", "Last" },
        { 5, "First", "A", "Last" },
        { 6, "First", "A", "Last" },
        { 7, "First", "A", "Last" },
        { 8, "First", "A", "Last" },
        { 9, "First", "A", "Last" }
    };
    
    std::vector<GameplayPlayer> playersOut;
    
    PlayerMapper<LeaguePlayer> mapper;
    PlayerMapper<ExhibitionPlayer> mapper2;
    mapper.mapPlayers(lPlayers, playersOut);
    mapper2.mapPlayers(ePlayers, playersOut);

    for (auto player : playersOut)
    {
        std::cout << player.gameId << " " << player.fullName << std::endl;
    }
}