#include <iostream>
#include <cstdlib>

class slots {
    public:
    char sloticon[3];

    slots() {
        sloticon[0] = '7';
        sloticon[1] = '1';
        sloticon[2] = '9';
    }
};

bool spinSlots(slots &s) {
    std::srand(std::time(0));

    char results[3];
    
    std::cout << "####### O" << '\n';
    
    for (int i = 0; i < 3; i++) {
        int slot = rand() % 3;
        
        switch(slot) {
            case 0:
                results[i] = s.sloticon[0];
                std::cout << "#" << s.sloticon[0];
                break;
            case 1:
                results[i] = s.sloticon[1];
                std::cout << "#" << s.sloticon[1];
                break;
            case 2:
                results[i] = s.sloticon[2];
                std::cout << "#" << s.sloticon[2];
                break;
        }
    }
    std::cout << "# V" << '\n';
    std::cout << "#######-|" << '\n';
    std::cout << std::endl;

    return (results[0] == results[1] && results[1] == results[2]);
}

int main() {
    int bet;
    int balance = 100;

    slots s;

    std::cout << "Hello and welcome to my shitty slots thingy" << '\n';

    do {
        std::cout << "Enter your bet amount" << '\n';
        std::cout << "Your balance is $" << balance << '\n';
        std::cout << '>'; std::cin >> bet; std::cout << '\n';
        bet -= bet / 2;
        balance -= bet;
    
        if (bet <= 0 || bet > balance) {
            std::cout << "INVALID: You entered a bet less than or equal to 0 or your bet is greater than your balance" << '\n';
            break;
        } else {
            bool winlose = spinSlots(s);
            
            if (!winlose) {
                std::cout << "womp womp you lose" << '\n';
                balance -= bet;
                continue;
            } else {
                std::cout << "YOU WIN!!!" << '\n';
                balance += bet * 3;    
            }
        }
        
        if (balance <= 0) {
            std::cout << "damn you suck ass at this lil bro" << '\n';    
        }
    } while (balance > 0);
    
    return 0;
}