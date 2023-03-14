//
// Created by Andrei Budilovskii on 13.03.2023.
//

#pragma once
#include "BaseBank.hpp"
#include "magic_enum.hpp"

std::unique_ptr<BaseBank> MakeBank(std::string_view name);

