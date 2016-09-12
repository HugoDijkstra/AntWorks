#include <hugworks/layer.h>

Layer::Layer()
{

}
Layer::~Layer()
{

}
void Layer::addEntity(Entity* entity)
{
        std::vector<Entity*>::iterator it = entities.begin();
        while(it != entities.end())
        {
                if((*it)->getId() == entity->getId())
                {
                        return;
                }
                else
                {
                        ++it;
                }

        }
        entities.push_back(entity);
}
