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

	void invoke();

	const bool& IsNull() const;

	Delegate& operator+=(Function<> function);
	template<typename T, typename... Args>
	Delegate& operator+=(void(T::*function)(const Args&...));
	Delegate& operator=(const Delegate& delegate);
	bool operator==(const Delegate& delegate);
	bool operator!=(const Delegate& delegate);
};