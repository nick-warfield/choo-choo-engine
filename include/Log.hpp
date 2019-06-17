#ifndef LOG_HPP_INCLUDED
#define LOG_HPP_INCLUDED

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

class Log
{
	public:
		static std::shared_ptr<spdlog::logger> eh(void);
		static std::shared_ptr<spdlog::logger> graphics(void);

	private:
		static std::shared_ptr<spdlog::logger> m_eh;
		static std::shared_ptr<spdlog::logger> m_graphics;
};

#endif
