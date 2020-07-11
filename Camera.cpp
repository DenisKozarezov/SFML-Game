#include "Camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{
	delete this->faded;
	delete this->moving;
	delete this->target;

	delete this->speed;
}