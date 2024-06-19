#pragma once
#include <string>

namespace DrawingInstruction
{
    class StateCommand {
    public:
        StateCommand() = default;
        virtual ~StateCommand() = default;
        virtual void execute() = 0;
        virtual void parse(const std::string& input) = 0;
    };
}