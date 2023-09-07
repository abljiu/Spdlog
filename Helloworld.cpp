#include <iostream>
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
void example()
{
    try
    {
        auto logger1 = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
        logger1->info("This is logger1");
        auto logger2 = spdlog::stdout_color_mt("console");
        spdlog::info("Welcome to spdlog!");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
}

int main()
{
    example();
    return 0;
}