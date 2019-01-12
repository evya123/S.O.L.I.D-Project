//
// Created by evya on 1/12/19.
//

#ifndef S_O_L_I_D_MATRIXSEARCHERITER_H
#define S_O_L_I_D_MATRIXSEARCHERITER_H


#include "AnyIterator.h"
#include "MatrixSearcher.h"
#include <vector>

class MatrixSearcherIter : public AnyIterator<MatrixSearcherIter*>{

    MatrixSearcherIter() = default;

    ~MatrixSearcherIter() override;

    AnyIterator<MatrixSearcherIter *> &operator=(const AnyIterator &o) override;

    AnyIterator<MatrixSearcherIter *> &operator++() override;

    MatrixSearcherIter *&operator*() override;

    bool operator==(const AnyIterator &o) const override;

    bool operator!=(const AnyIterator &o) const override;
};


#endif //S_O_L_I_D_MATRIXSEARCHERITER_H
