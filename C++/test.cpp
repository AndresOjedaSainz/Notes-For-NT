#include <iostream>
#include <cmath>
#include <vector>
#include <string>

//typedef std::string text_t;
using text_t = std::string;
using number_t = int;

int main(void)
{
    using std::cout;
    using std::string;

    int correct = 8;
    int questions = 10;
    double score = correct/(double)questions * 100;

    cout << score << "%" << '\n';

    text_t firstName = "James";

    cout << "Testing!" << "\n";

    cout << firstName << "\n";

    string obi = "Hello There!";

    int number1 = 5;
    int number2 = 2;

    int test = pow(number1, number2);

    std::cout << test << '\n';

    string name;
    int age;

    cout << "How old are you?" << '\n';
    std::cin >> age;

    cout << "What's your name?" << '\n';
    std::getline(std::cin >> std::ws, name);
    
    cout << "Your name is " << name << " and you are " << age << " years old.";

    return 0;
}