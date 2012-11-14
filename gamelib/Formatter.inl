#ifndef FORMATTER_INL
#define FORMATTER_INL

#include <gamelib/Formatter.hpp>

#include <sstream>

template <typename T>
class StaticFormatter : public IFormat {
	std::string store;
public:
	StaticFormatter(const T& data) {
		std::ostringstream s;
		s << data;
		store = s.str();
	}

	std::string Format() const override {
		return store;
	}
};

template <typename T>
class DynamicFormatter : public IFormat {
	const T& data;
public:
	DynamicFormatter(const T& data)
	: data(data) {

	}

	std::string Format() const override {
		std::ostringstream s;
		s << data;
		return s.str();
	}
};

template <typename T>
Formatter &Formatter::operator<<(const T& data) {
	formatters.push_back(
		StoreStatic(data)
	);
	return *this;
}

Formatter &Formatter::operator<<(std::shared_ptr<IFormat> insert) {
	formatters.push_back(insert);
	return *this;
}

Formatter &Formatter::operator<<(const Formatter &formatter) {
	for (auto f : formatter.formatters) {
		*this << f;
	}
	return *this;
}

template <typename T>
std::shared_ptr<IFormat> Formatter::Store(const T& data) {
	return std::shared_ptr<IFormat>(
		new DynamicFormatter<T>(data)
	);
}

template <typename T>
std::shared_ptr<IFormat> Formatter::StoreStatic(const T& data) {
	return std::shared_ptr<IFormat>(
		new StaticFormatter<T>(data)
	);
}

void Formatter::Clear() {
	formatters.clear();
}

std::string Formatter::Format() const {
	std::string store;

	for (auto f : formatters) {
		store += f->Format();
	}

	return store;
}

#endif /* FORMATTER_INL */

