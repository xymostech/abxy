#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>
#include <map>

namespace Util {

	class Logger {
	public:
		enum Level {
			DEBUG = 0,
			INFO = 1,
			WARNING = 2,
			ERROR = 3,
			CRITICAL = 4,
		};

	private:
		std::ofstream log;
		Level level;
		std::string path;
		bool is_setup;

		Logger();
		void DoSetup(const std::string &prefix);
		void DoLog(Level l, const std::string &message);
		void DoSetLevel(Level set_level);

		static std::map<Level, std::string> LevelNames;

		static Logger &Instance();
	public:
		static std::string Setup(const std::string &prefix);

		static void SetLevel(Level set_level);

		static void Log(Level level, const std::string &message);
		static void Debug(const std::string &message);
		static void Info(const std::string &message);
		static void Warning(const std::string &message);
		static void Error(const std::string &message);
		static void Critical(const std::string &message);
	};

}

#endif /* LOGGER_HPP */

