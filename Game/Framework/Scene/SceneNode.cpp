#include "SceneNode.h"

using namespace math;


SceneNode::SceneNode()
	: Drawable()
	, mChildren()
	, mParent(nullptr)
{
}


void SceneNode::addChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}


void SceneNode::setView(Drawable::Ptr view)
{
	mView = std::move(view);
}


void SceneNode::enablePhysics()
{
	mBody = Body::Ptr(new Body(this));
}


void SceneNode::onUpdate(float secs)
{
	update(secs);

	if (mBody != nullptr)
		mBody->update(secs);
	
	for (auto &child : mChildren)
		child->onUpdate(secs);
}


void SceneNode::onDraw(const Matrix3 &world) const
{
	Matrix3 matrix = world;
	matrix *= calculateMatrix();

	draw(matrix);

	if (mView != nullptr)
		mView->draw(matrix);

	for (auto &child : mChildren)
		child->onDraw(matrix);
}


void SceneNode::update(float secs) {}
void SceneNode::draw(const Matrix3 &matrix) const {}