//
// Created by evya on 1/12/19.
//

#ifndef S_O_L_I_D_ANYITERATOR_H
#define S_O_L_I_D_ANYITERATOR_H

template <typename T>
class AnyIterator {
    AnyIterator() = 0;
    AnyIterator(const AnyIterator& o) = 0;                   // Copy constructor
    virtual ~AnyIterator() = 0;
    virtual AnyIterator& operator=(const AnyIterator& o) = 0;        // Assignment operator
    virtual AnyIterator& operator++() = 0;                   // Next element
    virtual T&   operator*() = 0;                    // Dereference
    virtual bool operator==(const AnyIterator& o) const = 0; // Comparison
    virtual bool operator!=(const AnyIterator& o) const { return !(*this == o); }
};
#endif //S_O_L_I_D_ANYITERATOR_H
