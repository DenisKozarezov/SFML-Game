#include "Camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{
	delete this->faded;
	delete this->isMoving;
	delete this->target;

	delete this->speed;
}