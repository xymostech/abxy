#include <abxy/entity/BaseEntity.hpp>

BaseEntity::BaseEntity()
: MessageReceiver("base")
, program_loader(projection)
, child(nullptr)
{
	
}

void BaseEntity::Draw() const {
	if (child) {
		Matrix4 matrix(1.0);
		child->Draw(matrix);
	}
}

void BaseEntity::Update() {
	if (child) {
		child->Update();
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
			LoadData data(&loader, &program_loader, &projection);
			new_child->OnLoad(data);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}

	child = new_child;
}
