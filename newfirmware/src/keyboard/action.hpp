namespace keyboard
{

enum class ActionType
{
    SINGLE_KEY, STRING, COMBINATION
};

struct Action
{
    ActionType type;

    int code;

    char* string;

    // TODO add combination
};
}
