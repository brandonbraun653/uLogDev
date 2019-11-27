/********************************************************************************
 *  File Name:
 *    uLogDevelopment.cpp
 *
 *  Description:
 *    Development entry point for uLog
 *
 *  2019 | Brandon Braun | brandonbraun653@gmail.com
 ********************************************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <fmt/format.h>

/* uLog Includes */
#include <uLog/ulog.hpp>
#include <uLog/sinks/sink_cout.hpp>

int main()
{
  std::string s = fmt::format("Hello, {}!\n", "world");
  std::string warnMSG = fmt::format("This is a warning message!\n");
  std::string errorMSG = fmt::format("This is an error message!\n");
  std::cout << s;

  uLog::setGlobalLogLevel( uLog::LogLevelType::LOG_LEVEL_ERROR );

  uLog::SinkType commonSink = std::make_shared<uLog::CoutSink>();
  commonSink->setLogLevel( uLog::LogLevelType::LOG_LEVEL_DEBUG );

  uLog::SinkType warningSink = std::make_shared<uLog::CoutSink>();
  warningSink->setLogLevel( uLog::LogLevelType::LOG_LEVEL_WARN );

  uLog::SinkType errorSink = std::make_shared<uLog::CoutSink>();
  errorSink->setLogLevel( uLog::LogLevelType::LOG_LEVEL_ERROR );

  auto commonSinkHandle = uLog::registerSink( commonSink );
  auto warningSinkHandle = uLog::registerSink( warningSink );
  auto errorSinkHandle = uLog::registerSink( errorSink );

  uLog::enableSink( nullptr );

  
  uLog::debug( s.data(), s.size() );
  uLog::warn( warnMSG.data(), warnMSG.size() );
  uLog::error( errorMSG.data(), errorMSG.size());

  return 0;
}