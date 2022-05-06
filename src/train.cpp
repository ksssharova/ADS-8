// Copyright 2021 NNTU-CS
#include "train.h"


Train::Train(): countOp(0), first(nullptr) {}

Train::Cage* Train::create(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  cage->next = nullptr;
  cage->prev = nullptr;
  return cage;
}

void Train::addCage(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  cage->prev = nullptr;
  cage->next = nullptr;
  if (first == nullptr) {
    first = cage;
  } else if (first->next == nullptr) {
    first->next = cage;
    cage->prev = first;
    first->prev = cage;
    cage->next = first;
  } else {
    first->prev->next = cage;
    cage->prev = first->prev;
    first->prev = cage;
    cage->next = first;
  }
}

int Train::getLength() {
  int len = 0;
  countOp = 0;
  first->light = true;
  Cage* temp = first;
  while (true) {
    countOp++;
    lenght++;
    int tr_len;
    temp = temp->next;
    if (temp->light) {
      temp->light = false;
      tr_len = len;
      for (tr_len; tr_len > 0; tr_len--) {
        temp = temp->prev;
        countOp++;
      }
      if (!temp->light) {
        return len;
      }
      len = tr_len;
    }
  }
}
return tr_len;
}

int Train::getOpCount() {
  return countOp;
}
