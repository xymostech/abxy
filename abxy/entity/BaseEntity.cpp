#include <abxy/entity/BaseEntity.hpp>

BaseEntity::BaseEntity()
: child(nullptr)
{
	
}

void BaseEntity::Draw() const {
	if (child) {
		child->Draw();
	}
}

void BaseEntity::Update() {
	if (child) {
		child->Draw();
	}
}

void BaseEntity::SetChild(Entity *new_child) {
	if (child) {
		child->OnUnload();
	}

	if (new_child) {
		new_child->OnLoad(
			LoadData(&loader, &program_loader, &projection)
		);
	}

	child = new_child;
}
