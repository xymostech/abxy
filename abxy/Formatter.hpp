#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include <vector>
#include <memory>

class IFormat {
public:
	virtual std::string Format() const = 0;
};

class Formatter : public IFormat {
	std::vector<std::shared_ptr<IFormat>> formatters;
public:
	template <typename T>
	Formatter &operator<<(const T& data);
	Formatter &operator<<(std::shared_ptr<IFormat> insert);
	Formatter &operator<<(const Formatter &formatter);

	template <typename T>
	static std::shared_ptr<IFormat> Store(const T& data);

	template <typename T>
	static std::shared_ptr<IFormat> StoreStatic(const T& data);

	void Clear();

	virtual std::string Format() const override;
};

#include <abxy/Formatter.inl>

#endif /* FORMATTER_HPP */

