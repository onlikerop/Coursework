//
// Created by Eugene on 26.04.2021.
//

#include "Active.h"


bool Active::is_active() const {
    return is_active_;
}

void Active::is_active(bool is_active_) {
    this->is_active_ = is_active_;
}