#include "level.h"
#include "game.h"

// Include all enemies
#include "plane1.h"
#include "plane2.h"
#include "ufo.h"
#include "rocket.h"
#include "missiontext.h"

#include "basicmovementengine.h"

#include "bitmapserver.h"

Level::Level() {
    _distance = 0;
    _level = 1;
}

Level::~Level() {
}

void Level::run() {

    // Which level are we on?
    switch (_level) {
        case 1:
            // Level one
            level1();
            break;
        case 2:
            // Level two
            level2();
            break;
        case 3:
            // Level three
            level3();
            break;
        case 4:
            // Level four
            level4();
            break;

    }

    _distance++;
}

void Level::level1() {
    // How far have we got into the level?
    if ((_distance > 1000) && (_distance < 4000)) {
        level1RocketStorm();
    } else {

        switch (_distance) {
            // Level intro
            case 1:

                // Change colours
                BitmapServer::changeColour(COLOUR_GREY);

                // Reblit background
                Game::redrawBackground();

                // Redraw score
                Score::draw();

                addMissionText();
//_distance = 2600;
                break;

            // Rocket wave 1
            case 300:
                addRocket(90);
                break;

            case 420:
                addRocket(215);
                break;

            case 540:
                addRocket(110);
                break;

            case 660:
                addRocket(195);
                break;

            case 780:
                addRocket(130);
                break;

            case 900:
                addRocket(175);
                break;

            // Rocket storm procedure takes over from 1000 to 4000

            // UFO
            case 4100:
                addUFO(100);
                break;

            // Plane2 wave
            case 4500:
                addPlane1(200);
                break;

            case 4560:
                addPlane1(200);
                break;

            case 4620:
                addPlane1(200);
                break;

            case 4680:
                addPlane1(200);
                break;

            case 4740:
                addPlane1(200);
                break;

            case 4800:
                addPlane1(200);
                break;



            // End of level
            case 5200:
                //_distance = 290;

                // Next level
                _distance = 0;
                _level++;

        }
    }
}

void Level::level2() {
    // How far have we got into the level?
    switch (_distance) {
        case 1:

            // Change colours
            BitmapServer::changeColour(COLOUR_YELLOW);

            // Reblit background
            Game::redrawBackground();

            // Redraw score
            Score::draw();

            addMissionText();
            break;

        case 300:
            addPlane1(70);
            addPlane2(80);
            addPlane2(200);
            break;

        case 500:
            // Next level
            _distance = 0;
            _level++;
    }
}

void Level::level3() {
    // How far have we got into the level?
    switch (_distance) {
        case 1:

            // Change colours
            BitmapServer::changeColour(COLOUR_GREEN);

            // Reblit background
            Game::redrawBackground();

            // Redraw score
            Score::draw();

            addMissionText();
            break;

        case 300:
            addPlane1(70);
            addPlane2(80);
            addPlane2(200);
            break;

        case 500:
            // Next level
            _distance = 0;
            _level++;
    }
}

void Level::level4() {
    // How far have we got into the level?
    switch (_distance) {
        case 1:

            // Change colours
            BitmapServer::changeColour(COLOUR_BLUE);

            // Reblit background
            Game::redrawBackground();

            // Redraw score
            Score::draw();

            addMissionText();
            break;

        case 300:
            addPlane1(70);
            addPlane2(80);
            addPlane2(200);
            break;

        case 500:
            // Next level
            _distance = 0;
            _level = 1;
    }
}

void Level::level1RocketStorm() {
    if (rand() % 30 == 0) {
        Uint32 rockets = rand() % 4;
        Uint32 speed = 0;
        Uint32 x = 0;

        for (Uint32 i = 0; i < rockets; i++) {
            x = PLAYFIELD_X + (rand() % PLAYFIELD_WIDTH);
            speed = 128 + (rand() % 256);

            Rocket* rocket;
            rocket = new Rocket();
            rocket->setY(-rocket->getHeight());
            rocket->setX(x);
            ((BasicMovementEngine*)rocket->getMovementEngine())->setYSpeed(speed);

            Game::getEnemyManager()->add(rocket);
        }
    }
}

void Level::addPlane1(Sint32 x) {
    Plane1* plane1;
    plane1 = new Plane1();
    plane1->setY(-plane1->getHeight());
    plane1->setX(x);

    Game::getEnemyManager()->add(plane1);
}

void Level::addPlane2(Sint32 x) {
    Plane2* plane2;
    plane2 = new Plane2();
    plane2->setY(-plane2->getHeight());
    plane2->setX(x);

    Game::getEnemyManager()->add(plane2);
}

void Level::addUFO(Sint32 x) {
    UFO* ufo;
    ufo = new UFO();
    ufo->setY(70);
    ufo->setX(x);

    Game::getEnemyManager()->add(ufo);
}

void Level::addRocket(Sint32 x) {
    Rocket* rocket;
    rocket = new Rocket();
    rocket->setY(-rocket->getHeight());
    rocket->setX(x);

    Game::getEnemyManager()->add(rocket);
}

void Level::addMissionText() {
    Game::getSpriteManager()->add(new MissionText(_level));
}
