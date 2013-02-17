#include <abxy/entity/BranchEntity.hpp>

BranchEntity::BranchEntity()
: MessageReceiver("brach")
{
	
}

void BranchEntity::OnLoad(Entity *parent) {
	for (auto &child : children) {
		child->OnLoad(this);
	}
}

void BranchEntity::OnUnload() {
	for (auto &child : children) {
		child->OnUnload();
	}
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
	entity->OnLoad(this);
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
			children.erase(it);
			(*it)->OnUnload();
		}
	}
}

std::list<std::shared_ptr<Entity>> &BranchEntity::GetChildren() {
	return children;
}

const std::list<std::shared_ptr<Entity>> &BranchEntity::GetChildren() const {
	return children;
}
