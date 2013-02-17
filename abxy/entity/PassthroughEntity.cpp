#include <abxy/entity/PassthroughEntity.hpp>

PassthroughEntity::PassthroughEntity(Entity &child)
: MessageReceiver("passthrough")
, child(child)
{
	
}

void PassthroughEntity::OnLoad(Entity *parent) {
	child.OnLoad(parent);
}

void PassthroughEntity::OnUnload() {
	child.OnUnload();
}

void PassthroughEntity::Draw(Matrix4 model_matrix) const {
	child.Draw(model_matrix);
}

void PassthroughEntity::Update() {
	child.Update();
}
