#pragma once


namespace keyboard
{

enum class ActionType
{
    SINGLE_KEY, STRING, COMBINATION
};

struct Action
{
    Action(int code);
    Action(char* string);

    ActionType type;

    int code;

    char* string;

    // TODO add combination
};
}
