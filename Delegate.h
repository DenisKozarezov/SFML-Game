#pragma once
class Delegate
{
private:
	template<typename... Args>
	using Function = void(*)(const Args&...);
	Function<> func;
public:
	Delegate() = default;
	Delegate(Function<> function);
	template<typename T, typename... Args>
	Delegate(void(T::*function)(const Args&... args));

	template<typename... Args>
	void invoke(const Args&... args);

	Delegate& operator+=(Function<> function);
	template<typename T, typename... Args>
	Delegate& operator+=(void(T::*function)(const Args&...));
};