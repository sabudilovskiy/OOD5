#include <iostream>
#include "BaseBank.hpp"
#include "magic_enum.hpp"
#include "MakerBank.hpp"

#define Print(x) \
std::cout << #x << '\t'; \
std::cout << x << '\n';


int main() {
    std::tuple<int, double> amazing;
    std::cout << "Введите название банка: Sber, Tinkoff, Alpha: ";
    std::string temp;
    std::cin >> temp;
    auto bank = MakeBank(temp);
    if (!bank){
        std::cout << "Не найден банк.";
        return 0;
    }
    auto [debet, credit, mortgage]=
            std::make_tuple(bank->MakeDebet(), bank->MakeCredit(), bank->MakeMortage());
    Print(debet->GetPercent());
    Print(debet->name());
    Print(credit->name());
    Print(credit->GetPercent());
    Print(mortgage->GetPercentFirst());
    Print(mortgage->GetPercentYear());
    Print(mortgage->name());
}
