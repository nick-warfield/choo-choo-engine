#include "Log.hpp"

std::shared_ptr<spdlog::logger> Log::m_eh =
		spdlog::basic_logger_mt("eh", "logs/eh.txt");

std::shared_ptr<spdlog::logger> Log::m_graphics =
		spdlog::basic_logger_mt("graphics", "logs/graphics.txt");


std::shared_ptr<spdlog::logger> Log::eh() { return m_eh; }
std::shared_ptr<spdlog::logger> Log::graphics() { return m_graphics; }
