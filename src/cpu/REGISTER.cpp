//
// Created by joaomarcoshess on 01/11/24.
//

#include "REGISTER.h"

void REGISTER::write(const uint32_t new_value) {
    value = new_value;
}

uint32_t REGISTER::read() const {
    return value;
}

uint32_t REGISTER::reverse_read() const {
    return ~value;
}
