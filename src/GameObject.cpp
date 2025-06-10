#include "GameObject.h"

void GameObject::printUID()
{
    printf(" % s :", name.c_str());
    for (int i = 0; i < 16;i++) {
        printf("%02X", uid[i]);
    }
    printf("\n");

} 
void GameObject::DrawUID()
{
    DrawText(getUID().c_str(), position.x, position.y - 20, 10, WHITE);
}
