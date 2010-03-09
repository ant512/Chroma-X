#include "bulletbase.h"

BulletBase::BulletBase() {
    _damage = 1;
}

BulletBase::~BulletBase() {
}

Uint32 BulletBase::getDamage() {
    return _damage;
}
