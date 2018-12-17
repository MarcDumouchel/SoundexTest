//
// Created by CCEClass1 on 12/17/2018.
//

#include "RetweetCollection.h"


bool RetweetCollection::isEmpty() const {
    return 0 == size();
}

unsigned int RetweetCollection::size() const {
    return size_;
}

void RetweetCollection::add(const Tweet& tweet) {
    size_ = 1;
}

RetweetCollection::RetweetCollection() {
    size_ = 0;
}
