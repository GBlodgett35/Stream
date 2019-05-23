#include<iostream>
#include<functional>
#include<vector>
#include "BaseStream.cpp"

template<typename T>
class Stream : public BaseStream<T> {
public:
	Stream(std::vector<T> const&);
	Stream(const Stream<T>& );
	~Stream();
	template<typename Function> auto map(Function) const;
	template<typename Function> auto mapToInt(std::function<int(const T&)>) const;
	auto forEach(std::function<void(const T&)>) const;
	auto forEach(std::ostream&) const;
	auto filter(std::function<bool(const T&)>) const;
	bool anyMatch(T) const;
	bool allMatch(T) const;
	bool noneMatch(T) const;
	int count() const;
	const T* toArray() const;
	Stream<T> operator = (Stream<T> const&);
private:
	const std::vector<T> elements;
};

template<typename T>
Stream<T>::~Stream() {}

template<typename T>
Stream<T>::Stream(const Stream<T> &other ) {
	this->elements = other.elements;
}

template<typename T>
Stream<T> Stream<T>::operator=(Stream<T> const & obj)
{
	return Stream<T>{obj};
}

template<typename T>
Stream<T>::Stream(std::vector<T> const& e) : elements(e){}

template<typename T>
template<typename Function>
auto Stream<T>::map(Function func) const
{
	T throwAway = elements.at(0);
	using R = decltype(func(throwAway));
	std::vector<R> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		T copy = *i;
		newStream.push_back(func(copy));
	}
	return Stream<R>{newStream};
}

template<typename T>
auto Stream<T>::filter(std::function<bool(const T&)> predicate) const
{
	std::vector<T> newStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (predicate(*i)) {
			newStream.push_back(*i);
		}
	}
	return Stream<T>{newStream};
}


template<typename T>
auto Stream<T>::forEach(std::function<void(const T&)> consumer) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		consumer(*i);
	}
}

template<typename T>
auto Stream<T>::forEach(std::ostream &stream) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		stream << *i << " ";
	}
}

template<typename T>
bool Stream<T>::anyMatch(T element) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (*i == element) {
			return true;
		}
	}
	return false;
}

template<typename T>
bool Stream<T>::allMatch(T element) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (*i != element) {
			return false;
		}
	}
	return true;
}

template<typename T>
bool Stream<T>::noneMatch(T element) const
{
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		if (*i == element) {
			return false;
		}
	}
	return true;
}

template<typename T>
int Stream<T>::count() const {
	return elements.size();
}

template<typename T>
template<typename Function>
auto Stream<T>::mapToInt(std::function<int(const T&)> mapper) const
{
	std::vector<int> intStream;
	for (auto i = elements.begin(); i != elements.end(); ++i) {
		intStream.push_back(mapper(*i));
	}
	return Stream<int>{intStream};
}

template<typename T>
const T * Stream<T>::toArray() const
{
	return &elements[0];
}


