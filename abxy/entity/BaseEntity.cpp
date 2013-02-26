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
		try {
			child->OnUnload();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	if (new_child) {
		try {
			new_child->OnLoad(
				LoadData(&loader, &program_loader, &projection)
			);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}

	child = new_child;
}
