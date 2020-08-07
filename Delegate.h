#pragma once
#include <vector>
#include <functional>

class Delegate
{
private:
	class Function
	{
	public:
		template<typename... Args>
		using Func = void(*)(const Args...);
		using Lyambda = std::function<void()>;
		Function(Func<> function) : _function(function) {}
		Function(Lyambda lyambda) : _lyambda(lyambda) {}

		void invoke();
	private:
		Func<> _function = 0;
		Lyambda _lyambda = 0;
	};

	std::vector<Function> functions;
public:
	Delegate() = default;

	void invoke();

	const bool& IsNull() const;

	Delegate& operator+=(Function::Lyambda lyambda);
	template<typename T, typename... Args>
	Delegate& operator+=(void(T::*function)(const Args...));
	Delegate& operator+=(const Delegate& delegate);

	template<typename T, typename... Args>
	Delegate& operator-=(void(T::* function)(const Args...));

	Delegate& operator=(const Delegate& delegate);
};	