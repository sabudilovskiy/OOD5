//
// Created by Andrei Budilovskii on 13.03.2023.
//

#pragma once
#include "BaseBank.hpp"
#include "string_view"


struct Sber : BaseBank{
    std::unique_ptr<BaseDebet> MakeDebet() override;
    std::unique_ptr<BaseCredit> MakeCredit() override;
    std::unique_ptr<BaseMortgage> MakeMortage() override;
};

struct SberDebet : BaseDebet{
    double GetPercent() override {
        return 5.0;
    }

    std::string_view name() override {
        return name_;
    }

    static inline std::string_view name_ = "сберовский дебет";
};

struct SberCredit : BaseCredit{
    double GetPercent() override {
        return 10.0;
    }

    std::string_view name() override {
        return name_;
    }
    static inline std::string_view name_ = "сберовский кредит";
};

struct SberMortgage : BaseMortgage {
    double GetPercentYear() override {
        return 8.0;
    }

    double GetPercentFirst() override {
        return 12.0;
    }

    std::string_view name() override {
        return name_;
    }
    static inline std::string_view name_ = "сберовская ипотека";
};

std::unique_ptr<BaseDebet> Sber::MakeDebet() {
    return std::unique_ptr<BaseDebet>(new SberDebet);
}

std::unique_ptr<BaseCredit> Sber::MakeCredit() {
    return std::unique_ptr<BaseCredit>(new SberCredit);
}

std::unique_ptr<BaseMortgage> Sber::MakeMortage() {
    return std::unique_ptr<BaseMortgage>(new SberMortgage);
}
