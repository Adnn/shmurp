#pragma once

#include "commons.h"
#include "Instancing.h"

#include <renderer/VertexSpecification.h>

namespace ad {

namespace vertex3D
{

struct Data
{
    Vec<3, GLfloat> mPosition;
    Vec<3, GLfloat> mNormal{0.f, 0.f, 1.f};
};

constexpr AttributeDescriptionList gDescription = {
    { 0, 3, offsetof(Data, mPosition), MappedGL<GLfloat>::enumerator},
    { 1, 3, offsetof(Data, mNormal), MappedGL<GLfloat>::enumerator},
};

} // namespace vertex3D

template <>
class BufferData_trait<vertex3D::Data>
{
public:
    static constexpr AttributeDescriptionList description_value = vertex3D::gDescription;
};

namespace ship3D {

static const std::array<vertex3D::Data, 4> gVertices = {
    vertex3D::Data{
        {-0.3f, -0.25f, 0.0f},
    },
    vertex3D::Data{
        { 0.0f,  0.75f, 0.0f},
    },
    vertex3D::Data{
        { 0.3f, -0.25f, 0.0f},
    },
    vertex3D::Data{
        { 0.0f,  0.0f,  0.0f},
    },
};

} // namespace ship3D

namespace cube {

static constexpr float cpi4 = 0.70710678f;

static const std::array<vertex3D::Data, 8*3> gVertices = {
    // Frontface
    vertex3D::Data{
        {-0.3f, -0.3f, 0.3f},
        {-cpi4,  0.0f, cpi4},
    },
    vertex3D::Data{
        {-0.3f,  0.3f, 0.3f},
        {-cpi4,  0.0f, cpi4},
    },
    vertex3D::Data{
        {-0.3f,  0.3f, 0.3f},
        { 0.0f,  cpi4, cpi4},
    },
    vertex3D::Data{
        { 0.3f,  0.3f, 0.3f},
        { 0.0f,  cpi4, cpi4},
    },
    vertex3D::Data{
        { 0.3f,  0.3f, 0.3f},
        { cpi4,  0.0f, cpi4},
    },
    vertex3D::Data{
        { 0.3f,  -0.3f, 0.3f},
        { cpi4,  0.0f,  cpi4},
    },
    vertex3D::Data{
        { 0.3f, -0.3f, 0.3f},
        { 0.0f, -cpi4, cpi4},
    },
    vertex3D::Data{
        {-0.3f, -0.3f, 0.3f},
        { 0.0f, -cpi4, cpi4},
    },

    // Backface
    vertex3D::Data{
        {-0.3f, -0.3f, -0.3f},
          {-cpi4,  0.0f, -cpi4},
    },
    vertex3D::Data{
        {-0.3f,  0.3f, -0.3f},
        {-cpi4,  0.0f, -cpi4},
    },
    vertex3D::Data{
        {-0.3f,  0.3f, -0.3f},
        { 0.0f,  cpi4, -cpi4},
    },
    vertex3D::Data{
        { 0.3f,  0.3f, -0.3f},
        { 0.0f,  cpi4, -cpi4},
    },
    vertex3D::Data{
        { 0.3f,  0.3f, -0.3f},
        { cpi4,  0.0f, -cpi4},
    },
    vertex3D::Data{
        { 0.3f,  -0.3f, -0.3f},
        { cpi4,   0.0f, -cpi4},
    },
    vertex3D::Data{
        { 0.3f, -0.3f, -0.3f},
        { 0.0f, -cpi4, -cpi4},
    },
    vertex3D::Data{
        {-0.3f, -0.3f, -0.3f},
        { 0.0f, -cpi4, -cpi4},
    },

    // Connect
    vertex3D::Data{
        {-0.3f, -0.3f, -0.3f},
        {-cpi4, -cpi4,  0.0f},
    },
    vertex3D::Data{
        {-0.3f, -0.3f, +0.3f},
        {-cpi4, -cpi4,  0.0f},
    },
    vertex3D::Data{
        {-0.3f,  0.3f, -0.3f},
        {-cpi4,  cpi4,  0.0f},
    },
    vertex3D::Data{
        {-0.3f,  0.3f, +0.3f},
        {-cpi4,  cpi4,  0.0f},
    },
    vertex3D::Data{
        { 0.3f,  0.3f, -0.3f},
        { cpi4,  cpi4,  0.0f},
    },
    vertex3D::Data{
        { 0.3f,  0.3f, +0.3f},
        { cpi4,  cpi4,  0.0f},
    },
    vertex3D::Data{
        { 0.3f,  -0.3f, -0.3f},
        { cpi4,  -cpi4,  0.0f},
    },
    vertex3D::Data{
        { 0.3f,  -0.3f, +0.3f},
        { cpi4,  -cpi4,  0.0f},
    },
};

} // namespace cube

namespace circle3D {

template <GLsizei N_vertices>
std::vector<vertex3D::Data> makeVertices(GLfloat aRadius)
{
    std::vector<vertex3D::Data> result{vertex3D::Data{
        {0.f, 0.f, 0.f},
    }};
    result.reserve(N_vertices+2);
    for(int i=0; i<=N_vertices; ++i)
    {
        result.emplace_back(vertex3D::Data{{
                                                cos(2*pi<float>*i/N_vertices) * aRadius,
                                                sin(2*pi<float>*i/N_vertices) * aRadius,
                                                0.f,
                                            },
                                            {
                                                0.f,
                                                0.f,
                                                -1.f,
                                            }});
    }
    return result;
}

} // namespace circle3D

namespace filledSquare3D {

static const std::array<vertex3D::Data, 4> gVertices = {
    vertex3D::Data{
        {1.f, 1.f, 0.f},
    },
    vertex3D::Data{
        {1.f,  0.f, 0.f},
    },
    vertex3D::Data{
        {0.f,  0.f, 0.f},
    },
    vertex3D::Data{
        { 0.f,  1.f, 0.f},
    }
};
}

namespace instance3D {

struct Data
{
    Vec<2, GLfloat> mPosition;
    Matrix<4, GLfloat> mOrientation{Matrix<4, GLfloat>::Identity()};
};

constexpr AttributeDescriptionList gDescription = {
    {2, 2, offsetof(Data, mPosition),      MappedGL<GLfloat>::enumerator},
    {3, 4, offsetof(Data, mOrientation),   MappedGL<GLfloat>::enumerator},
    {4, 4, offsetof(Data, mOrientation) +  4*sizeof(GLfloat),   MappedGL<GLfloat>::enumerator},
    {5, 4, offsetof(Data, mOrientation) +  8*sizeof(GLfloat),   MappedGL<GLfloat>::enumerator},
    {6, 4, offsetof(Data, mOrientation) + 12*sizeof(GLfloat),   MappedGL<GLfloat>::enumerator},
};

} // namespace instance3D

template <>
class BufferData_trait<instance3D::Data>
{
public:
    static constexpr AttributeDescriptionList description_value = instance3D::gDescription;
};


} // namespace ad
