#pragma once
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <tuple>

class EventHandler {
public:
	EventHandler();
	virtual ~EventHandler(); //виртуал нужен, чтобы при наследовании этот деструктор вызывался в детях, это надо, чтобы очищалось map

	template<typename ...Args> //указываем, что будет переменное количество параметров разных типов данных
	void on(const std::string& event_type, std::function<void(Args...)> callback)
	{
		auto wrapped = [callback](void* argsPtr) { //создаем обертку, которая будет вызывать функцию, обертка нужна, так как std::map не может напрямую хранить без ебки std::vector<std::function<void(Args...)>>
			auto* tuplePtr = static_cast<std::tuple<Args...>*>(argsPtr); //у нас параметр указатель на void, но мы аргументом всегда кидаем кортеж, так что преобразуем назад в кортеж при помощи static_cast
			std::apply(callback, *tuplePtr); //при помощи std::apply вызываем функцию с tuple
		};

		callbacks[event_type].push_back(wrapped); //создает вектор автоматически, даже если его не было
	}
protected:
	template<typename... Args>
	void emit(const std::string& event_type, Args... args)
	{
		if (callbacks.contains(event_type)) {
			for (auto& callback : callbacks[event_type]) {
				auto argsTuple = std::make_tuple(args...); //из переменных аргументов мы создаем кортеж
				callback(&argsTuple); //вызываем функцию, передав кортеж как параметр (без std::apply ибо там нет сложных параметров, просто параметр, принимающий адрес чего угодно)
			}
		}
	}

	std::map<std::string, std::vector<std::function<void(void*)>>> callbacks; //храним вектор функций, который принимают параметром указатель на войд (указатель на все в С++, в нашем случае на кортеж параметров)
};
