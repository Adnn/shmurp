set(TARGET_NAME shmurp)

set(${TARGET_NAME}_HEADERS
    commons.h
    Bloom.h
    BloomShaders.h
    Boss1.h
    DebugUI.h
    Game.h
    Instancing.h
    ScreenQuad.h
    shapes.h
    shapes3D.h

    Components/BossEvent.h
    Components/Boundaries.h
    Components/ControlDevice.h
    Components/CustomCallback.h
    Components/EventObserver.h
    Components/FirePattern.h
    Components/Geometry.h
    Components/Health.h
    Components/HealthFollower.h
    Components/ImpactRef.h
    Components/SceneGraphComposite.h
    Components/SceneGraphParent.h
    Components/Shape.h
    Components/Speed.h
    Components/TrackerPlayer.h
    Components/Tweening.h

    Entities/Bullets.h
    Entities/Ships.h

    System/BulletSpawn.h
    System/Collision.h
    System/Customizer.h
    System/Damage.h
    System/Displace.h
    System/EnemySpawn.h
    System/EventQueue.h
    System/EventQueue-impl.h
    System/Interpolate.h
    System/Interpolate-impl.h
    System/LimitPosition.h
    System/KeyboardControl.h
    System/PruneEntities.h
    System/Rendering.h
    System/Rendering3D.h
    System/RenderingShaders.h
    System/SceneGraph.h
    System/Tracking.h

    Utils/ArcQuantifier.h
    Utils/Delay.h
    Utils/interpolation.h
    Utils/Iterative.h
    Utils/Periodic.h
    Utils/Rythm.h
    Utils/TimedSequence.h
)

set(${TARGET_NAME}_SOURCES
    DebugUI.cpp
    Game.cpp

    System/BulletSpawn.cpp
    System/Collision.cpp
    System/Customizer.cpp
    System/Damage.cpp
    System/Displace.cpp
    System/EnemySpawn.cpp
    System/LimitPosition.cpp
    System/PruneEntities.cpp
    System/Rendering.cpp
    System/Rendering3D.cpp
    System/KeyboardControl.cpp
    System/SceneGraph.cpp
    System/Tracking.cpp
)

find_package(Aunteater CONFIG REQUIRED COMPONENTS aunteater)
find_package(Graphics CONFIG REQUIRED COMPONENTS engine)
find_package(Math CONFIG REQUIRED COMPONENTS math)
find_package(Websocket CONFIG REQUIRED COMPONENTS websocket)

find_package(glad REQUIRED)

add_executable(${TARGET_NAME}
    main.cpp
    ${${TARGET_NAME}_SOURCES}
    ${${TARGET_NAME}_HEADERS}
)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(${TARGET_NAME}
        PRIVATE "-fno-omit-frame-pointer" "-fsanitize=address" "-fsanitize=undefined")
    target_link_options(${TARGET_NAME}
        PRIVATE "-fsanitize=address" "-fsanitize=undefined")
endif()

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${TARGET_NAME}
    PRIVATE
        ad::aunteater
        ad::engine
        ad::math
        ad::websocket

        glad::glad
)

set_target_properties(${TARGET_NAME} PROPERTIES
                      VERSION "${${PROJECT_NAME}_VERSION}"
)


##
## Install
##

install(TARGETS ${TARGET_NAME})
