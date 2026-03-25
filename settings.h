#ifndef SETTINGS_H
#define SETTINGS_H

#include <cstdint>
#include <utility>

#include <QFlags>

enum class Operator {
    None            = 0x0,
    Addition        = 0x1,
    Subtraction     = 0x2,
    Multiplication  = 0x4,
    Division        = 0x8
};
Q_DECLARE_FLAGS(Operators, Operator)
Q_DECLARE_OPERATORS_FOR_FLAGS(Operators)

class Settings {
public:
    class Range {
        int mMin = 0;
        int mMax = 1;

        void checkRange();

    public:
        Range(int min, int max)
            : mMin(min), mMax(max)
        { checkRange(); }

        Range(): Range(0, 1) {}

        std::pair<int, int> interval() const {
            return {mMin, mMax};
        }

        int min() const noexcept { return mMin; }
        int max() const noexcept { return mMax; }
    };

    Settings();

    uint16_t amount() const { return mAmount; }
    const Range& addition() const { return mAddition; }
    const Range& multiplication() const { return mMultiplication; }
    const Range& division() const { return mDivision; }

    void setAmount(uint16_t value){ mAmount = value; }
    void setAddition(const Range& range){ mAddition = range; }
    void setMultiplication(const Range& range){ mMultiplication = range; }
    void setDivision(const Range& range){ mDivision = range; }

    void clearOps() { mOperators = {}; }
    bool hasAddition() const { return hasOp(Operator::Addition); }
    bool hasSubtraction() const { return hasOp(Operator::Subtraction); }
    bool hasMultiplication() const { return hasOp(Operator::Multiplication); }
    bool hasDivision() const { return hasOp(Operator::Division); }

    bool hasOp(Operator op) const {
        return mOperators.testFlag(op);
    }

    void setOp(Operator op, bool enabled = true) {
        mOperators.setFlag(op, enabled);
    }

private:
    uint16_t mAmount;
    Operators mOperators;
    Range mAddition;
    Range mMultiplication;
    Range mDivision;
};

#endif // SETTINGS_H
