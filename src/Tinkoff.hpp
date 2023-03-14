//
// Created by Andrei Budilovskii on 13.03.2023.
//

#pragma once
#include "BaseBank.hpp"
#include "string_view"


struct Tinkoff : BaseBank{
    std::unique_ptr<BaseDebet> MakeDebet() override;
    std::unique_ptr<BaseCredit> MakeCredit() override;
    std::unique_ptr<BaseMortgage> MakeMortage() override;
};

struct TinkoffDebet : BaseDebet{
    double GetPercent() override {
        return 16.0;
    }

    std::string_view name() override {
        return name_;
    }

    static inline std::string_view name_ = "Tinkoff дебет";
};

struct TinkoffCredit : BaseCredit{
    double GetPercent() override {
        return 19.0;
    }

    std::string_view name() override {
        return name_;
    }
    static inline std::string_view name_ = "Tinkoff кредит";
};

struct TinkoffMortgage : BaseMortgage {
    double GetPercentYear() override {
        return 16.0;
    }

    double GetPercentFirst() override {
        return 25.0;
    }

    std::string_view name() override {
        return name_;
    }
    static inline std::string_view name_ = "Tinkoff ипотека";
};

std::unique_ptr<BaseDebet> Tinkoff::MakeDebet() {
    return std::unique_ptr<BaseDebet>(new TinkoffDebet);
}

std::unique_ptr<BaseCredit> Tinkoff::MakeCredit() {
    return std::unique_ptr<BaseCredit>(new TinkoffCredit);
}

std::unique_ptr<BaseMortgage> Tinkoff::MakeMortage() {
    return std::unique_ptr<BaseMortgage>(new TinkoffMortgage);
}
