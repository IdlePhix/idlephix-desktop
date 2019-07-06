#include "../include/Logger.h"
#include <sstream>
#include <iostream>
#include <iomanip>

IdlePhix::Logger::Logger(bool showTimestamps) :
	m_showTimestamps(showTimestamps)
{
}

void IdlePhix::Logger::log(std::string level, std::string message)
{
	std::ostringstream oss;

	std::time_t m_timeT = std::time(nullptr);
	errno_t m_localtime = localtime_s(&m_timeInfo, &m_timeT);

	if (m_showTimestamps == true)
		oss << std::put_time(&m_timeInfo, "[%d-%m-%Y %H:%M:%S]");

	oss << "[" << level << "]: " << message << std::endl;
	std::cout << oss.str();
}
