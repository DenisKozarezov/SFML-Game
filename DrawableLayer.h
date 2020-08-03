///////////////////////////////////////////////////////////////////
//				 ������ �� ���������� �����������				 //
// DrawableContainer.h -> DrawableLayer.h -> DrawableContainer.h //
///////////////////////////////////////////////////////////////////
#ifndef _DRAWABLELAYER_H_
#define _DRAWABLELAYER_H_
#include "DrawableObject.h"
#include <vector>

class DrawableLayer final
{
private:
	bool* drawable;
	std::vector<DrawableObject*>* layer;
public:
	DrawableLayer();

	const bool& IsDrawable() const;

	void add(DrawableObject* object);

	/// �������� ������ ����������� �������� �� ���������� ��������.
	/// \param type - ���������������� �������.
	template<typename T>
	void remove_group(const T& type);

	/// �������� ������������ ������� � ����������� ����������� ��� �� 
	/// �������� ���������.
	/// \param object - ����������� ������
	void remove(DrawableObject* object);

	/// ��������, �������� �� ���� ��������� ������.
	/// \param object - ����������� ������
	/// \return bool - ����
	const bool& is_contain(DrawableObject* object) const;

	void update(sf::RenderWindow& window);

	std::vector<DrawableObject*>* get_layer();

	~DrawableLayer();
};
#endif