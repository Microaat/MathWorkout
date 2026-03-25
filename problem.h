#ifndef PROBLEM_H
#define PROBLEM_H

#include <QString>

#include "settings.h"

class Problem {
public:
    Problem(int lhs, int rhs, Operator op)
        : mLhs(lhs), mRhs(rhs), mOp(op)
    {}

    Problem(int lhs, int rhs)
        : Problem(lhs, rhs, Operator::Addition)
    {}

    Problem()
        : Problem(0, 0, Operator::Addition)
    {}

    int lhs() const { return mLhs; }
    int rhs() const { return mRhs; }
    Operator op() const { return mOp; }
    int answer() const;
    char opStr() const;

    QString toString() const;


    static Problem generate(int min, int max, Operator op);
    static Problem generate(const Settings& s);

private:
    int mLhs = 0;
    int mRhs = 0;
    Operator mOp;
};

#endif // PROBLEM_H
