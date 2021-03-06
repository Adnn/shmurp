#pragma once

#include <math/Angle.h>
#include <math/Constants.h>
#include <math/Matrix.h>
#include <math/Rectangle.h>
#include <math/Vector.h>

#include <glad/glad.h>

namespace ad {

using Floating = float;

// Most places do not care about a complete Timer with several measurements,
// such as wall time, delta, etc;
using duration_t = double;
using timepoint_t = duration_t;

template <class T=Floating> constexpr T pi = math::pi<T>;

template <int N, class T=Floating>
using Vec = math::Vec<N, T>;

template <int N, class T=Floating>
using Size = math::Size<N, T>;

template <int N, class T=Floating>
using Position = math::Position<N, T>;

template <int N, class T=Floating>
using Matrix = math::Matrix<N, N, T>;

template <class T=Floating>
using Rectangle = math::Rectangle<T>;

template <class T=Floating>
using Radian = math::Radian<T>;

} // namespace ad
