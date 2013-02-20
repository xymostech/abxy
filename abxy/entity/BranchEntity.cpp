#include <abxy/entity/BranchEntity.hpp>

BranchEntity::BranchEntity()
: MessageReceiver("brach")
, is_loaded(false)
, store_data(nullptr, nullptr, nullptr)
{
	
}

void BranchEntity::OnLoad(LoadData &data) {
	for (auto &child : children) {
		child->OnLoad(data);
	}

	is_loaded = true;
	store_data = data;
}

void BranchEntity::OnUnload() {
	for (auto &child : children) {
		child->OnUnload();
	}

	is_loaded = false;
}

void BranchEntity::Draw(Matrix4 model_matrix) const {
	for (auto &child : children) {
		child->Draw(model_matrix);
	}
}

void BranchEntity::Update() {
	for (auto &child : children) {
		child->Update();
	}
}

void BranchEntity::AddChild(const std::shared_ptr<Entity> &entity) {
	children.push_back(entity);
	if (is_loaded) {
		entity->OnLoad(store_data);
	}
	MessageReceiver::AddChild(entity.get());
}

void BranchEntity::RemoveChild(const std::shared_ptr<Entity> &entity) {
	RemoveChild(entity.get());
}

void BranchEntity::RemoveChild(Entity *entity) {
	/*
	 * Iterate through each child, and compare the given pointer to the raw
	 * pointer of each child
	 */
	auto it = children.begin(), end = children.end();
	for (; it != end; ++it) {
		if (it->get() == entity) {
			// Only do this stuff if the entity is found
			(*it)->OnUnload();
			MessageReceiver::RemoveChild((*it).get());
			children.erase(it);
		}
	}
}

std::list<std::shared_ptr<Entity>> &BranchEntity::GetChildren() {
	return children;
}

const std::list<std::shared_ptr<Entity>> &BranchEntity::GetChildren() const {
	return children;
}
