#pragma once

#include "../commons.h"

#include <aunteater/Component.h>

namespace ad {

struct Speed : public aunteater::Component<Speed>
{
    explicit Speed(Vec<2, GLfloat> aTranslation = Vec<2>::Zero()) :
        translation{aTranslation}
    {}

    Speed(Vec<2, GLfloat> aTranslation, Vec<3, Radian<>> aRotation) :
        translation{aTranslation},
        rotation{aRotation}
    {}

    Speed(GLfloat x, GLfloat y) :
        translation(x, y)
    {}

    Vec<2> translation;
    Vec<3, Radian<>> rotation{Vec<3, Radian<>>::Zero()};
};



} // namespace ad
