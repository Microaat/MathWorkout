#include "problem.h"

#include <utility>
#include <array>

#include <QRandomGenerator>
#include <QVector>

int Problem::answer() const {
    switch(mOp){
    case Operator::Addition:
        return mLhs + mRhs;

    case Operator::Subtraction:
        return mLhs - mRhs;

    case Operator::Multiplication:
        return mLhs * mRhs;
    }

    return mLhs / mRhs;
}

char Problem::opStr() const {
    switch(mOp){
    case Operator::Addition:
        return '+';

    case Operator::Subtraction:
        return '-';

    case Operator::Multiplication:
        return 'x';
    }

    return u'÷';
}

QString Problem::toString() const {
    return QString("%1 %2 %3 = %4")
        .arg(mLhs)
        .arg(opStr())
        .arg(mRhs)
        .arg(answer());
}

Problem Problem::generate(int min, int max, Operator op){
    if(min > max) std::swap(min, max);
    max = (min == max)? max + 1 : max;

    auto *gen = QRandomGenerator::global();
    std::array<int, 2> values;
    auto &[a, b] = values;

    for(auto &value : values){
        value = gen->bounded(min, max + 1);
    }

    switch(op){
    case Operator::Subtraction:
        if(a < b) std::swap(a, b);
        break;

    case Operator::Multiplication:
        if(a == 0) a = gen->bounded(2, 9);
        if(b == 0) b = gen->bounded(2, 9);
        break;

    case Operator::Division:
        if(b == 0) b = 2;
        a *= b;
    }

    return Problem(values[0], values[1], op);
}

Problem Problem::generate(const Settings &s){
    QVector<Operator> ops;
    if (s.hasAddition())       ops.append(Operator::Addition);
    if (s.hasSubtraction())    ops.append(Operator::Subtraction);
    if (s.hasMultiplication()) ops.append(Operator::Multiplication);
    if (s.hasDivision())       ops.append(Operator::Division);

    if(ops.empty()) return {};
    auto op = ops.at(QRandomGenerator::global()->bounded(ops.size()));

    const Settings::Range& range =
        (op == Operator::Multiplication)?   s.multiplication() :
        (op == Operator::Division)?         s.division() :
            s.addition();

    return Problem::generate(range.min(), range.max(), op);
}
