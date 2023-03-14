//
// Created by Andrei Budilovskii on 13.03.2023.
//

#pragma once
#include <memory>
#include "string_view"
struct BaseProduct{
    virtual std::string_view name() = 0;
    virtual ~BaseProduct() {}
};


struct BaseDebet : BaseProduct{
    virtual double GetPercent() = 0;
};

struct BaseCredit : BaseProduct{
    virtual double GetPercent() = 0;
};

struct BaseMortgage : BaseProduct{
    virtual double GetPercentYear() = 0;
    virtual double GetPercentFirst() = 0;
};

struct BaseBank {
    virtual std::unique_ptr<BaseDebet> MakeDebet() = 0;
    virtual std::unique_ptr<BaseCredit> MakeCredit() = 0;
    virtual std::unique_ptr<BaseMortgage> MakeMortage() = 0;
};