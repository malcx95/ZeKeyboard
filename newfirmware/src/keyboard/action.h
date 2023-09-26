namespace keyboard
{

enum class ActionType
{
    SINGLE_KEY, STRING, COMBINATION
};

struct Action
{
    ActionType action;

    int code;

    char* string;

    // TODO add combination
};
}
