#include <vector>
#include <iostream>
#include <exception>

using namespace std;

template <typename Iter>
class RangeCheckingIterator {

    Iter begin;
    Iter end;
    Iter current;

public:
    RangeCheckingIterator(Iter begin, Iter end)
            : begin(begin), end(end), current(begin) {}

    RangeCheckingIterator operator++()throw(string){
            if (current == end) {
                string emessage = "You're iterator already reached the end!";
                throw emessage;            }
            else{
            current ++;
            }
    }

    RangeCheckingIterator operator--()throw(string){
            if (current == begin) {
                string emessage = "You're iterator already reached the start!";
                throw emessage;
            }
            else{
                current --;
            }

    }

    RangeCheckingIterator operator++(int)throw(string){
            if (current == end) {
                string emessage = "You're iterator already reached the end!";
                throw emessage;
            } else {
                current++;
            }

    }

    RangeCheckingIterator operator--(int)throw(string){
            if (current == begin) {
                string emessage = "You're iterator already reached the start!";
                throw emessage;
            }
            else{
                current --;
            }

    }

    typename iterator_traits<Iter>::reference operator*(){
       return *current;
    }

};