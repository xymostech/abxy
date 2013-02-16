#include "Logger.hpp"

#include <chrono>
#include <iomanip>

#include <abxy/util/Path.hpp>

using std::chrono::system_clock;

namespace Util {

	std::map<Logger::Level, std::string> Logger::LevelNames{
		{Logger::DEBUG,    "DEBUG"},
		{Logger::INFO,     "INFO"},
		{Logger::WARNING,  "WARNING"},
		{Logger::ERROR,    "ERROR"},
		{Logger::CRITICAL, "CRITICAL"},
	};

	Logger::Logger()
	: level(DEBUG)
	, is_setup(false)
	{ }

	void Logger::DoSetup(const std::string &prefix) {
		if (!is_setup) {
			path = Util::OpenTempFile(prefix, log);
			is_setup = true;
		}
	}

	void Logger::DoLog(Level l, const std::string &message) {
		if (l >= level) {
			auto t = system_clock::now();
			std::time_t now = system_clock::to_time_t(t);

			log
				<< std::put_time(std::localtime(&now), "%F %T")
				<< " - "
				<< LevelNames[level]
				<< " - "
				<< message
				<< std::endl;
		}
	}

	void Logger::DoSetLevel(Level set_level) {
		level = set_level;
	}

	Logger &Logger::Instance() {
		static Logger logger;
		return logger;
	}

	std::string Logger::Setup(const std::string &prefix) {
		Instance().DoSetup(prefix);
		return Instance().path;
	}

	void Logger::SetLevel(Level set_level) {
		Instance().DoSetLevel(set_level);
	}

	void Logger::Log(Level level, const std::string &message) {
		Instance().DoLog(level, message);
	}

	void Logger::Debug(const std::string &message) {
		Log(DEBUG, message);
	}

	void Logger::Info(const std::string &message) {
		Log(INFO, message);
	}

	void Logger::Warning(const std::string &message) {
		Log(WARNING, message);
	}

	void Logger::Error(const std::string &message) {
		Log(ERROR, message);
	}

	void Logger::Critical(const std::string &message) {
		Log(CRITICAL, message);
	}

}
