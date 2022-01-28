#include "game.h"

int main(void)
{
    game game = init_game();

    run_game(&game);

    deinit_game(&game);
    return 0;
}