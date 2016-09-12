#include<hugworks/scene.h>

Scene::Scene()
{

}
Scene::~Scene()
{
  entities.clear();
}
void Scene::addEntity(Entity* entity)
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
