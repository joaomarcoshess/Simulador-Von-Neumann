//
// Created by joaomarcoshess on 01/11/24.
//

#ifndef REGISTER_H
#define REGISTER_H

#include <cinttypes>

struct REGISTER {
    uint32_t value;

    REGISTER() : value(0x0000) {}

    void write(uint32_t new_value);

    // Inibe o usuário de descartar o valor da função
    [[nodiscard]] uint32_t read() const;
    [[nodiscard]] uint32_t reverse_read() const;
};


#endif 
