#pragma once
#include <vector>
#include <functional>

class Delegate
{
private:
	class Function
	{
	public:
		using Func = void(*)();
		using Lyambda = std::function<void()>;

		Func function = 0;
		Lyambda lyambda = 0;

		Function(Func function) : function(function) {}
		Function(Lyambda lyambda) : lyambda(lyambda) {}

		virtual void invoke();
	};

	template<typename T>
	class Member : public Function
	{
	private:
		using M = void(T::*)();
		T* type;
		M member;
	public:
		Member(T* type, M member) : type(type), member(member) {}

		void invoke() override;
	};

	std::vector<Function> functions;
public:
	Delegate() = default;
	template<typename T>
	Delegate(T* type, void(T::*function)());

	/// <summary>
	/// Invokation of all functions that were added in this delegate. Also includes lyambda-expressions.
	/// </summary>
	void invoke();

	/// <summary>
	/// Clear the list of delegate functions.
	/// </summary>
	void clear();

	Delegate& operator+=(Function::Lyambda lyambda);
	Delegate& operator+=(void(*function)());
	Delegate& operator+=(const Delegate& delegate);

	Delegate& operator-=(void(*function)());
	template<typename T>
	Delegate& operator-=(void(T::*function)());

	Delegate& operator=(const Delegate&) = default;
};