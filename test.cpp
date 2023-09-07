#include <iostream>
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/spdlog.h"

int main()
{
    // 设置日志级别为调试
    spdlog::set_level(spdlog::level::debug);

    // 设置日志消息的格式模式
    spdlog::set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] [%n] [%l]%$ %v");

    // 创建一个输出到标准输出的多线程日志记录器
    auto console_logger = spdlog::stdout_color_mt("console_logger");

    // 创建一个写入到文件的日志记录器，最大文件大小为5MB，最多保留3个文件
    auto file_logger = spdlog::rotating_logger_mt("file_logger", "logs.log", 1024 * 1024 * 5, 3);

    // 设置默认的日志记录器
    spdlog::set_default_logger(console_logger);

    // 使用默认的日志记录器记录不同级别的日志消息
    spdlog::info("This is an info message");
    spdlog::debug("This is a debug message");
    spdlog::warn("This is a warning message");
    spdlog::error("This is an error message");

    // 使用特定的日志记录器记录日志消息
    console_logger->info("This is a message using the console_logger");
    file_logger->info("This is a message using the file_logger");

    return 0;
}