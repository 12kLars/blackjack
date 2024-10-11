#include <iostream>
#include <random>
#include <string>

using namespace std;

int player = 0;
int dealer = 0;
string playerMessage = "Las cartas del jugador son: ";
string dealerMessage = "Las cartas del dealer son: ";
int cards[52];

void createDeck()
{
    int cardValue = 2;
    int cardCount = 0;
    for (int figure = 1; figure <= 4; figure++)
    {
        for (int card = 1; card <= 13; card++)
        {
            switch (card)
            {
            case 11:
            case 12:
                cardValue = 10;
                break;
            case 13:
                cardValue = 11;
                break;
            default:
                break;
            }
            cards[cardCount] = cardValue;
            cardCount++;
            cardValue++;
        }
        cardValue = 2;
    }
}

int drawCard()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 52);
    int card = dist(gen);
    return cards[card - 1];
}

void initGame()
{
    for (int i = 0; i < 2; i++)
    {
        int playerCard = drawCard();
        player += playerCard;
        playerMessage += to_string(playerCard) + " ";

        int dealerCard = drawCard();
        dealer += dealerCard;
        dealerMessage += to_string(dealerCard) + " ";
    }

    cout << playerMessage << " -> Puntuacion: " << player << endl;
    cout << dealerMessage << " -> Puntuacion: " << dealer << endl;
}

void checkWinner()
{
    if (player == 21)
    {
        cout << "Ganaste, tienes 21 puntos. " << endl;
    }
    else if (player > dealer && player <= 21)
    {
        cout << "Ganaste." << endl;
    }
    else if (player == dealer)
    {
        cout << "Empate." << endl;
    }
    else
    {
        cout << "Perdiste." << endl;
    }
}

int main()
{
    createDeck();
    initGame();
    checkWinner();

    return 0;
}