#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = new Item();
  tail_ = head_;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

//WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == nullptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == nullptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != nullptr){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = nullptr;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val)
{
    if (empty() || tail_->last == ARRSIZE) {

        Item* newItem = new Item();

        tail_->next = newItem;

        newItem->prev = tail_;
        
        tail_ = newItem;
    }

    tail_->val[tail_->last] = val;
    ++tail_->last;
    ++size_;
}

void ULListStr::pop_back()
{
    if (empty()) {
        return;
    }

    --tail_->last;
    --size_;

    if (tail_->last == 0 && tail_ != head_) {
        Item* temp = tail_->prev;
        delete tail_;
        tail_ = temp;
        tail_->next = nullptr;
    }
}

void ULListStr::push_front(const std::string& val)
{
    if (empty() || head_->first == 0) {
        Item* newHead = new Item();
        newHead->next = head_;
        head_->prev = newHead;
        head_ = newHead;
    }

    --head_->first;
    head_->val[head_->first] = val;
    ++size_;
}

void ULListStr::pop_front()
{
    if (empty()) {
        return;
    }

    ++head_->first;
    --size_;

    if (head_->first == ARRSIZE) {
        Item* temp = head_->next;
        delete head_;
        head_ = temp;
        head_->prev = nullptr;
    }
}

std::string const & ULListStr::back() const
{
    if (empty()) {
        throw std::out_of_range("List is empty");
    }

    return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
    if (empty()) {
        throw std::out_of_range("List is empty");
    }

    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
    if (loc >= size_) {
        return nullptr; 
    }

    Item* current = head_;

    while (loc >= (current->last - current->first)) {
        loc -= (current->last - current->first);
        current = current->next;
    }

    return &(current->val[current->first + loc]);
}
