//
// Created by stingliang on 2021/9/29 14:30.
//
#ifndef DEV_UTILITY_LOGGER_H
#define DEV_UTILITY_LOGGER_H

#include <core/common.h>

enum Severity {
    TRACE = 0,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

#ifdef USE_BOOST
// boost include
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;

#define LOGGER(MODULE, SEVERITY) BOOST_LOG_TRIVIAL(SEVERITY) << "[" << (MODULE) << "] "

class log_initializer {
public:
    struct log_config {
        bool console_print = true;
        logging::trivial::severity_level severity = boost::log::trivial::info;
        std::string log_path;
        size_t logfile_maxsize = 128 *1024 *1024;
    };
    static void init(const log_config&);
    static bool isInit() { return init_flag; }
private:
    static bool init_flag;
};

#else

#endif

#endif //DEV_UTILITY_LOGGER_H
