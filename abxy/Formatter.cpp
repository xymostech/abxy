#include <abxy/Formatter.hpp>

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
