//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_RESOURCEMANAGER_H
#define DUNGEONC_RESOURCEMANAGER_H

#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

template<typename Resource, typename Identifier>
class ResourceManager {
public:
    void load(Identifier id, const std::string& filename);
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;

private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
    std::string mDirectory = "resources/";
};

template<typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string &filename) {
    std::unique_ptr<Resource> resource = std::make_unique<Resource>();

    if (!resource->loadFromFile(filename)) {
        throw std::runtime_error("ResourceManager::load - Failed to load " + filename);
    }

    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    if (!inserted.second) {
        throw std::runtime_error("ResourceManager::load - Failed to insert " + filename);
    }
}

template<typename Resource, typename Identifier>
Resource& ResourceManager<Resource, Identifier>::get(Identifier id) {
    auto found = mResourceMap.find(id);
    if (found == mResourceMap.end()) {
        throw std::runtime_error("ResourceManager::get - Resource not found");
    }
    return *found->second;
}

template<typename Resource, typename Identifier>
const Resource& ResourceManager<Resource, Identifier>::get(Identifier id) const {
    auto found = mResourceMap.find(id);
    if (found == mResourceMap.end()) {
        throw std::runtime_error("ResourceManager::get - Resource not found");
    }
    return *found->second;
}

#endif //DUNGEONC_RESOURCEMANAGER_H
