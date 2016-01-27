#pragma once

#include "../Graphics/Drawable.h"
#include "../Graphics/Transformable.h"
#include "../Physics/Body.h"
#include <memory>
#include <vector>

class SceneNode : public Drawable, public Transformable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

	SceneNode();

	void addChild(Ptr);

	void setView(Drawable::Ptr view);
	template <typename T, typename... Args>
	void setView(Args...);

	void enablePhysics();
	inline Body* getBody() const { return mBody.get(); };

	void onUpdate(float secs);
	void onDraw(const math::Matrix3 &world) const;

	virtual void update(float secs);
	virtual void draw(const math::Matrix3 &matrix) const override;

protected:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;

	Drawable::Ptr mView;
	Body::Ptr mBody;
};

template <typename T, typename... Args>
void SceneNode::setView(Args... args)
{
	mView = Drawable::Ptr(new T(args...));
}