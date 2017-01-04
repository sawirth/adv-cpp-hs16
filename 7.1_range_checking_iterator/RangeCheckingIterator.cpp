#include <vector>
#include <iostream>

using namespace std;

template <typename Iter>
class RangeCheckingIterator {

    Iter begin;
    Iter end;
    Iter current;

public:
    RangeCheckingIterator(Iter begin, Iter end)
            : begin(begin), end(end), current(begin) {}

    RangeCheckingIterator operator++(){
        if (current == end) {
            cout << "Watch out, you're iterator already reached the end!" << endl;
        }
        else{
            current ++;
        }
    }
    RangeCheckingIterator operator--(){
        if (current == begin) {
             cout << "Watch out, you're iterator already reached the start!" << endl;
        }
        else{
            current --;
        }
    }
    RangeCheckingIterator operator++(int){
        if (current == end) {
            cout << "Watch out, you're iterator already reached the end!" << endl;
        }
        else{
            current ++;
        }
    }
    RangeCheckingIterator operator--(int){
        if (current == begin) {
            cout << "Watch out, you're iterator already reached the start!" << endl;
        }
        else{
            current --;
        }
    }

    typename iterator_traits<Iter>::reference operator*();

    bool operator ==(RangeCheckingIterator const& other) const;
    bool operator !=(RangeCheckingIterator const& other) const;
};