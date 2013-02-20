#include <abxy/entity/PassthroughEntity.hpp>

PassthroughEntity::PassthroughEntity(Entity &child)
: MessageReceiver(&child)
, child(child)
{
	
}

void PassthroughEntity::OnLoad(LoadData &data) {
	child.OnLoad(data);
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
