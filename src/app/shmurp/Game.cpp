#include "Game.h"

#include "configuration.h"

#include "Components/ControlDevice.h"
#include "Components/Faction.h"
#include "Components/Geometry.h"
#include "Components/Shape.h"

#include "System/BulletSpawn.h"
#include "System/Collision.h"
#include "System/Displace.h"
#include "System/EnemySpawn.h"
#include "System/KeyboardControl.h"
#include "System/Rendering.h"

#include <aunteater/UpdateTiming.h>

using aunteater::Entity;

namespace ad {
namespace shmurp {

Game::Game(Application & aApplication)
{
    /*
     * Systems
     */
    auto kbControl = std::make_shared<KeyboardControl>(mEntityEngine);
    aApplication.registerKeyCallback(kbControl->getCallback());
    mEntityEngine.addSystem(kbControl);

    mEntityEngine.addSystem<Displace>();

    mEntityEngine.addSystem<Collision>();

    mEntityEngine.addSystem<EnemySpawn>();

    mEntityEngine.addSystem<BulletSpawn>();

    mEntityEngine.addSystem<Rendering>();


    /*
     * Entities
     */
    mEntityEngine.addEntity(Entity().add<ControlDevice>(0)
                                    .add<Faction>(Faction::SpaceForce, Faction::Democrats)
                                    .add<Geometry>(conf::shipInitialX, conf::shipInitialY, conf::shipRadius)
                                    .add<Shape>(Shape::RocketShip)
                                    .add<Speed>(0., 0.)
                                    );

    mEntityEngine.addEntity(Entity().add<FirePattern>(0.05f, pi<float>)
                                    .add<Geometry>(5.f, conf::gWindowWorldHeight-5.f, conf::squareRadius)
                                    .add<Shape>(Shape::RocketShip)
                                    .add<Speed>(0., 0.)
                                    );
    mEntityEngine.addEntity(Entity().add<FirePattern>(0.05f, pi<float>)
                                    .add<Geometry>(conf::gWindowWorldWidth-5.f, conf::gWindowWorldHeight-5.f, conf::squareRadius)
                                    .add<Shape>(Shape::RocketShip)
                                    .add<Speed>(0., 0.)
                                    );
}

void Game::update(const Timer & aTimer)
{
    aunteater::UpdateTiming timings;
    mEntityEngine.update(aTimer.delta(), timings);

    mUI.broadcast(timings);
}

} // namespace shmurp
} // namespace ad
