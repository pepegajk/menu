#include <iostream>
#include <string>
#include <algorithm>
#include <random>

void reverseWord(std::string word) {
    std::reverse(word.begin(), word.end());
    std::cout << "Слово задом наперед: " << word << std::endl;
}

void removeVowels(std::string word) {
    std::string vowels = "aeiouAEIOU";
    word.erase(std::remove_if(word.begin(), word.end(), [&](char c) { return vowels.find(c) != std::string::npos; }), word.end());
    std::cout << "Слово без гласных: " << word << std::endl;
}

void removeConsonants(std::string word) {
    std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    word.erase(std::remove_if(word.begin(), word.end(), [&](char c) { return consonants.find(c) != std::string::npos; }), word.end());
    std::cout << "Слово без согласных: " << word << std::endl;
}

void shuffleWord(std::string word) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(word.begin(), word.end(), g);
    std::cout << "Рандомно раскиданные буквы: " << word << std::endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    std::string word;
    int choice;

    std::cout << "Введите слово: ";
    std::cin >> word;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Слово выводится задом наперед\n";
        std::cout << "2. Вывести слово без гласных\n";
        std::cout << "3. Вывести слово без согласных\n";
        std::cout << "4. Рандомно раскидывать буквы заданного слова\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            reverseWord(word);
            break;
        case 2:
            removeVowels(word);
            break;
        case 3:
            removeConsonants(word);
            break;
        case 4:
            shuffleWord(word);
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
