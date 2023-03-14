//
// Created by Andrei Budilovskii on 13.03.2023.
//

#pragma once
#include "BaseBank.hpp"
#include "string_view"


struct Alpha : BaseBank{
    std::unique_ptr<BaseDebet> MakeDebet() override;
    std::unique_ptr<BaseCredit> MakeCredit() override;
    std::unique_ptr<BaseMortgage> MakeMortage() override;
};

struct AlphaDebet : BaseDebet{
    double GetPercent() override {
        return 6.0;
    }

    std::string_view name() override {
        return name_;
    }

    static inline std::string_view name_ = "Alpha дебет";
};

struct AlphaCredit : BaseCredit{
    double GetPercent() override {
        return 9.0;
    }

    std::string_view name() override {
        return name_;
    }
    static inline std::string_view name_ = "Alpha кредит";
};

struct AlphaMortgage : BaseMortgage {
    double GetPercentYear() override {
        return 6.0;
    }

    double GetPercentFirst() override {
        return 15.0;
    }

    std::string_view name() override {
        return name_;
    }
    static inline std::string_view name_ = "Alpha ипотека";
};

std::unique_ptr<BaseDebet> Alpha::MakeDebet() {
    return std::unique_ptr<BaseDebet>(new AlphaDebet);
}

std::unique_ptr<BaseCredit> Alpha::MakeCredit() {
    return std::unique_ptr<BaseCredit>(new AlphaCredit);
}

std::unique_ptr<BaseMortgage> Alpha::MakeMortage() {
    return std::unique_ptr<BaseMortgage>(new AlphaMortgage);
}
