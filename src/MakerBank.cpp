#include "MakerBank.hpp"
#include "string_view"
#include "Sber.hpp"
#include "Alpha.hpp"
#include "Tinkoff.hpp"
#include "magic_enum.hpp"

enum struct BankType{
    Sber, Tinkoff, Alpha
};

std::unique_ptr<BaseBank> MakeBank(BankType bankType) {
    switch (bankType) {
        case BankType::Sber:
            return std::unique_ptr<BaseBank>(new Sber);
        case BankType::Tinkoff:
            return std::unique_ptr<BaseBank>(new Tinkoff);
        case BankType::Alpha:
            return std::unique_ptr<BaseBank>(new Alpha);
    }
}

std::unique_ptr<BaseBank> MakeBank(std::string_view name) {
    auto bank_type = magic_enum::enum_cast<BankType>(name);
    if (bank_type){
        return MakeBank(*bank_type);
    }
    else return {};
}

