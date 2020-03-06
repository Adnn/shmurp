#pragma once

#include "../Bloom.h"
#include "../commons.h"
#include "../Instancing.h"
#include "../shapes3D.h"

#include <Components/Geometry.h>
#include <Components/Shape.h>

#include <aunteater/Archetype.h>
#include <aunteater/FamilyHelp.h>
#include <aunteater/System.h>

#include <renderer/Shading.h>

namespace ad {

typedef aunteater::Archetype<Geometry, Shape> Renderable;

class Rendering3D : public aunteater::System
{
    using ShapeInstancing = Instancing<vertex3D::Data, instance3D::Data>;

    struct Impl
    {
        Impl(Size<2, GLsizei> aResolution);
        void draw(double time);

        std::map<Shape::Value, ShapeInstancing> mShapeToSpecification;
        Program mProgram;

        Bloom mOkBloomer;
    };

public:
    Rendering3D(aunteater::Engine &aEngine, Size<2, GLsizei> aResolution);

    void update(double time) override;

private:
    aunteater::FamilyHelp<Renderable> mRenderables;
    Impl mImpl;
};

} // namespace ad
