#ifndef WORLDENTITY_HPP
#define WORLDENTITY_HPP

#include <deque>
#include <memory>

#include <abxy/entity/BranchEntity.hpp>

class WorldEntity : public BranchEntity {
	std::deque<std::shared_ptr<Entity>> to_add;
	std::deque<Entity*> to_remove;

	bool is_updating;
public:
	WorldEntity();
	virtual ~WorldEntity();

	template <class T, class... Args>
	void Add(Args&&... args) {
		AddChild(std::dynamic_pointer_cast<Entity>(
			std::make_shared<T>(std::forward<Args>(args)...)
		));
	}

	virtual void Update() override;

	virtual void AddChild(const std::shared_ptr<Entity> &entity) override;
	virtual void RemoveChild(Entity *entity) override;
};

#endif /* WORLDENTITY_HPP */

