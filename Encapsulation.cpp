#include <iostream>

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const 
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    // withdraw method should check the balance
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: $" << balance << "\n";
        }

        else
        {
            std::cout << "Insufficient funds for withdrawal.\n";
        }
    }
};
class HeatingSystem
{
public:
    void turnOn()
    {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() 
    {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat 
{
private:
    double currentTemperature;
    HeatingSystem heatingSystem;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    // have thermostat control the heating system

    void adjustHeating()
    {
        if (currentTemperature < 20.0f)
        {
            heatingSystem.turnOn();
        }

        else
        {
            heatingSystem.turnOff();
        }
    }

    double getCurrentTemperature() const
    {
        return currentTemperature;
    }
};
#include <iostream>
#include <string>

class Book 
{
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}
    
    // check availailty should be done in book class
    void borrowBook()
    {
        if (isAvailable)
        {
            isAvailable = false;
            std::cout << "Book borrowed successfully.\n";

        }

        else
        {
            std::cout << "Book is not available for borrowing.\n";
        }
    }

    void returnBook() 
    {
        isAvailable = true;
    }
};

class Library 
{
public:
    void processBookBorrowing(Book& book) 
    {
        book.borrowBook();
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const 
    {
        return health;
    }

    int getAmmo() const 
    {
        return ammo;
    }

    void takeDamage(int damage) 
    {
        if (health > 0)
        {
            health -= damage;
        }
               
    }

    void useAmmo() 
    {
        if (ammo > 0)
        {
            ammo--;
            std::cout << "Player attacked and used ammo." << std::endl;
        }

        else
        {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};

class Game
{
public:
    void enemyAttack(Player& player) 
    {
        player.takeDamage(10);
        player.useAmmo();
    }
};


int main() 
{
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);
    account.withdraw(500);              // checks internally


    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    thermostat.adjustHeating();         // thermostat turns on/off

    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;
    myBook.borrowBook();



    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}
