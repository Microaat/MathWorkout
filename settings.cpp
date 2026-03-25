#include "settings.h"

#include <limits>
#include <algorithm>

void Settings::Range::checkRange(){
    if(mMin > mMax) std::swap(mMin, mMax);
    if(mMin == mMax){
        if(mMax < std::numeric_limits<uint16_t>::max())
            ++mMax;
        else
            --mMin;
    }
}

Settings::Settings():
    mAmount(10),
    mOperators(Operator::Addition | Operator::Subtraction),
    mAddition(100, 999), mMultiplication(1, 50),
    mDivision(1, 30)
{}
